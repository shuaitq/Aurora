#include "Core/Render.hpp"

#include <cstdio>

int main(int argc, char *argv[])
{
    using namespace Aurora;
    if(argc != 2)
    {
        throw std::runtime_error("Please input right path!");
    }
    Render render(argv[1]);
    render.Work("output.ppm");
    return 0;
}