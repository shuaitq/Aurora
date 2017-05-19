#ifndef AURORA_OBJECT_HPP_
#define AURORA_OBJECT_HPP_

#include <vector>

namespace Aurora
{
    struct Object
    {
        void Load(const std::string &path);

        Vector4D_T<float> position;
        Vector4D_T<float> u, v, n;
        Texture texure;
        std::vector<size_t> FaceIndex;
    };
    std::vector<Object> ObjectList;
};

#endif // AURORA_OBJECT_HPP_