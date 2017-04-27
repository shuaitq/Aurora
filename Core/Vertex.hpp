#ifndef AURORA_VERTEX_HPP_
#define AURORA_VERTEX_HPP_

#include "../Math/Math.hpp"

#include <vector>
#include <iostream>

namespace Aurora
{
    class Vertex
    {
    public:
        Vertex();
        Vertex(const Point4D_T<float> &point, const Point2D_T<float> &uv, const Vector4D_T<float> &normal);
        Vertex(const Vertex &ver);
        Vertex& operator = (const Vertex &ver);

        Point4D_T<float> point_;
        Point2D_T<float> uv_;
        Vector4D_T<float> normal_;
    private:
    };
}

#endif //AURORA_VERTEX_HPP_
