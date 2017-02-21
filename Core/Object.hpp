#ifndef AURORA_OBJECT_HPP_
#define AURORA_OBJECT_HPP_

#include "Texture.hpp"
#include "Triangle.hpp"
#include "../Utility/ObjectFile.hpp"

#include <vector>
#include <string>
#include <iostream>

namespace Aurora
{
	class Object
	{
	public:
		Object() = default;
		Object(Point4D_T<float> position, Vector4D_T<float> up, Vector4D_T<float> front, Vector4D_T<float> right):position_(position), up_(up), front_(front), right_(right){}
		Object& operator = (const Object &object)
		{
			position_ = object.position_;
			up_ = object.up_;
			front_ = object.front_;
			right_ = object.right_;
			triangle_ = object.triangle_;
			vertex_ = object.vertex_;
			texture_ = object.texture_;
			return *this;
		}
		void Load(const std::string &path)
		{
			ObjectFile::Load(path, vertex_, triangle_, texture_);
		}
		void RotateX(const float angle)
		{
			Matrix4_T<float> m(1, 0, 0, 0,
					0, cos(angle), sin(angle), 0,
					0, -sin(angle), cos(angle), 0,
					0, 0, 0, 1);
			for(auto &vertex : vertex_)
			{
				vertex.point() *= m;
				vertex.normal() *= m;
			}
		}
		void RotateY(const float angle)
		{
			Matrix4_T<float> m(cos(angle), 0, -sin(angle), 0,
					0, 1, 0, 0,
					sin(angle), 0, cos(angle), 0,
					0, 0, 0, 1);
			for(auto &vertex : vertex_)
			{
				vertex.point() *= m;
				vertex.normal() *= m;
			}
		}
		void RotateZ(const float angle)
		{
			Matrix4_T<float> m(cos(angle), sin(angle), 0, 0,
					-sin(angle), cos(angle), 0, 0,
					0, 0, 1, 0,
					0, 0, 0, 1);
			for(auto &vertex : vertex_)
			{
				vertex.point() *= m;
				vertex.normal() *= m;
			}
		}

		std::vector<Triangle>& triangle()
		{
			return triangle_;
		}
		const std::vector<Triangle>& triangle() const
		{
			return triangle_;
		}
		std::vector<Vertex>& vertex()
		{
			return vertex_;
		}
		const std::vector<Vertex>& vertex() const
		{
			return vertex_;
		}
		Texture& texture()
		{
			return texture_;
		}
		const Texture& texture() const
		{
			return texture_;
		}
		Point4D_T<float>& position()
		{
			return position_;
		}
		const Point4D_T<float>& position() const
		{
			return position_;
		}
		Vector4D_T<float>& up()
		{
			return up_;
		}
		const Vector4D_T<float>& up() const
		{
			return up_;
		}
		Vector4D_T<float>& front()
		{
			return front_;
		}
		const Vector4D_T<float>& front() const
		{
			return front_;
		}
		Vector4D_T<float>& right()
		{
			return right_;
		}
		const Vector4D_T<float>& right() const
		{
			return right_;
		}

		friend std::ostream& operator << (std::ostream &out, const Object &object)
		{
			out << "# Object" << std::endl;
			out << "# position" << std::endl;
			out << object.position();
			out << "# up" << std::endl;
			out << object.up();
			out << "# front" << std::endl;
			out << object.front();
			out << "# right" << std::endl;
			out << object.right();
			out << "# triangle" << std::endl;
			for(auto it = object.triangle().begin(); it != object.triangle().end(); ++ it)
			{
				out << *it;
			}
			out << "# vertex" << std::endl;
			for(auto it = object.vertex().begin(); it != object.vertex().end(); ++ it)
			{
				out << *it;
			}
			return out;
		}
		friend std::istream& operator >> (std::istream &in, Object &object)
		{
			in >> object.position() >> object.up() >> object.front() >> object.right();
			return in;
		}
	private:
		Point4D_T<float> position_;
		Vector4D_T<float> up_;
		Vector4D_T<float> front_;
		Vector4D_T<float> right_;
		std::vector<Triangle> triangle_;
		std::vector<Vertex> vertex_;
		Texture texture_;
	};
}

#endif //AURORA_OBJECT_HPP_
