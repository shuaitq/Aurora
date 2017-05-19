#include "DirectLight.hpp"

namespace Aurora
{
    RGB_T<float> DirectLight::Sample(const Point3D_T<float> &p, const Vector3D_T<float> &n)
    {
        float NdotD = Dot(n, direction);
        return color * std::max(0.0f, -NdotD);
    }
    void DirectLight::SetLight(const nlohmann::json &json)
    {
        const nlohmann::json &direction = json["direction"];
        direction.x = direction[0];
        direction.y = direction[1];
        direction.z = direction[2];
        const nlohmann::json &color = json["color"];
        color.red = color[0];
        color.green = color[1];
        color.blue = color[2];
    }
}