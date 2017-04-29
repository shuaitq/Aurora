#ifndef AURORA_POINT_LIGHT_HPP_
#define AURORA_POINT_LIGHT_HPP_

#include "../Core/Light.hpp"

namespace Aurora
{
    class PointLight:public Light
    {
    public:
        RGB_T<float> Sample(const Point4D_T<float> &p, const Vector4D_T<float> &n);
    private:
    };
}

#endif //AURORA_POINT_LIGHT_HPP_
