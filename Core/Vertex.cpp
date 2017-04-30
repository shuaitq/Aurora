#include "Vertex.hpp"

namespace Aurora
{
    Vertex::Vertex():point(), normal(), uv(){}
    Vertex::Vertex(const Point3D_T<float> &p, const Vector3D_T<float> &n, const Point2D_T<float> &u):point(p), normal(n), uv(u){}
    Vertex::Vertex(const Vertex &v):point(v.point), normal(v.normal), uv(v.uv){}
    Vertex& Vertex::operator = (const Vertex &v)
    {
        point = v.point;
        normal = v.normal;
        uv = v.uv;
        return *this;
    }

    std::ostream& operator << (std::ostream &out, const Vertex &vertex)
    {
        out << "Point" << std::endl;
        out << vertex.point << std::endl;
        out << "Normal" << std::endl;
        out << vertex.normal << std::endl;
        out << "UV" << std::endl;
        out << vertex.uv;
        return out;
    }
}