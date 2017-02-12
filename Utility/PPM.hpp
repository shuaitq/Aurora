#ifndef AURORA_PPM_HPP_
#define AURORA_PPM_HPP_

#include "../Core/Color.hpp"

#include <cstdio>
#include <vector>

namespace Aurora
{
	namespace PPM
	{
		bool Load(const char *path, size_t &size, std::vector<RGB_T<float>> &ppm);

		bool Save(const char *path,const std::vector<RGB_T<float>> &ppm, const size_t width, const size_t height);
	}
}

#endif //AURORA_PPM_HPP_
