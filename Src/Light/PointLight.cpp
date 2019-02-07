#include "PointLight.hpp"

namespace Aurora
{
    PointLight::PointLight():position(0, 1), VP(0, 1), color(){}
    RGB_T<double> PointLight::Sample(const Vector4D_T<double> &p, const Vector4D_T<double> &n)
    {
        double length2 = (p - VP).Length2();
        Vector4D_T<double> direction = Normalize(p - VP);
        double NdotD = Dot(n, direction);
        return color * std::max(0.0, -NdotD) / length2;
    }
    void PointLight::Set(const nlohmann::json &json)
    {
        const nlohmann::json &Position = json["position"];
        position.x = Position[0];
        position.y = Position[1];
        position.z = Position[2];
        position.w = 1;
        const nlohmann::json &Color = json["color"];
        color.red = Color[0];
        color.green = Color[1];
        color.blue = Color[2];
    }
    void PointLight::Transform(const Matrix4X4_T<double> &m)
    {
        VP = position * m;
    }
}