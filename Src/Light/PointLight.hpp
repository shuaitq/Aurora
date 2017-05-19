#ifndef AURORA_POINT_LIGHT_HPP_
#define AURORA_POINT_LIGHT_HPP_

#include "../Core/Light.hpp"

namespace Aurora
{
    class PointLight:public Light
    {
    public:
        RGB_T<float> Sample(const Point3D_T<float> &p, const Vector3D_T<float> &n);
        void SetLight(const nlohmann::json &json);
    private:
        Vector4D_T<float> position;
        RGB_T<float> color;
    };
}

#endif //AURORA_POINT_LIGHT_HPP_
