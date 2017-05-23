#include "Face.hpp"

namespace Aurora
{
    Face::Face(size_t index1, size_t index2, size_t index3)
    {
        index[0] = index1;
        index[1] = index2;
        index[2] = index3;
    }
    Face::Face(const Face &f)
    {
        index[0] = f.index[0];
        index[1] = f.index[1];
        index[2] = f.index[2];
    }
    Face& Face::operator = (const Face &f)
    {
        index[0] = f.index[0];
        index[1] = f.index[1];
        index[2] = f.index[2];
        return *this;
    }
}