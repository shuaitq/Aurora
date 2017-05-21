#ifndef AURORA_LIGHT_HPP_
#define AURORA_LIGHT_HPP_

#include "../Core/Color.hpp"
#include "../Math/Math.hpp"
#include "../Utility/json.hpp"

#include <iostream>

namespace Aurora
{
    class Light
    {
    public:
        virtual RGB_T<float> Sample(const Vector4D_T<float> &p, const Vector4D_T<float> &n) = 0;
        virtual void Set(const nlohmann::json &json) = 0;
    private:
    };
    std::vector<std::shared_ptr<Light>> LightList;
}

#endif //AURORA_LIGHT_HPP_