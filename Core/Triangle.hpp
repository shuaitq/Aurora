#ifndef AURORA_TRIANGLE_HPP_
#define AURORA_TRIANGLE_HPP_

#include "../Math/Math.hpp"
#include "Vertex.hpp"

#include <cstdio>
#include <vector>
#include <iostream>

namespace Aurora
{
	class Triangle
	{
	public:
		Triangle();
		Triangle(const Vertex &v1, const Vertex &v2, const Vertex &v3);
		Triangle& operator=(const Triangle &tri);
		
		Vertex& operator [] (size_t index);
		const Vertex& operator [] (size_t index) const;
	private:
		Vertex vertex_[3];
	};
	std::ostream& operator << (std::ostream& out, const Triangle &triangle);
	std::istream& operator >> (std::istream& in, Triangle &triangle);
}

#endif //AURORA_TRIANGLE_HPP_
