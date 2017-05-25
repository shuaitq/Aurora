#ifndef AURORA_DIRECT_LIGHT_HPP_
#define AURORA_DIRECT_LIGHT_HPP_

#include "Light.hpp"

namespace Aurora
{
    class DirectLight : public Light
    {
    public:
        DirectLight();
        RGB_T<float> Sample(const Vector4D_T<float> &p, const Vector4D_T<float> &n);
        void Set(const nlohmann::json &json);
        void Transform(const Matrix4X4_T<float> &m);
    private:
        Vector4D_T<float> direction, VD;
        RGB_T<float> color;
    };
}

#endif //AURORA_DIRECT_LIGHT_HPP_