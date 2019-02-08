#ifndef AURORA_OBJECT_FILE_HPP_
#define AURORA_OBJECT_FILE_HPP_

#include "../Model/Texture.hpp"

#include <vector>
#include <string>
#include <array>

namespace Aurora
{
    class ObjectFile
    {
    public:
        static void Load(const std::string &root, const std::string &name, std::vector<std::array<size_t, 3>> &face, Texture &texture);
    };
}

#endif //AURORA_OBJECT_FILE_HPP_