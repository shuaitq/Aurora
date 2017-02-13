#ifndef AURORA_OBJECT_HPP_
#define AURORA_OBJECT_HPP_

#include "Texture.hpp"
#include "Triangle.hpp"
#include "../Utility/ObjectFile.hpp"

#include <vector>
#include <string>

namespace Aurora
{
	class Object
	{
	public:
		Object() = default;
		Object(Point4D_T<float> position, Point4D_T<float> up, Point4D_T<float> front, Point4D_T<float> right):position_(position), up_(up), front_(front), right_(right){}
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

		void Load(const std::string &path)
		{
			ObjectFile::Load(path, vertex_, triangle_, texture_);
		}
	private:
		std::vector<Triangle> triangle_;
		std::vector<Vertex> vertex_;
		Texture texture_;
		Point4D_T<float> position_;
		Point4D_T<float> up_;
		Point4D_T<float> front_;
		Point4D_T<float> right_;
	};
}

#endif //AURORA_OBJECT_HPP_
