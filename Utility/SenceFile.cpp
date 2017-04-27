#include "SenceFile.hpp"

namespace Aurora
{
    static void SenceFile::Load(const std::string &path, Sence &sence)
    {
        nlohmann::json j;
        std::ifstream in(path);
        if(!in.is_open())
        {
            throw std::runtime_error("Object " + path + " doesn't exist!");
        }
        in >> j;
        sence.width() = j["width"];
        sence.height() = j["height"];
        sence.camera().position() = j["camera"]["position"];
        sence.camera().up() = j["camera"]["up"];
    }
}