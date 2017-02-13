#ifndef AURORA_OBJECT_FILE_HPP_
#define AURORA_OBJECT_FILE_HPP_

#include "../Math/Math.hpp"
#include "../Core/Vertex.hpp"

#include <cstdio>
#include <vector>

namespace Aurora
{
	namespace ObjectFile
	{
		bool Load(const char *path, std::vector<Vertex> &vertex, std::vector<Triangle> &triangle, Texture texture);
	}
}

#endif //AURORA_OBJECT_FILE_HPP_
