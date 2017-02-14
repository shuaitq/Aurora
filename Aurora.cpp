#include "Math/Math.hpp"
#include "Core/Vertex.hpp"
#include "Core/Object.hpp"
#include "Core/Renderer.hpp"

#include <cstdio>
#include <vector>

int main(int argc, char *argv[])
{
	using namespace Aurora;
	Renderer test;
	test.Load("Sence/cube.sence");
	std::cout << test;
	return 0;
}
