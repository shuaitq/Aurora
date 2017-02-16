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
	class Renderer
	{
	public:
		void Load(const std::string &path)
		{
			SenceFile::Load(path, width_, height_, camera_, object_);
		}
		
		void DrawTriangle(const Point2D_T<float> &p1, const Point2D_T<float> &p2, const Point2D_T<float> &p3)
		{
		}

		void Render(const std::string &path)
		{
			// init
			screen_.resize(width_ * height_);
			ZBuffer_.resize(width_ * height_);
			// make camera matrix
			Matrix4_T<float> &m = camera_.MakeMatrix();
			std::cout << m << std::endl;
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
				if(0 > Dot(camera_.front() , CalcNormal(p0, p1, p2)))
				{
					std::vector<Point2D_T<float>> screenpoint;
					screenpoint.push_back(Point2D_T<float>(p0.x() / p0.z(), p0.y() / p0.z()));
					screenpoint.push_back(Point2D_T<float>(p1.x() / p1.z(), p1.y() / p1.z()));
					screenpoint.push_back(Point2D_T<float>(p2.x() / p2.z(), p2.y() / p2.z()));
					std::sort(screenpoint.begin(), screenpoint.end());
					Point2D_T<float> midpoint(screenpoint[0].x() + , screenpoint[1].y());
					for(size_t i = 0; i < 3; ++ i)
					{
						std::cout << screenpoint[i];
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
