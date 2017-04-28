#ifndef AURORA_POINT_LIGHT_HPP_
#define AURORA_POINT_LIGHT_HPP_

#include "../Core/Light.hpp"

namespace Aurora
{
    class PointLight:public Light
    {
    public:
        PointLight(const Point4D_T<float> &position, const RGB_T<float> &color);
        RGB_T<float> Sample(const Point4D_T<float> &position, const Vector4D_T<float> &normal, const Matrix4_T<float> &m);
    private:
        Point4D_T<float> position_;
        RGB_T<float> color_;
    };
}

#endif //AURORA_POINT_LIGHT_HPP_
