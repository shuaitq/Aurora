#ifndef AURORA_CAMERA_HPP_
#define AURORA_CAMERA_HPP_

#include "../Math/Math.hpp"
#include "../Utility/json.hpp"

#include <iostream>

namespace Aurora
{
    class Camera
    {
    public:
        Camera();
        void Set(const nlohmann::json &json);
        Matrix4X4_T<float> ViewMatrix();
        Matrix4X4_T<float> ProjMatrix();
        Matrix4X4_T<float> WindMatrix();

        Vector4D_T<float> position;
        Vector4D_T<float> u, v, n;
        float fov;
        float near, far;
        float aspect;
    private:
    };
    extern int height, width;
    extern Camera camera;
}

#endif //AURORA_CAMERA_HPP_