#ifndef AURORA_TRIANGLE_HPP_
#define AURORA_TRIANGLE_HPP_

#include "../Math/Math.hpp"
#include "Vertex.hpp"

#include <iostream>

namespace Aurora
{
    class Triangle
    {
    public:
        friend std::ostream& operator << (std::ostream &out, const Triangle &triangle);

        Vertex vertex[3];
    private:
    };
}

#endif //AURORA_TRIANGLE_HPP_
