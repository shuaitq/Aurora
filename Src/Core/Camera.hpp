#ifndef AURORA_CAMERA_HPP_
#define AURORA_CAMERA_HPP_

#include "../Math/Math.hpp"
#include "../Utility/json.hpp"

#include <iostream>

namespace Aurora
{
    int height, width;
    class Camera
    {
    public:
        Camera();
        void Set(const nlohmann::json &json);

        Vector4D_T<float> position;
        Vector4D_T<float> u, v, n;
        float fov;
        float near, far;
        float aspect;
    private:
    };
    Camera camera;
}

#endif //AURORA_CAMERA_HPP_