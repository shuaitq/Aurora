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
        out << "Lights";
        for(auto &it : sence.light)
        {
            out << std::endl << *it;
        }
        return out;
    }
}