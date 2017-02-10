#ifndef AURORA_PPM_HPP_
#define AURORA_PPM_HPP_

#include <cstdio>
#include "../Core/Color.hpp"

namespace Aurora
{
	namespace PPM
	{
		bool Save(const char *path, const RGB_T<float> *src, const size_t width, const size_t height)
		{
			FILE *fp = fopen(path,"w");
			if(fp == nullptr)
			{
				return false;
			}
			fprintf(fp, "P3\n%zu %zu\n255\n", width, height);
			for(size_t i = 0; i < height * width; ++ i, ++ src)
			{
				fprintf(fp, "%d %d %d ", (int)(*src)[0]*255, (int)(*src)[1]*255, (int)(*src)[2]*255);
			}
			fclose(fp);
			return true;
		}
	}
}

#endif //AURORA_PPM_HPP_
