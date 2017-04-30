#include "Camera.hpp"

namespace Aurora
{
    std::ostream& operator << (std::ostream &out, const Camera &camera)
    {
        out << "Position" << std::endl;
        out << camera.position << std::endl;
        out << "RotateX" << std::endl;
        out << camera.rotatex << std::endl;
        out << "RotateY" << std::endl;
        out << camera.rotatey << std::endl;
        out << "RotateZ" << std::endl;
        out << camera.rotatez << std::endl;
        out << "Fov" << std::endl;
        out << camera.fov << std::endl;
        out << "Near" << std::endl;
        out << camera.near << std::endl;
        out << "Far" << std::endl;
        out << camera.far << std::endl;
        out << "Aspect" << std::endl;
        out << camera.aspect;
        return out;
    }
}