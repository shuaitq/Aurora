#include "Math/Math.hpp"
#include "Core/Vertex.hpp"
#include "Core/Object.hpp"
#include "Core/Renderer.hpp"

#include <cstdio>
#include <vector>

int main(int argc, char *argv[])
{
	using namespace Aurora;
	Renderer<> test;
	test.Load("Sence/cube.sence");
	test.Init();
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
