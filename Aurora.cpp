#include "Utility/PPM.hpp"

#include <cstdio>
int main(int argc, char *argv[])
{
	using namespace Aurora;
	RGB_T<float> src[6]=
	{
		RGB_T<float>(1, 0, 0), RGB_T<float>(0, 1, 0), RGB_T<float>(0, 0, 1), RGB_T<float>(1, 1, 0), RGB_T<float>(1, 1, 1), RGB_T<float>(0, 0, 0)
	};
	for(size_t i = 0; i < 6; ++ i)
	{
		printf("%zu %f %f %f\n", i, src[i][0], src[i][1], src[i][2]);
	}
	printf("%d\n", PPM::Save("test.ppm",src,3,2));
	return 0;
}
