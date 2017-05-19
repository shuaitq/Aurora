#ifndef AURORA_CAMERA_HPP_
#define AURORA_CAMERA_HPP_

#include "../Math/Math.hpp"

#include <iostream>

namespace Aurora
{
    struct Camera
    {
        Vector4D_T<float> position;
        Vector4D_T<float> u, v, n;
        float fov;
        float near, far;
        float aspect;
    };
    int height, width;
    Camera camera;
}

#endif //AURORA_CAMERA_HPP_
