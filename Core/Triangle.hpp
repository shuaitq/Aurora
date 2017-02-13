#ifndef AURORA_TRIANGLE_HPP_
#define AURORA_TRIANGLE_HPP_

#include "../Math/Math.hpp"

#include <cstdio>
#include <vector>

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
		Triangle(const std::vector<size_t> &index)
		{
			index_[0] = index[0];
			index_[1] = index[1];
			index_[2] = index[2];
		}
		Triangle& operator=(const Triangle &tri)
		{
			index_[0] = tri.index_[0];
			index_[1] = tri.index_[1];
			index_[2] = tri.index_[2];
			return *this;
		}
	private:
		size_t index_[3];
	};
}

#endif //AURORA_TRIANGLE_HPP_
