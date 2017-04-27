#ifndef AURORA_OBJECT_HPP_
#define AURORA_OBJECT_HPP_

#include "Texture.hpp"
#include "Triangle.hpp"
#include "../Utility/ObjectFile.hpp"

#include <vector>
#include <string>
#include <iostream>

namespace Aurora
{
	class Object
	{
	public:
		Object();
		Object(Point4D_T<float> position, Vector4D_T<float> up, Vector4D_T<float> front, Vector4D_T<float> right);
		Object& operator = (const Object &object);
		void Load(const std::string &path);

		std::vector<Triangle>& triangle();
		const std::vector<Triangle>& triangle() const;
		Texture& texture();
		const Texture& texture() const;
		Point4D_T<float>& position();
		const Point4D_T<float>& position() const;
		Vector4D_T<float>& up();
		const Vector4D_T<float>& up() const;
		Vector4D_T<float>& front();
		const Vector4D_T<float>& front() const;
		Vector4D_T<float>& right();
		const Vector4D_T<float>& right() const;
		friend std::ostream& operator << (std::ostream &out, const Object &object);
		friend std::istream& operator >> (std::istream &in, Object &object);
	private:
		using Model = ObjectFile;
		Point4D_T<float> position_;
		Vector4D_T<float> up_;
		Vector4D_T<float> front_;
		Vector4D_T<float> right_;
		std::vector<Triangle> triangle_;
		Texture texture_;
	};
}

#endif //AURORA_OBJECT_HPP_
