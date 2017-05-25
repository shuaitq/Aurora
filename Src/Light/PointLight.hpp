#ifndef AURORA_POINT_LIGHT_HPP_
#define AURORA_POINT_LIGHT_HPP_

#include "Light.hpp"

namespace Aurora
{
    class PointLight : public Light
    {
    public:
        PointLight();
        RGB_T<float> Sample(const Vector4D_T<float> &p, const Vector4D_T<float> &n);
        void Set(const nlohmann::json &json);
        void Transform(const Matrix4X4_T<float> &m);
    private:
        Vector4D_T<float> position, VP;
        RGB_T<float> color;
    };
}

#endif //AURORA_POINT_LIGHT_HPP_
