#include "DirectLight.hpp"

namespace Aurora
{
    DirectLight():direction(0, 0), color(){}
    RGB_T<float> DirectLight::Sample(const Vector4D_T<float> &p, const Vector4D_T<float> &n)
    {
        float NdotD = Dot(n, direction);
        return color * std::max(0.0f, -NdotD);
    }
    void DirectLight::Set(const nlohmann::json &json)
    {
        const nlohmann::json &Direction = json["direction"];
        direction.x = Direction[0];
        direction.y = Direction[1];
        direction.z = Direction[2];
        direction.w = 0;
        const nlohmann::json &Color = json["color"];
        color.red = Color[0];
        color.green = Color[1];
        color.blue = Color[2];
    }
}