#ifndef AURORA_LIGHT_HPP_
#define AURORA_LIGHT_HPP_

#include "../Core/Color.hpp"
#include "../Math/Math.hpp"
#include "../Utility/json.hpp"

namespace Aurora
{
    class Light
    {
    public:
        virtual ~Light() = default;
        virtual RGB_T<double> Sample(const Vector4D_T<double> &p, const Vector4D_T<double> &n) = 0;
        virtual void Set(const nlohmann::json &json) = 0;
        virtual void Transform(const Matrix4X4_T<double> &m) = 0;
    private:
    };
    extern std::vector<std::shared_ptr<Light>> LightList;
}

#endif //AURORA_LIGHT_HPP_