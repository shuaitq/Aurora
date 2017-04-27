#include "Sence.hpp"

namespace Aurora
{
    void Sence::Sence(const std::string &path)
    {
        Loader::Load(path, *this);
    }

    std::ostream& operator << (std::ostream &out, const Sence &sence) const
    {
        out << "Width" << std::endl;
        out << width << std::endl;
        out << "Height" << std::endl;
        out << height << std::endl;
        out << "Camera" << std::endl;
        out << camera << std::endl;
        out << "Objects" << std::endl;
        for(auto it = object.begin(); it != object.end(); ++ it)
        {
            out << *it << std::endl;
        }
        out << "Lights";
        for(auto it = light.begin(); it != light.end(); ++ it)
        {
            out << std::endl << **it;
        }
        return out;
    }
}