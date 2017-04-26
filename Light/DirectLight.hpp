#ifndef AURORA_DIRECT_LIGHT_HPP_
#define AURORA_DIRECT_LIGHT_HPP_

#include "Light.hpp"

namespace Aurora
{
	class DirectLight:public Light
	{
	public:
		DirectLight(const Vector4D_T<float> &direction, const RGB_T<float> &color):direction_(direction), color_(color){}
		RGB_T<float> Sample(const Point4D_T<float> &position, const Vector4D_T<float> &normal, const Matrix4_T<float> &m)
		{
			float NdotD = Dot(normal, direction_ * m);
			if(NdotD > 0)
			{
				return RGB_T<float>::black;
			}
			else
			{
				return color_ * -NdotD;
			}
		}
	private:
		Vector4D_T<float> direction_;
		RGB_T<float> color_;
	};
}

#endif //AURORA_DIRECT_LIGHT_HPP_
