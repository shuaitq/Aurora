#ifndef AURORA_POINT_LIGHT_HPP_
#define AURORA_POINT_LIGHT_HPP_

#include "Light.hpp"

#include <iostream>

namespace Aurora
{
	class PointLight:public Light
	{
	public:
		PointLight(const Point4D_T<float> &position, const RGB_T<float> &color):position_(position), color_(color){}
		RGB_T<float> Sample(const Point4D_T<float> &position, const Vector4D_T<float> &normal, const Matrix4_T<float> &m)
		{
			float length2 = (position - position_ * m).Length2();
			Vector4D_T<float> direction = Normalize(position - position_ * m);
			float NdotD = Dot(normal, direction);
			if(NdotD > 0)
			{
				return RGB_T<float>::black;
			}
			else
			{
				return color_ * -NdotD / length2;
			}
		}
	private:
		Point4D_T<float> position_;
		RGB_T<float> color_;
	};
}

#endif //AURORA_POINT_LIGHT_HPP_
