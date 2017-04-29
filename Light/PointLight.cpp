#include "PointLight.hpp"

namespace Aurora
{
    PointLight::PointLight(const Point4D_T<float> &position, const RGB_T<float> &color):position_(position), color_(color){}
    RGB_T<float> PointLight::Sample(const Point4D_T<float> &position, const Vector4D_T<float> &normal)
    {
        float length2 = (position - position_ * m).Length2();
        Vector4D_T<float> direction = Normalize(position - position_ * m);
        float NdotD = Dot(normal, direction);
        return color_ * std::max(0.0f, -NdotD) / length2;
    }
}