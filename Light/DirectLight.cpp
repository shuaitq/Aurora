#include "DirectLight.hpp"

namespace Aurora
{
    RGB_T<float> DirectLight::Sample(const Point4D_T<float> &p, const Vector4D_T<float> &n)
    {
        float NdotD = Dot(n, direction);
        return color * std::max(0.0f, -NdotD);
    }
}