#ifndef AURORA_SENCE_FILE_HPP_
#define AURORA_SENCE_FILE_HPP_

#include "../Core/Object.hpp"

#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>

namespace Aurora
{
	namespace SenceFile
	{
		void Load(const string &path, std::vector<Object> &object);
	}
}

#endif //AURORA_SENCE_FILE_HPP_
