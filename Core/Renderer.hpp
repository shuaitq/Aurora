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
			Matrix4_T<float> &m = camera_.MakeMatrix();
			directlight *= m;
			screen_.resize(width_ * height_);
			ZBuffer_.resize(width_ * height_);
		}
		void DrawTopTriangle(Vertex &top, Vertex &left, Vertex &right, Texture &texture)
		{
			for(size_t i = top.point().y(); i < left.point().y(); ++ i)
			{
				// left and right must be the same height.
				float t = (left.point().y() - i) / (left.point().y() - top.point().y());
				// point
				float xs = Interpolation(top.point().x(), left.point().x(), t);
				float xe = Interpolation(top.point().x(), right.point().x(), t);
				// normal
				Vector4D_T<float> xns = Interpolation(top.normal() / top.point().z(), left.normal() / left.point().z(), t);
				Vector4D_T<float> xne = Interpolation(top.normal() / top.point().z(), right.normal() / right.point().z(), t);
				// 1 / z
				float onezs = Interpolation(1 / top.point().z(), 1 / left.point().z(), t);
				float oneze = Interpolation(1 / top.point().z(), 1 / right.point().z(), t);
				// uv
				Point2D_T<float> xuvs = Interpolation(top.uv() / top.point().z(), left.uv() / left.point().z(), t);
				Point2D_T<float> xuve = Interpolation(top.uv() / top.point().z(), right.uv() / right.point().z(), t);
				for(size_t j = xs; j < xe; ++ j)
				{
					float tt = (xe - j) / (xe - xs);
					// normal
					Vector4D_T<float> point_normal = Interpolation(xns, xne, tt);
					point_normal /= Interpolation(onezs, oneze, tt);
					// uv
					Point2D_T<float> point_uv = Interpolation(xuvs, xuve, tt);
					point_uv /= Interpolation(onezs, oneze, tt);
					// color = texture.color * (normal * light)
					float PdotD = -Dot(point_normal, directlight);
					if(PdotD < 0)
					{
						PdotD = 0;
					}
					if(PdotD > 1)
					{
						PdotD = 1;
					}
					screen_[i * width_ + j] =  texture.Sample(point_uv.x(), point_uv.y()) * (RGB_T<float>::white * PdotD);
				}
			}
		}
		void DrawBottomTriangle(Vertex &bottom, Vertex &left, Vertex &right, Texture &texture)
		{
			for(size_t i = left.point().y(); i < bottom.point().y(); ++ i)
			{
				// left and right must be the same height.
				float t = (bottom.point().y() - i) / (bottom.point().y() - left.point().y());
				// point
				float xs = Interpolation(left.point().x(), bottom.point().x(), t);
				float xe = Interpolation(right.point().x(), bottom.point().x(), t);
				// normal
				Vector4D_T<float> xns = Interpolation(left.normal() / left.point().z(), bottom.normal() / bottom.point().z(), t);
				Vector4D_T<float> xne = Interpolation(right.normal() / right.point().z(), bottom.normal() / bottom.point().z(), t);
				// 1 / z
				float onezs = Interpolation(1 / left.point().z(), 1 / bottom.point().z(), t);
				float oneze = Interpolation(1 / right.point().z(), 1 / bottom.point().z(), t);
				// uv
				Point2D_T<float> xuvs = Interpolation(left.uv() / left.point().z(), bottom.uv() / bottom.point().z(), t);
				Point2D_T<float> xuve = Interpolation(right.uv() / right.point().z(), bottom.uv() / bottom.point().z(), t);
				for(size_t j = xs; j < xe; ++ j)
				{
					float tt = (xe - j) / (xe - xs);
					// normal
					Vector4D_T<float> point_normal = Interpolation(xns, xne, tt);
					point_normal /= Interpolation(onezs, oneze, tt);
					// uv
					Point2D_T<float> point_uv = Interpolation(xuvs, xuve, tt);
					point_uv /= Interpolation(onezs, oneze, tt);
					float PdotD = -Dot(point_normal, directlight);
					if(PdotD < 0)
					{
						PdotD = 0;
					}
					if(PdotD > 1)
					{
						PdotD = 1;
					}
					// color = texture.color * (normal * light)
					screen_[i * width_ + j] =  texture.Sample(point_uv.x(), point_uv.y()) * (RGB_T<float>::white * PdotD);
				}
			}
		}

		void Render(const std::string &path)
		{
			// make camera matrix
			Matrix4_T<float> &m = camera_.MakeMatrix();
			float x, y, z;
			std::cout << "Please input rotate angle x y z" << std::endl;
			std::cin >> x >> y >> z;
			x = x * M_PI / 180;
			y = y * M_PI / 180;
			z = z * M_PI / 180;
			object_[0].RotateX(x);
			object_[0].RotateY(y);
			object_[0].RotateZ(z);
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
					if(0 < Dot(v[0].point() - Point4D_T<float>(0,0,0), CalcNormal(v[0].point(), v[1].point(), v[2].point())))
					{
						// transform points to screen
						for(size_t i = 0; i < 3; ++ i)
						{
							v[i].point().x() = v[i].point().x() / v[i].point().z();
							v[i].point().y() = v[i].point().y() / v[i].point().z();
							v[i].point().y() *= camera_.aspect();
							v[i].point().x() *= (width_ / 2);
							v[i].point().x() += (width_ / 2);
							v[i].point().y() *= (height_ / 2);
							v[i].point().y() += (height_ / 2);
						}
						// sort
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
						// calc mid vertex
						Point4D_T<float> midpoint(v[0].point().x() + (v[2].point().x() - v[0].point().x()) / (v[2].point().y() - v[0].point().y()) * (v[1].point().y() - v[0].point().y()), v[1].point().y(), 0);
						float t = (v[0].point() - midpoint).Length() / (v[0].point() - v[2].point()).Length();
						Point2D_T<float> miduv(t * v[2].uv() + (1-t) * v[0].uv());
						Vector4D_T<float> midnormal(t * v[2].normal() + (1-t) * v[0].normal());
						// TODO
						if(midpoint.x() - v[0].point().x() == 0 || v[0].point().x() - v[2].point().x() == 0)
						{
							midpoint.z() = 1 / v[0].point().z() + ((midpoint.y() - v[0].point().y()) / (v[2].point().y() - v[0].point().y()) * (1 / v[2].point().z() - 1 / v[0].point().z()));
							midpoint.z() = 1 / midpoint.z();
						}
						else
						{
							midpoint.z() = 1 / v[0].point().z() + ((midpoint.x() - v[0].point().x()) / (v[2].point().x() - v[0].point().x()) * (1 / v[2].point().z() - 1 / v[0].point().z()));
							midpoint.z() = 1 / midpoint.z();
						}
						Vertex midvertex(midpoint, miduv, midnormal);
						// draw triangle
						std::cout << v[0] << std::endl;
						std::cout << v[1] << std::endl;
						std::cout << v[2] << std::endl;
						std::cout << midvertex << std::endl;
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
			PPM::Save(path, width_, height_, screen_);
			// save ppm file
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
