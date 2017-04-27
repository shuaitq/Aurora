#include "Triangle.hpp"

namespace Aurora
{
    Triangle::Triangle()vertex[0](), vertex[1](), vertex[2](){}
    Triangle::Triangle(const Vertex &v1, const Vertex &v2, const Vertex &v3)
    {
        vertex[0] = v1;
        vertex[1] = v2;
        vertex[2] = v3;
    }
    Triangle& Triangle::operator=(const Triangle &tri)
    {
        vertex[0] = tri.vertex[0];
        vertex[1] = tri.vertex[1];
        vertex[2] = tri.vertex[2];
        return *this;
    }
}