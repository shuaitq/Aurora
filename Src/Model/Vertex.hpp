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
        Vertex(const Vector4D_T<float> &p, const Vector4D_T<float> &n, const Vector2D_T<float> &u);
        Vertex(const Vertex &v);
        Vertex& operator = (const Vertex &v);

        Vertex operator * (const Matrix4X4_T<float> &m) const;
        Vertex& operator *= (const Matrix4X4_T<float> &m);

        Vector4D_T<float> point;
        Vector4D_T<float> normal;
        Vector2D_T<float> uv;
    };
    extern std::vector<Vertex> VertexList;
};

#endif // AURORA_VERTEX_HPP_