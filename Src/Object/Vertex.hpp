#ifndef AURORA_VERTEX_HPP_
#define AURORA_VERTEX_HPP_

#include "../Math/Math.hpp"

#include <vector>

namespace Aurora
{
    struct Vertex
    {
        size_t PointIndex;
        size_t NormalIndex;
        size_t UVIndex;
    };
    std::vector<Vector4D_T<float>> PointList;
    std::vector<Vector4D_T<float>> NormalList;
    std::vector<Vector2D_T<float>> UVList;
    std::vector<Vectex> VertexList;
};

#endif // AURORA_VERTEX_HPP_