#include "Vertex.hpp"

namespace Aurora
{
    Vertex::Vertex():point_(0), uv_(0), normal_(0){}
    Vertex::Vertex(const Point4D_T<float> &point, const Point2D_T<float> &uv, const Vector4D_T<float> &normal):point_(point), uv_(uv), normal_(normal){}
    Vertex::Vertex(const Vertex &ver):point_(ver.point_), uv_(ver.uv_), normal_(ver.normal_){}
    Vertex& Vertex::operator = (const Vertex &ver)
    {
        point_ = ver.point_;
        uv_ = ver.uv_;
        normal_ = ver.normal_;
        return *this;
    }
}