#include "Vertex.hpp"

namespace Aurora
{
    Vertex::Vertex():point(), uv(), normal(){}
    Vertex::Vertex(const Point4D_T<float> &p, const Point2D_T<float> &u, const Vector4D_T<float> &n):point(p), uv(u), normal(n){}
    Vertex::Vertex(const Vertex &ver):point(ver.point), uv(ver.uv), normal(ver.normal){}
    Vertex& Vertex::operator = (const Vertex &ver)
    {
        point = ver.point;
        uv = ver.uv;
        normal = ver.normal;
        return *this;
    }
    Vertex& Vertex::operator *= (const Matrix4_T<float> &m)
    {
        point *= m;
        normal *= m;
        return *this;
    }

     std::ostream& operator << (std::ostream &out, const Vertex &vertex)
     {
         out << "Point" << std::endl;
         out << vertex.point << std::endl;
         out << "UV" << std::endl;
         out << vertex.uv << std::endl;
         out << "Normal" << std::endl;
         out << vertex.normal;
         return out;
     }
}