#ifndef AURORA_POINT_LIGHT_HPP_
#define AURORA_POINT_LIGHT_HPP_

#include "Light.hpp"

namespace Aurora
{
	class PointLight:public Light
	{
	public:
		RGB_T<float> Sample(Point4D_T<float> &position, Vector4D_T<float> &normal)
		{
			float length2 = Length2(position - position_);
			Vector4D_T<float> direction = Normalize(position - position_);
			float NdotD = Dot(normal, direction);
			if(NdotD > 0)
			{
				return RGB_T<float>::black;
			}
			else
			{
				return color_ * NdotD * / length2;
			}
		}
	private:
		Point4D_T<float> position_;
		RGB_T<float> color_;
	}
}

#endif //AURORA_POINT_LIGHT_HPP_
