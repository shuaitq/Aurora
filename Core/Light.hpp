#ifndef AURORA_LIGHT_HPP_
#define AURORA_LIGHT_HPP_

#include "Color.hpp"
#include "../Math/Math.hpp"

namespace Aurora
{
    class Light
    {
    public:
        Light(const Vector4D_T<float> &d, const Point4D_T<float> &p, const RGB_T<float> &c);
        Light& operator *= (const Matrix4_T<float> &m);
        virtual RGB_T<float> Sample(const Point4D_T<float> &position, const Vector4D_T<float> &normal) = 0;

        Vector4D_T<float> direction;
        Point4D_T<float> position;
        RGB_T<float> color;
    private:
    };
}

#endif //AURORA_LIGHT_HPP_