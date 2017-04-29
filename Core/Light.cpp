#include "Light.hpp"

namespace Aurora
{
    Light::Light(const Vector4D_T<float> &d, const Point4D_T<float> &p, const RGB_T<float> &c):direction(d), position(p), color(c){}
    Light& Light::operator *= (const Matrix4_T<float> &m)
    {
        position *= m;
        direction *= m;
        return *this;
    }
}