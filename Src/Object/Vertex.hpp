#ifndef AURORA_VERTEX_HPP_
#define AURORA_VERTEX_HPP_

#include "../Math/Math.hpp"

namespace Aurora
{
    struct Vertex
    {
        Vector4D_T<float> point;
        Vector4D_T<float> normal;
        Vector4D_T<float> uv;
    };
};

#endif // AURORA_VERTEX_HPP_