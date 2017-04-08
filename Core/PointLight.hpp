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
			std::cout << normal << position << std::endl;
			if(NdotD > 0)
			{
				std::cout << NdotD << "no" << std::endl;
				return RGB_T<float>::black;
			}
			else
			{
				std::cout << NdotD << "yes" << std::endl;
				return color_ * -NdotD / length2;
			}
		}
	private:
		Point4D_T<float> position_;
		RGB_T<float> color_;
	};
}

#endif //AURORA_POINT_LIGHT_HPP_
