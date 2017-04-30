#include "Triangle.hpp"

namespace Aurora
{
    Triangle::Triangle(){}
    std::ostream& operator << (std::ostream &out, const Triangle &triangle)
    {
        out << "Vertex 1" << std::endl;
        out << triangle.vertex[0] << std::endl;
        out << "Vertex 2" << std::endl;
        out << triangle.vertex[1] << std::endl;
        out << "Vertex 3" << std::endl;
        out << triangle.vertex[2];
        return out;
    }
}