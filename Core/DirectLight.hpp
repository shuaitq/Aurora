#ifndef AURORA_DIRECT_LIGHT_HPP_
#define AURORA_DIRECT_LIGHT_HPP_

#include "Light.hpp"

namespace Aurora
{
public:
	class DirectLight:public Light
	{
		RGB_T<float> Sample(Point4D_T<float> position, Vector4D_T<float> normal)
		{
			float NdotD = Dot(normal, direction_);
			if(NdotD > 0)
			{
				return RGB_T<float> black();
			}
			else
			{
				return color_ * -NdotD;
			}
		}
	}
private:
	Vector4D_T<float> direction_;
	RGB_T<float> color_;
}

#endif //AURORA_DIRECT_LIGHT_HPP_
