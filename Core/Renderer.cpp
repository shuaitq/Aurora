#include "Renderer.hpp"

namespace Aurora
{
    Renderer::Renderer(const std::string &path)
    {
        Loader::Load(path, sence);
    }

    std::ostream& operator << (std::ostream &out, const Renderer &renderer)
    {
        out << "Sence" << std::endl;
        out << renderer.sence;
        return out;
    }
}