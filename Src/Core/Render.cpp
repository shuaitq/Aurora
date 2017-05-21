#include "Render.hpp"

namespace Aurora
{
    Render::Render(const std::string &path)
    {
        Loader::Load(path, sence, width, height, camera);
        screen.resize(width * height);
        depth.resize(width * height);
    }

    std::vector<RGB_T<float>>& Render::Work()
    {
        
        return screen;
    }

    void Render::ObjectToWorld()
    {

    }
}