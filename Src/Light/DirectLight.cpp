#include "DirectLight.hpp"

namespace Aurora
{
    DirectLight::DirectLight():direction(0, 0), VD(0, 0), color(){}
    RGB_T<double> DirectLight::Sample(const Vector4D_T<double> &p, const Vector4D_T<double> &n)
    {
        double NdotD = Dot(n, VD);
        return color * std::max(0.0, -NdotD);
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
    void DirectLight::Transform(const Matrix4X4_T<double> &m)
    {
        VD = direction * m;
    }
}