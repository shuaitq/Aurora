#ifndef AURORA_VERTEX_HPP_
#define AURORA_VERTEX_HPP_

#include "../Math/Math.hpp"

#include <vector>
#include <iostream>

namespace Aurora
{
	class Vertex
	{
	public:
		Vertex():point_(0), uv_(0), normal_(0){}
		Vertex(const Point4D_T<float> &point, const Point2D_T<float> &uv, const Vector4D_T<float> &normal):point_(point), uv_(uv), normal_(normal){}
		Vertex(const Vertex &ver):point_(ver.point_), uv_(ver.uv_), normal_(ver.normal_){}
		Vertex& operator = (const Vertex &ver)
		{
			point_ = ver.point_;
			uv_ = ver.uv_;
			normal_ = ver.normal_;
			return *this;
		}

		Point4D_T<float>& point()
		{
			return point_;
		}
		const Point4D_T<float>& point() const
		{
			return point_;
		}
		Point2D_T<float>& uv()
		{
			return uv_;
		}
		const Point2D_T<float>& uv() const
		{
			return uv_;
		}
		Vector4D_T<float>& normal()
		{
			return normal_;
		}
		const Vector4D_T<float>& normal() const
		{
			return normal_;
		}
		std::vector<size_t>& index()
		{
			return index_;
		}
		const std::vector<size_t>& index() const
		{
			return index_;
		}

		friend std::ostream& operator << (std::ostream &out, const Vertex &vertex)
		{
			out << "# Vertex" << std::endl;
			out << "# point" << std::endl;
			out << vertex.point();
			out << "# uv" << std::endl;
			out << vertex.uv();
			out << "# normal" << std::endl;
			out << vertex.normal();
			out << "# triangle index" << std::endl;
			for(auto it = vertex.index().begin(); it != vertex.index().end(); ++ it)
			{
				out << *it << ' ';
			}
			return out;
		}
		friend std::istream& operator >> (std::istream &in, Vertex &vertex)
		{
			in >> vertex.point() >> vertex.uv() >> vertex.normal();
			return in;
		}
	private:
		Point4D_T<float> point_;
		Point2D_T<float> uv_;
		Vector4D_T<float> normal_;
		std::vector<size_t> index_;
	};
}

#endif //AURORA_VERTEX_HPP_
