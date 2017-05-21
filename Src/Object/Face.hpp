#ifndef AURORA_FACE_HPP_
#define AURORA_FACE_HPP_

namespace Aurora
{
    struct Face
    {
        size_t PointIndex[3];
        size_t NormalIndex[3];
        size_t UVIndex[3];
    };
};

#endif // AURORA_FACE_HPP_