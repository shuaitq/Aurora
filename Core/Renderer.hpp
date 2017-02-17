#ifndef AURORA_RENDERER_HPP_
#define AURORA_RENDERER_HPP_

#include "Camera.hpp"
#include "Color.hpp"
#include "../Utility/SenceFile.hpp"
#include "../Math/Math.hpp"

#include <memory>
#include <vector>
#include <string>
#include <algorithm>

namespace Aurora
{
	Vector4D_T<float> directlight(-0.267261, -0.534522, -0.801784);
	class Renderer
	{
	public:
		void Load(const std::string &path)
		{
			SenceFile::Load(path, width_, height_, camera_, object_);
		}
		void Init()
		{
			screen_.resize(width_ * height_);
			ZBuffer_.resize(width_ * height_);
		}
		void DrawTopTriangle(Point2D_T<float> &top, Vector4D_T<float> &topnormal, Point2D_T<float> &left, Vector4D_T<float> &leftnormal, Point2D_T<float> &right, Vector4D_T<float> &rightnormal)
		{
			float xs = top.x(), xe = top.x();
			float slope_left = (left.x() - top.x()) / (left.y() - top.y()), slope_right = (right.x() - top.x()) / (right.y() - top.y());
			for(size_t i = top.y(); i < left.y(); ++ i)
			{
				for(size_t j = xs; j < xe; ++ j)
				{
					screen_[i * width_ + j] = RGB_T<float>::white * -Dot(topnormal, directlight);
				}
				xs += slope_left;
				xe += slope_right;
			}
		}
		void DrawBottomTriangle(Point2D_T<float> &bottom, Vector4D_T<float> &bottomnormal, Point2D_T<float> &left, Vector4D_T<float> &leftnormal, Point2D_T<float> &right, Vector4D_T<float> &rightnormal)
		{
			float xs = left.x(), xe = right.x();
			float slope_left = (left.x() - bottom.x()) / (left.y() - bottom.y()), slope_right = (right.x() - bottom.x()) / (right.y() - bottom.y());
			for(size_t i = left.y(); i < bottom.y(); ++ i)
			{
				for(size_t j = xs; j < xe; ++ j)
				{
					screen_[i * width_ + j] = RGB_T<float>::white * -Dot(bottomnormal, directlight);
				}
				xs += slope_left;
				xe += slope_right;
			}
		}

		void Render(const std::string &path)
		{
			// make camera matrix
			Matrix4_T<float> &m = camera_.MakeMatrix();
			Object& object = object_[0];
			// transform
			for(auto it = object.vertex().begin(); it != object.vertex().end(); ++ it)
			{
				it->point() *= m;
			}
			for(auto it = object.triangle().begin(); it != object.triangle().end(); ++ it)
			{
				Point4D_T<float> &p0 = object.vertex()[(*it)[0]].point();
				Point4D_T<float> &p1 = object.vertex()[(*it)[1]].point();
				Point4D_T<float> &p2 = object.vertex()[(*it)[2]].point();
				Vector4D_T<float> basenormal = object.vertex()[(*it)[0]].normal();
				if(0 < Dot(Vector4D_T<float>(0, 0, 1) , CalcNormal(p0, p1, p2)))
				{
					std::vector<Point2D_T<float>> sp;
					sp.push_back(Point2D_T<float>(p0.x() / p0.z(), p0.y() / p0.z()));
					sp.push_back(Point2D_T<float>(p1.x() / p1.z(), p1.y() / p1.z()));
					sp.push_back(Point2D_T<float>(p2.x() / p2.z(), p2.y() / p2.z()));
					std::sort(sp.begin(), sp.end());
					for(size_t i = 0; i < 3; ++ i)
					{
						sp[i].x() /= camera_.aspect();
						sp[i].x() *= (width_ / 2);
						sp[i].x() += (width_ / 2);
						sp[i].y() *= (height_ / 2);
						sp[i].y() += (height_ / 2);
						std::cout << sp[i];
					}
					Point2D_T<float> midpoint(sp[0].x() + (sp[2].x() - sp[0].x()) / (sp[2].y() - sp[0].y()) * (sp[1].y() - sp[0].y()), sp[1].y());
					std::cout << "mid point " << midpoint << std::endl;
					if(midpoint.x() < sp[1].x())
					{
						DrawTopTriangle(sp[0], basenormal, midpoint, basenormal, sp[1], basenormal);
						DrawBottomTriangle(sp[2], basenormal, midpoint, basenormal, sp[1], basenormal);
					}
					else
					{
						DrawTopTriangle(sp[0], basenormal, sp[1], basenormal, midpoint, basenormal);
						DrawBottomTriangle(sp[2], basenormal, sp[1], basenormal, midpoint, basenormal);
					}
				}
			}
			// save ppm file
			PPM::Save(path, width_, height_, screen_);
		}

		Camera& camera()
		{
			return camera_;
		}
		const Camera& camera() const
		{
			return camera_;
		}
		std::vector<Object>& object()
		{
			return object_;
		}
		const std::vector<Object>& object() const
		{
			return object_;
		}
		size_t& width()
		{
			return width_;
		}
		const size_t& width() const
		{
			return width_;
		}
		size_t& height()
		{
			return height_;
		}
		const size_t& height() const
		{
			return height_;
		}
		
		friend std::ostream& operator << (std::ostream &out, const Renderer &r)
		{
			out << "# Renderer" << std::endl;
			out << r.camera();
			for(auto it = r.object().begin(); it != r.object().end(); ++ it)
			{
				out << *it;
			}
			out << "# width height" << std::endl;
			out << r.width() << ' ' << r.height() << std::endl;
			return out;
		}
	private:
		Camera camera_;
		std::vector<RGB_T<float>> screen_;
		std::vector<Object> object_;
		std::vector<float> ZBuffer_;
		size_t width_;
		size_t height_;
	};
}

#endif //AURORA_RENDERER_HPP_
