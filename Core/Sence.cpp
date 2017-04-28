#include "Sence.hpp"

namespace Aurora
{
    Sence::Sence(const std::string &path)
    {
        Loader::Load(path, *this);
    }

    std::ostream& operator << (std::ostream &out, const Sence &sence)
    {
        out << "Width" << std::endl;
        out << sence.width << std::endl;
        out << "Height" << std::endl;
        out << sence.height << std::endl;
        out << "Camera" << std::endl;
        out << sence.camera << std::endl;
        out << "Objects" << std::endl;
        for(auto it = sence.object.begin(); it != sence.object.end(); ++ it)
        {
            out << *it << std::endl;
        }
        out << "Lights";
        for(auto it = sence.light.begin(); it != sence.light.end(); ++ it)
        {
          //  out << std::endl << **it;
        }
        return out;
    }
}