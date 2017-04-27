#include "Camera.hpp"

namespace Aurora
{
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