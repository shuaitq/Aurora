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

    Point4D_T<float>& Vertex::point()
    {
        return point_;
    }
    const Point4D_T<float>& Vertex::point() const
    {
        return point_;
    }
    Point2D_T<float>& Vertex::uv()
    {
        return uv_;
    }
    const Point2D_T<float>& Vertex::uv() const
    {
        return uv_;
    }
    Vector4D_T<float>& Vertex::normal()
    {
        return normal_;
    }
    const Vector4D_T<float>& Vertex::normal() const
    {
        return normal_;
    }

    std::ostream& operator << (std::ostream &out, const Vertex &vertex)
    {
        out << "# Vertex" << std::endl;
        out << "# point" << std::endl;
        out << vertex.point();
        out << "# uv" << std::endl;
        out << vertex.uv();
        out << "# normal" << std::endl;
        out << vertex.normal();
        return out;
    }
    std::istream& operator >> (std::istream &in, Vertex &vertex)
    {
        in >> vertex.point() >> vertex.uv() >> vertex.normal();
        return in;
    }
}