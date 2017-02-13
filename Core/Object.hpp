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

		Triangle& operator[](size_t index)
		{
			return triangle_[index];
		}
		const Triangle& operator[](size_t index) const
		{
			return triangle_[index];
		}
		void push_back(const Triangle &triangle)
		{
			triangle_.push_back(triangle);
		}

		bool Load(const char *path)
		{
			return ObjectFile::Load(path, triangle_, triangle_, texture_);
		}
	private:
		std::vector<Triangle> triangle_;
		Texture texture_;
	};
}

#endif //AURORA_OBJECT_HPP_
