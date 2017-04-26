#include "Triangle.hpp"

namespace Aurora
{
    Triangle::Triangle(const Vertex &v1, const Vertex &v2, const Vertex &v3)
    {
        vertex_[0] = v1;
        vertex_[1] = v2;
        vertex_[2] = v3;
    }
    Triangle& Triangle::operator=(const Triangle &tri)
    {
        vertex_[0] = tri.vertex_[0];
        vertex_[1] = tri.vertex_[1];
        vertex_[2] = tri.vertex_[2];
        return *this;
    }
    
    Vertex& Triangle::operator [] (size_t index)
    {
        return vertex_[index];
    }
    const Vertex& Triangle::operator [] (size_t index) const
    {
        return vertex_[index];
    }

    std::ostream& operator << (std::ostream& out, const Triangle &triangle)
    {
        out << "# Triangle" << std::endl;
        out << triangle[0] << ' ' << triangle[1] << ' ' << triangle[2];
        return out;
    }
    std::istream& operator >> (std::istream& in, Triangle &triangle)
    {
        in >> triangle[0] >> triangle[1] >> triangle[2]; 
        return in;
    }
}