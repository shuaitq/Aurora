#ifndef AURORA_OBJECT_FILE_HPP_
#define AURORA_OBJECT_FILE_HPP_

#include "../Math/Math.hpp"
#include "../Core/Object.hpp"

#include <vector>
#include <string>
#include <fstream>

class Object;

namespace Aurora
{
    class ObjectFile
    {
    public:
        static void Load(const std::string &path, Object &object);
    };
}

#endif //AURORA_OBJECT_FILE_HPP_
