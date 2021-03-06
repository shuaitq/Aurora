#include "Vertex.hpp"

namespace Aurora
{
    Vertex::Vertex():point(0, 1), normal(0, 0), uv(){}
    Vertex::Vertex(const Vector4D_T<double> &p, const Vector4D_T<double> &n, const Vector2D_T<double> &u):point(p), normal(n), uv(u){}
    Vertex::Vertex(const Vertex &v):point(v.point), normal(v.normal), uv(v.uv){}
    Vertex& Vertex::operator = (const Vertex &v)
    {
        point = v.point;
        normal = v.normal;
        uv = v.uv;
        return *this;
    }

    std::vector<Vertex> VertexList;
}