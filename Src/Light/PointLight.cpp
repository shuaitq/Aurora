#include "PointLight.hpp"

namespace Aurora
{
    RGB_T<float> PointLight::Sample(const Point3D_T<float> &p, const Vector3D_T<float> &n)
    {
        float length2 = (p - position).Length2();
        Vector3D_T<float> direction = Normalize(p - position);
        float NdotD = Dot(n, direction);
        return color * std::max(0.0f, -NdotD) / length2;
    }
    void PointLight::SetLight(const nlohmann::json &json)
    {
        const nlohmann::json &position = json["position"];
        position.x = position[0];
        position.y = position[1];
        position.z = position[2];
        const nlohmann::json &color = json["color"];
        color.red = color[0];
        color.green = color[1];
        color.blue = color[2];
    }
}