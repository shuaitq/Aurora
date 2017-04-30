#include "DirectLight.hpp"

namespace Aurora
{
    RGB_T<float> DirectLight::Sample(const Point3D_T<float> &p, const Vector3D_T<float> &n)
    {
        float NdotD = Dot(n, direction);
        return color * std::max(0.0f, -NdotD);
    }
}