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
        Vertex(const Point4D_T<float> &p, const Point2D_T<float> &u, const Vector4D_T<float> &n);
        Vertex(const Vertex &ver);
        Vertex& operator = (const Vertex &ver);

        friend std::ostream& operator << (std::ostream &out, const Vertex &vertex);

        Point4D_T<float> point;
        Point2D_T<float> uv;
        Vector4D_T<float> normal;
    private:
    };
}

#endif //AURORA_VERTEX_HPP_
