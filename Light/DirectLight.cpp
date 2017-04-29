#include "DirectLight.hpp"

namespace Aurora
{
    DirectLight::DirectLight(const Vector4D_T<float> &direction, const RGB_T<float> &color):direction_(direction), color_(color){}
    RGB_T<float> DirectLight::Sample(const Point4D_T<float> &position, const Vector4D_T<float> &normal)
    {
        float NdotD = Dot(normal, direction_ * m);
        return color_ * std::max(0.0f, -NdotD);
    }
}