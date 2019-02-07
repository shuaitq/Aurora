#ifndef AURORA_CAMERA_HPP_
#define AURORA_CAMERA_HPP_

#include "../Math/Math.hpp"
#include "../Utility/json.hpp"

namespace Aurora
{
    class Camera
    {
    public:
        Camera();
        void Set(const nlohmann::json &json);
        Matrix4X4_T<double> ViewMatrix();
        Matrix4X4_T<double> ProjMatrix();

        Vector4D_T<double> position;
        Vector4D_T<double> u, v, n;
        double fov;
        double near, far;
        double aspect;
    private:
    };
    extern int height, width;
    extern Camera camera;
}

#endif //AURORA_CAMERA_HPP_