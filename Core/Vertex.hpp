#ifndef AURORA_VERTEX_HPP_
#define AURORA_VERTEX_HPP_

#include "../Math/Math.hpp"

#include <iostream>

namespace Aurora
{
    class Vertex
    {
    public:
        friend std::ostream& operator << (std::ostream &out, const Vertex &vertex);

        Point3D_T<float> point;
        Vector3D_T<float> normal;
        Point2D_T<float> uv;
    private:
    };
}

#endif //AURORA_VERTEX_HPP_
