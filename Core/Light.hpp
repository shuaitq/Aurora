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
        Light();
        virtual RGB_T<float> Sample(const Point4D_T<float> &p, const Vector4D_T<float> &n) = 0;

        friend std::ostream& operator << (std::ostream &out, const Light &light);

        Vector4D_T<float> direction;
        Point4D_T<float> position;
        RGB_T<float> color;
    private:
    };
}

#endif //AURORA_LIGHT_HPP_