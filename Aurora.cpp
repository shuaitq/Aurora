#include "Math/Math.hpp"
#include "Core/Vertex.hpp"
#include "Core/Object.hpp"
#include "Core/Renderer.hpp"

#include "Core/DirectLight.hpp"
#include "Core/PointLight.hpp"

#include <cstdio>
#include <vector>

int main(int argc, char *argv[])
{
    using namespace Aurora;
    if(argc != 2)
    {
        printf("Please input right path!\n");
        return 0;
    }
    Renderer render(argv[1]);
    for(size_t i = 1; i <= 360; ++ i)
    {
        std::string str = "Image/";
        char temp[10];
        sprintf(temp,"%zu",i);
        str += temp;
        str += ".ppm";
        std::cout << str << std::endl;
        test.Render(str);
    }
    std::cout << test;
    return 0;
}