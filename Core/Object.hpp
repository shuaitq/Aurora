#ifndef AURORA_OBJECT_HPP_
#define AURORA_OBJECT_HPP_

#include "Texture.hpp"
#include "Triangle.hpp"
#include "../Utility/ObjectFile.hpp"

#include <vector>

namespace Aurora
{
	class Object
	{
	public:
		Object() = default;
		bool Load(const char *path)
		{
			return ObjectFile::Load(path, triangle_);
		}
	private:
		std::vector<Triangle> triangle_;
		Texture texture_;
	};
}

#endif //AURORA_OBJECT_HPP_
