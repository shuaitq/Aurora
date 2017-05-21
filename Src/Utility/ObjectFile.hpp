#ifndef AURORA_OBJECT_FILE_HPP_
#define AURORA_OBJECT_FILE_HPP_

#include "../Math/Math.hpp"
#include "../Object/Texture.hpp"
#include "../Object/Face.hpp"

#include <vector>
#include <string>

namespace Aurora
{
    class ObjectFile
    {
    public:
        static void Load(const std::string &path, std::vector<Vector4D_T<float>> &point, std::vector<Vector4D_T<float>> &normal, std::vector<Vector2D_T<float>> &uv, std::vector<Face> &face, Texture &texture);
    };
}

#endif //AURORA_OBJECT_FILE_HPP_