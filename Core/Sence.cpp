#include "Sence.hpp"

namespace Aurora
{
    Sence::Sence(){}

    std::ostream& operator << (std::ostream &out, const Sence &sence)
    {
        out << "Width" << std::endl;
        out << sence.width << std::endl;
        out << "Height" << std::endl;
        out << sence.height << std::endl;
        out << "Camera" << std::endl;
        out << sence.camera << std::endl;
        out << "Objects" << std::endl;
        for(auto &it : sence.object)
        {
            out << *it << std::endl;
        }
        out << "Lights";
        for(auto &it : sence.light)
        {
            out << std::endl << *it;
        }
        return out;
    }
}