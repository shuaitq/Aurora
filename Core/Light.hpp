#ifndef AURORA_LIGHT_HPP_
#define AURORA_LIGHT_HPP_

#include "Color.hpp"
#include "../Math/Vector.hpp"
#include "../Math/Point.hpp"

namespace Aurora
{
	class Light
	{
	public:
		virtual RGB_T<float> Sample(const Point4D_T<float> &position, const Vector4D_T<float> &normal, const Matrix4_T<float> &m) = 0;
	private:
	};
}

#endif //AURORA_LIGHT_HPP_
