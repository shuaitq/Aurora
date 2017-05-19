#ifndef AURORA_FACE_HPP_
#define AURORA_FACE_HPP_

#include <vector>

namespace Aurora
{
    struct Face
    {
        size_t VertexIndex[3];
    };
    std::vector<Face> FaceList;
};

#endif // AURORA_FACE_HPP_