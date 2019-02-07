#ifndef AURORA_VERTEX_HPP_
#define AURORA_VERTEX_HPP_

#include "../Math/Math.hpp"

#include <vector>

namespace Aurora
{
    class Vertex
    {
    public:
        Vertex();
        Vertex(const Vector4D_T<double> &p, const Vector4D_T<double> &n, const Vector2D_T<double> &u);
        Vertex(const Vertex &v);
        Vertex& operator = (const Vertex &v);

        Vector4D_T<double> point;
        Vector4D_T<double> normal;
        Vector2D_T<double> uv;
    };
    extern std::vector<Vertex> VertexList;
};

#endif // AURORA_VERTEX_HPP_