#ifndef AURORA_MATH_HPP_
#define AURORA_MATH_HPP_

#include "Point.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"

#include <cmath>

// return t1 * u + t2 * (1-u) 
template <typename T, typename U>
T Interpolation(const T &t1, const T &t2, const U u)
{
	return t1 * u + t2 * (1 - u);
}

#endif //AURORA_MATH_HPP_
