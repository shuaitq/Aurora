#ifndef AURORA_PPM_HPP_
#define AURORA_PPM_HPP_

#include "../Core/Color.hpp"

#include <vector>
#include <string>
#include <fstream>
#include <limits>

namespace Aurora
{
	namespace PPM
	{
		void Load(const std::string &path, size_t &width, size_t &height, std::vector<RGB_T<float>> &ppm);

		void Save(const std::string &path, const size_t width, const size_t height, const std::vector<RGB_T<float>> &ppm);
	}
}

#endif //AURORA_PPM_HPP_
