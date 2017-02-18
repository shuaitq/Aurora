#ifndef AURORA_RENDERER_HPP_
#define AURORA_RENDERER_HPP_

#include "Camera.hpp"
#include "Color.hpp"
#include "../Utility/SenceFile.hpp"
#include "../Math/Math.hpp"
#include "Light.hpp"

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
		void DrawTopTriangle(Vertex &top, Vertex &left, Vertex &right, Texture &texture)
		{
			// left and right must be the same height.
			float dis = top.point().y() - left.point().y();
			// point
			float xs = top.point().x(), xe = top.point().x();
			float slope_left = (top.point().x() - left.point().x()) / dis, slope_right = (top.point().x() - right.point().x()) / dis;
			// normal
			Vector4D_T<float> xns = top.normal(), xne = top.normal();
			Vector4D_T<float> slope_left_normal = (top.normal() - left.normal()) / dis, slope_right_normal = (top.normal() - right.normal()) / dis;
			// uv
			Point2D_T<float> xuvs = top.uv(), xuve = top.uv();
			Vector2D_T<float> slope_left_uv = (top.uv() - left.uv()) / dis, slope_right_uv = (top.uv() - right.uv()) / dis;
			for(size_t i = top.point().y(); i < left.point().y(); ++ i)
			{
				float length = xe - xs;
				std::cout << length << "length" << right.point().x() << std::endl;
				std::cout << xs << "xs" << slope_left << std::endl;
				std::cout << xe << "xe" << slope_right << std::endl;
				for(size_t j = xs; j < xe; ++ j)
				{
					// normal
					Vector4D_T<float> point_normal = ((xe - 1 - j) / length * xns) + ((j - xs) / length * xne);
					// uv
					Point2D_T<float> point_uv = ((xe - 1 - j) / length * xuvs) + ((j - xs) / length * xuve);
					// color = texture.color * (normal * light)
					// std::cout << point_normal;
					screen_[i * width_ + j] =  texture.Sample(point_uv.x(), point_uv.y()) * -Dot(point_normal, directlight);
				}
				// point
				xs += slope_left;
				xe += slope_right;
				// normal
				xns += slope_left_normal;
				xne += slope_right_normal;
				// uv
				xuvs += slope_left_uv;
				xuve += slope_right_uv;
			}
		}
		void DrawBottomTriangle(Vertex &bottom, Vertex &left, Vertex &right, Texture &texture)
		{
			// left and right must be the same height.
			float dis = left.point().y() - bottom.point().y();
			// point
			float xs = left.point().x(), xe = right.point().x();
			float slope_left = (left.point().x() - bottom.point().x()) / dis, slope_right = (right.point().x() - bottom.point().x()) / dis;
			// normal
			Vector4D_T<float> xns = left.normal(), xne = right.normal();
			Vector4D_T<float> slope_left_normal = (left.normal() - bottom.normal()) / dis, slope_right_normal = (right.normal() - bottom.normal()) / dis;
			// uv
			Point2D_T<float> xuvs = left.uv(), xuve = right.uv();
			Vector2D_T<float> slope_left_uv = (left.uv() - bottom.uv()) / dis, slope_right_uv = (right.uv() - bottom.uv()) / dis;
			for(size_t i = left.point().y(); i < bottom.point().y(); ++ i)
			{
				float length = xe - xs;
				for(size_t j = xs; j < xe; ++ j)
				{
					// normal
					Vector4D_T<float> point_normal = ((xe - 1 - j) / length * xns) + ((j - xs) / length * xne);
					// uv
					Point2D_T<float> point_uv = ((xe - 1 - j) / length * xuvs) + ((j - xs) / length * xuve);
					// color = texture.color * (normal * light)
					screen_[i * width_ + j] =  texture.Sample(point_uv.x(), point_uv.y()) * -Dot(point_normal, directlight);
				}
				// point
				xs += slope_left;
				xe += slope_right;
				// normal
				xns += slope_left_normal;
				xne += slope_right_normal;
				// uv
				xuvs += slope_left_uv;
				xuve += slope_right_uv;
			}
		}

		void Render(const std::string &path)
		{
			// make camera matrix
			Matrix4_T<float> &m = camera_.MakeMatrix();
			std::vector<Object> TempObject = object_;
			for(auto &object : TempObject)
			{
				// transform
				for(auto &vertex : object.vertex())
				{
					vertex.point() *= m;
					vertex.normal() *= m;
				}
				for(auto &triangle : object.triangle())
				{
					Vertex v[3] = {object.vertex()[triangle[0]],object.vertex()[triangle[1]],object.vertex()[triangle[2]]};
					if(0 < Dot(Vector4D_T<float>(0, 0, 1), CalcNormal(v[0].point(), v[1].point(), v[2].point())))
					{
						for(size_t i = 0; i < 3; ++ i)
						{
							v[i].point().x() = v[i].point().x() / v[i].point().z();
							v[i].point().y() = v[i].point().y() / v[i].point().z();
							v[i].point().x() /= camera_.aspect();
							v[i].point().x() *= (width_ / 2);
							v[i].point().x() += (width_ / 2);
							v[i].point().y() *= (height_ / 2);
							v[i].point().y() += (height_ / 2);
						}
						if(v[0].point().y() > v[1].point().y())
						{
							std::swap(v[0], v[1]);
						}
						if(v[1].point().y() > v[2].point().y())
						{
							std::swap(v[1], v[2]);
						}
						if(v[0].point().y() > v[1].point().y())
						{
							std::swap(v[0], v[1]);
						}
						std::cout << v[0] << std::endl;
						std::cout << v[1] << std::endl;
						std::cout << v[2] << std::endl;
						std::cout << "Vertex" << std::endl;
						Point4D_T<float> midpoint(v[0].point().x() + (v[2].point().x() - v[0].point().x()) / (v[2].point().y() - v[0].point().y()) * (v[1].point().y() - v[0].point().y()), v[1].point().y(), 0);
						std::cout << "midpoint " << midpoint << std::endl;
						float t = (v[0].point() - midpoint).Length() / (v[0].point() - v[2].point()).Length();
						Point2D_T<float> miduv(t * v[2].uv() + (1-t) * v[0].uv());
						Vector4D_T<float> midnormal(t * v[2].normal() + (1-t) * v[0].normal());
						Vertex midvertex(midpoint, miduv, midnormal);
						if(midvertex.point().x() < v[1].point().x())
						{
							DrawTopTriangle(v[0], midvertex, v[1], object.texture());
							DrawBottomTriangle(v[2], midvertex, v[1], object.texture());
						}
						else
						{
							DrawTopTriangle(v[0], v[1], midvertex, object.texture());
							DrawBottomTriangle(v[2], v[1], midvertex, object.texture());
						}
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
		std::vector<Object> object_;
		std::vector<Light*> light_;
		std::vector<float> ZBuffer_;
		std::vector<RGB_T<float>> screen_;
		size_t width_;
		size_t height_;
	};
}

#endif //AURORA_RENDERER_HPP_
