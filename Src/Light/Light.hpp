#ifndef AURORA_LIGHT_HPP_
#define AURORA_LIGHT_HPP_

#include "Color.hpp"
#include "../Math/Math.hpp"

#include <iostream>

namespace Aurora
{
    class Light
    {
    public:
        virtual RGB_T<float> Sample(const Point3D_T<float> &p, const Vector3D_T<float> &n) = 0;
        virtual void SetLight(const nlohmann::json &json) = 0;
    private:
    };
    std::vector<std::shared_ptr<Light>> LightList;
}

#endif //AURORA_LIGHT_HPP_