#include "Light.hpp"

namespace Aurora
{
    std::ostream& operator << (std::ostream &out, const Light &light)
    {
        out << "Position" << std::endl;
        out << light.position << std::endl;
        out << "Direction" << std::endl;
        out << light.direction << std::endl;
        out << "Color" << std::endl;
        out << light.color;
        return out;
    }
}