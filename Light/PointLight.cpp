#include "PointLight.hpp"

namespace Aurora
{
    RGB_T<float> PointLight::Sample(const Point4D_T<float> &p, const Vector4D_T<float> &n)
    {
        float length2 = (p - position).Length2();
        Vector4D_T<float> direction = Normalize(p - position);
        float NdotD = Dot(n, direction);
        return color * std::max(0.0f, -NdotD) / length2;
    }
}