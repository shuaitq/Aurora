#ifndef AURORA_CAMERA_HPP_
#define AURORA_CAMERA_HPP_

#include "../Math/Math.hpp"

#include <iostream>

namespace Aurora
{
    class Camera
    {
    public:
        Matrix4_T<float> WorldToCamera();
        Matrix4_T<float> CameraToCVV();
        friend std::ostream& operator << (std::ostream &out, const Camera &camera);

        Point4D_T<float> position;
        Vector4D_T<float> up;
        Vector4D_T<float> front;
        Vector4D_T<float> right;
        float fov;
        float near, far;
        float aspect;
    private:
    };
}

#endif //AURORA_CAMERA_HPP_
