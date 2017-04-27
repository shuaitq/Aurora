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
	//test.light().push_back(new DirectLight(Vector4D_T<float>(-0.267261, -0.534522, -0.801784), RGB_T<float>(0.35, 0.15, 0.15)));
	//test.light().push_back(new PointLight(Point4D_T<float>(1, 1, 1), RGB_T<float>(0.25, 0.25, 0.75)));
	//test.Load("Sence/cube.sence");
	//test.Init();
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