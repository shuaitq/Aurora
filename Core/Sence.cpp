#include "Sence.hpp"

namespace Aurora
{
    std::ostream& operator << (std::ostream &out, const Sence &sence)
    {
        out << "Objects" << std::endl;
        for(auto &it : sence.object)
        {
            out << *it << std::endl;
        }
        out << "Lights" << std::endl;
        for(auto &it : sence.light)
        {
            out << *it << std::endl;
        }
        out << "Camera" << std::endl;
        out << sence.camera << std::endl;
        out << "Width" << std::endl;
        out << sence.width << std::endl;
        out << "Height" << std::endl;
        out << sence.height;
        return out;
    }
}