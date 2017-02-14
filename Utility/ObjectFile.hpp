#ifndef AURORA_OBJECT_FILE_HPP_
#define AURORA_OBJECT_FILE_HPP_

#include "../Math/Math.hpp"
#include "../Core/Vertex.hpp"
#include "../Core/Triangle.hpp"
#include "../Core/Texture.hpp"

#include <vector>
#include <string>
#include <fstream>

namespace Aurora
{
	namespace ObjectFile
	{
		void Load(const std::string &path, std::vector<Vertex> &vertex, std::vector<Triangle> &triangle, Texture &texture);
	}
}

#endif //AURORA_OBJECT_FILE_HPP_
