#include "Render.hpp"

namespace Aurora
{
    Render::Render(const std::string &path)
    {
        Loader::Load(path, sence, width, height, camera);
        screen.resize(width * height);
    }

    std::vector<RGB_T<float>>& Render::Work()
    {
        
        return screen;
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

    void Render::ObjectToWorld()
    {

    }
}