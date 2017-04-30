#include "Render.hpp"

namespace Aurora
{
    Render::Render(const std::string &path)
    {
        Loader::Load(path, sence, width, height, camera);
    }

    std::ostream& operator << (std::ostream &out, const Render &render)
    {
        out << "Width" << std::endl;
        out << render.width << std::endl;
        out << "Height" << std::endl;
        out << render.height << std::endl;
        out << "Camera" << std::endl;
        out << render.camera << std::endl;
        out << "Sence" << std::endl;
        out << render.sence;
        return out;
    }
}