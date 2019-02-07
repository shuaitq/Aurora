#ifndef AURORA_DIRECT_LIGHT_HPP_
#define AURORA_DIRECT_LIGHT_HPP_

#include "Light.hpp"

namespace Aurora
{
    class DirectLight : public Light
    {
    public:
        DirectLight();
        RGB_T<double> Sample(const Vector4D_T<double> &p, const Vector4D_T<double> &n);
        void Set(const nlohmann::json &json);
        void Transform(const Matrix4X4_T<double> &m);
    private:
        Vector4D_T<double> direction, VD;
        RGB_T<double> color;
    };
}

#endif //AURORA_DIRECT_LIGHT_HPP_