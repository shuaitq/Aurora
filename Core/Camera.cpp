#include "Camera.hpp"

namespace Aurora
{
    Matrix4_T<float> Camera::WorldToCamera()
    {
            float PdotR = position.x * right.x + position.y * right.y + position.z * right.z;
            float PdotU = position.x * up.x + position.y * up.y + position.z * up.z;
            float PdotF = position.x * front.x + position.y * front.y + position.z * front.z;
            return Matrix4_T<float>(right.x, up.x, front.x, 0,
                                    right.y, up.y, front.y, 0,
                                    right.z, up.z, front.z, 0,
                                    -PdotR, -PdotU, -PdotF, 1);
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