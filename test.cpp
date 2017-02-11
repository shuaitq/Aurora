#include "Utility/PPM.hpp"
#define length 1024
using namespace Aurora;
RGB_T<float> src[length*length];
int main(){
	for(size_t i = 0; i < length; ++ i)
	{
		for(size_t j = 0; j < length; ++ j)
		{
			if(((i / 64) + (j / 64)) % 2 == 1)
			{
				src[i*length+j]=RGB_T<float>::black;
			}
			else
			{
				src[i*length+j]=RGB_T<float>::white;
			}
		}
	}
	PPM::Save("chess.ppm",src,length,length);
	return 0;
}
