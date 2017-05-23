#ifndef AURORA_FACE_HPP_
#define AURORA_FACE_HPP_

#include <cstddef>

namespace Aurora
{
    class Face
    {
    public:
        Face(size_t index1 = 0, size_t index2 = 0, size_t index3 = 0);
        Face(const Face &f);
        Face& operator = (const Face &f);

        size_t index[3];
    };
};

#endif // AURORA_FACE_HPP_