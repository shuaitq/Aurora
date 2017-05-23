#ifndef AURORA_OBJECT_FILE_HPP_
#define AURORA_OBJECT_FILE_HPP_

#include "../Math/Math.hpp"
#include "../Model/Texture.hpp"
#include "../Model/Face.hpp"
#include "../Model/Vertex.hpp"

#include <vector>
#include <string>

namespace Aurora
{
    class ObjectFile
    {
    public:
        static void Load(const std::string &path, std::vector<Vertex> &vertex, std::vector<Face> &face, Texture &texture);
    };
}

#endif //AURORA_OBJECT_FILE_HPP_