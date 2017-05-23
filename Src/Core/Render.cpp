#include "Render.hpp"

namespace Aurora
{
    Render::Render(const std::string &path)
    {
        Loader::Load(path);
        screen.resize(width * height);
        depth.resize(width * height);
    }

    std::vector<RGBA_T<float>>& Render::Work(const std::string &path)
    {
        return screen;
    }
}