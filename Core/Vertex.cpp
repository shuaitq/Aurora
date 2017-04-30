#include "Vertex.hpp"

namespace Aurora
{
     std::ostream& operator << (std::ostream &out, const Vertex &vertex)
     {
         out << "Point" << std::endl;
         out << vertex.point << std::endl;
         out << "Normal" << std::endl;
         out << vertex.normal << std::endl;
         out << "UV" << std::endl;
         out << vertex.uv;
         return out;
     }
}