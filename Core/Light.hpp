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
		virtual RGB_T<float> Sample(Point4D_T<float> &position, Vector4D_T<float> &normal) = 0;
	private:
	};
}

#endif //AURORA_LIGHT_HPP_
