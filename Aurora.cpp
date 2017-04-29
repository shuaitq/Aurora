#include "Core/Renderer.hpp"

#include <cstdio>

int main(int argc, char *argv[])
{
    using namespace Aurora;
    if(argc != 2)
    {
        throw std::runtime_error("Please input right path!");
    }
    //Renderer render(argv[1]);
    for(size_t i = 1; i <= 360; ++ i)
    {
        std::string str = "Image/";
        char temp[10];
        sprintf(temp,"%zu",i);
        str += temp;
        str += ".ppm";
        std::cout << str << std::endl;
        //render.Render(str);
    }
    //std::cout << render;
    return 0;
}