#include "Camera.hpp"

namespace Aurora
{
    Matrix4_T<float> Camera::WorldToCamera()
    {
            float PdotR = position.x * right.x + position.y * right.y + position.z * right.z;
            float PdotU = position.x * up.x + position.y * up.y + position.z * up.z;
            float PdotF = position.x * front.x + position.y * front.y + position.z * front.z;
            return Matrix4_T<float>(right.x, up.x, front.x, 0.0f,
                                    right.y, up.y, front.y, 0.0f,
                                    right.z, up.z, front.z, 0.0f,
                                    -PdotR, -PdotU, -PdotF, 1.0f);
    }
    Matrix4_T<float> Camera::CameraToCVV()
    {
            return Matrix4_T<float>(1 / (tan(fov * 0.5f) *aspect), 0.0f, 0.0f, 0.0f,
                                    0.0f, 1 / tan(fov * 0.5f), 0.0f, 0.0f,
                                    0.0f, 0.0f, far / (far - near), 1.0f,
                                    0.0f, 0.0f, (near * far) / (near - far), 0.0f);
    }
    std::ostream& operator << (std::ostream &out, const Camera &camera)
    {
        out << "Position" << std::endl;
        out << camera.position << std::endl;
        out << "Up" << std::endl;
        out << camera.up << std::endl;
        out << "Front" << std::endl;
        out << camera.front << std::endl;
        out << "Right" << std::endl;
        out << camera.right << std::endl;
        out << "Fov" << std::endl;
        out << camera.fov << std::endl;
        out << "Aspect" << std::endl;
        out << camera.aspect;
        return out;
    }
}