#ifndef AURORA_TRIANGLE_HPP_
#define AURORA_TRIANGLE_HPP_

#include "../Math/Math.hpp"

#include <cstdio>
#include <vector>
#include <iostream>

namespace Aurora
{
	class Triangle
	{
	public:
		Triangle(const size_t index1, const size_t index2, const size_t index3)
		{
			index_[0] = index1;
			index_[1] = index2;
			index_[2] = index3;
		}
		Triangle& operator=(const Triangle &tri)
		{
			index_[0] = tri.index_[0];
			index_[1] = tri.index_[1];
			index_[2] = tri.index_[2];
			return *this;
		}
		
		size_t& operator [] (size_t index)
		{
			return index_[index];
		}
		const size_t& operator [] (size_t index) const
		{
			return index_[index];
		}

		friend std::ostream& operator << (std::ostream& out, const Triangle &triangle)
		{
			out << "# Triangle" << std::endl;
			out << triangle[0] << ' ' << triangle[1] << ' ' << triangle[2] << std::endl;
			return out;
		}
		friend std::istream& operator >> (std::istream& in, Triangle &triangle)
		{
			in >> triangle[0] >> triangle[1] >> triangle[2]; 
			return in;
		}
	private:
		size_t index_[3];
	};
}

#endif //AURORA_TRIANGLE_HPP_
