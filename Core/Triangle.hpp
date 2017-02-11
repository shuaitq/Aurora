#ifndef AURORA_TRIANGLE_HPP_
#define AURORA_TRIANGLE_HPP_

#include "../Math/Math.hpp"

namespace Aurora
{
	class Triangle
	{
	public:
	private:
		Point4D_T<float> point_[3];
		Point2D_T<float> uv_;
		Point4D_T<float> normal_;
	}
}

#endif //AURORA_TRIANGLE_HPP_
