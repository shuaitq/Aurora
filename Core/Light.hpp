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

        friend std::ostream& operator << (std::ostream &out, const Light &light);

        Point3D_T<float> position;
        Vector3D_T<float> direction;
        RGB_T<float> color;
    private:
    };
}

#endif //AURORA_LIGHT_HPP_