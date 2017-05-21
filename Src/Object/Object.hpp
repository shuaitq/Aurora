#ifndef AURORA_OBJECT_HPP_
#define AURORA_OBJECT_HPP_

#include "Face.hpp"
#include "Texture.hpp"

#include <vector>

namespace Aurora
{
    class Object
    {
    public:
        void Load(const std::string &path);

        Vector4D_T<float> position;
        Vector4D_T<float> u, v, n;
        Texture texure;
        std::vector<Vector4D_T<float>> point;
        std::vector<Vector4D_T<float>> normal;
        std::vector<Vector2D_T<float>> uv;
        std::vector<Face> face;
    private:
        using Loader = ObjectFile;
    };
    std::vector<Object> ObjectList;
};

#endif // AURORA_OBJECT_HPP_