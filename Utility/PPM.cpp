#include "PPM.hpp"

namespace Aurora
{
	namespace PPM
	{
		bool Load(const char *path, size_t &size, std::vector<RGB_T<float>> &ppm)
		{
			FILE *fp = fopen(path, "r");
			if(fp == nullptr)
			{
				return false;
			}
			size_t width;
			size_t height;
			fscanf(fp, "P3\n%zu%zu\n255\n", &width, &height);
			if(width != height)
			{
				return false;
			}
			size = width;
			int red, green, blue;
			for(size_t i = 0; i < height * width; ++ i)
			{
				fscanf(fp, "%d %d %d ", &red, &green, &blue);
				ppm.push_back(RGB_T<float>(red / 255.0, green / 255.0, blue / 255.0));
			}
			return true;
		}
		bool Save(const char *path,const std::vector<RGB_T<float>> &ppm, const size_t width, const size_t height)
		{
			FILE *fp = fopen(path, "w");
			if(fp == nullptr)
			{
				return false;
			}
			fprintf(fp, "P3\n%zu %zu\n255\n", width, height);
			for(auto it = ppm.begin(); it != ppm.end(); ++ it)
			{
				fprintf(fp, "%d %d %d ", (int)(*it).red()*255, (int)(*it).green()*255, (int)(*it).blue()*255);
			}
			fclose(fp);
			return true;
		}
	}
}
