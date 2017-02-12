#ifndef AURORA_TRIANGLE_HPP_
#define AURORA_TRIANGLE_HPP_

#include "../Math/Math.hpp"
#include "Vertex.hpp"

#include <cstdio>

namespace Aurora
{
	class Triangle
	{
	public:
		Triangle(const Vertex &vertex1, const Vertex &vertex2, const Vertex &vertex3)
		{
			vertex_[0] = vertex1;
			vertex_[1] = vertex2;
			vertex_[2] = vertex3;
		}
		Triangle(const std::vector<Vertex> &ver)
		{
			vertex_[0] = ver[0];
			vertex_[1] = ver[1];
			vertex_[2] = ver[2];
		}
		Triangle& operator=(const Triangle &tri)
		{
			vertex_[0] = tri.vertex_[0];
			vertex_[1] = tri.vertex_[1];
			vertex_[2] = tri.vertex_[2];
			return *this;
		}
	private:
		Vertex vertex_[3];
	};
}

#endif //AURORA_TRIANGLE_HPP_
