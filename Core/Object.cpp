#include "Object.hpp"

namespace Aurora
{
    std::ostream& operator << (std::ostream &out, const Object &object)
    {
        out << "Triangle" << std::endl;
        for(auto it = object.triangle.begin(); it != object.triangle.end(); ++ it)
        {
            out << *it << std::endl;
        }
        out << "Texture" << std::endl;
        out << object.texture << std::endl;
        out << "Position" << std::endl;
        out << object.position << std::endl;
        out << "RotateX" << std::endl;
        out << object.rotatex << std::endl;
        out << "RotateY" << std::endl;
        out << object.rotatey << std::endl;
        out << "RotateZ" << std::endl;
        out << object.rotatez;
        return out;
    }
}