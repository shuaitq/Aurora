#ifndef AURORA_CAMERA_HPP_
#define AURORA_CAMERA_HPP_

#include "../Math/Math.hpp"

#include <iostream>

namespace Aurora
{
    class Camera
    {
    public:
        friend std::ostream& operator << (std::ostream &out, const Camera &camera);

        Point3D_T<float> position;
        float rotatex, rotatey, rotatez;
        float fov;
        float near, far;
        float aspect;
    private:
    };
}

#endif //AURORA_CAMERA_HPP_
