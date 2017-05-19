#ifndef AURORA_DIRECT_LIGHT_HPP_
#define AURORA_DIRECT_LIGHT_HPP_

#include "../Core/Light.hpp"

namespace Aurora
{
    class DirectLight:public Light
    {
    public:
        RGB_T<float> Sample(const Point3D_T<float> &p, const Vector3D_T<float> &n);
        void SetLight(const nlohmann::json &json);
    private:
        Vector4D_T<float> direction;
        RGB_T<float> color;
    };
}

#endif //AURORA_DIRECT_LIGHT_HPP_