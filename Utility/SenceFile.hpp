#ifndef AURORA_SENCE_FILE_HPP_
#define AURORA_SENCE_FILE_HPP_

#include "../Core/Object.hpp"
#include "../Core/Camera.hpp"

#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>

namespace Aurora
{
	class SenceFile
	{
	public:
		static void Load(const std::string &path, size_t &width, size_t &height, Camera &camera, std::vector<Object<>> &object);
	};
}

#endif //AURORA_SENCE_FILE_HPP_
