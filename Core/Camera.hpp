#ifndef AURORA_CAMERA_HPP_
#define AURORA_CAMERA_HPP_

#include "../Math/Math.hpp"

#include <iostream>

namespace Aurora
{
	class Camera
	{
	public:
		friend std::ostream& operator << (std::ostream &out, const Camera &camera)
		{
			out << "# Camera" << std::endl;
			out << position_ << up_ << front_ << right_;
			out << fov_;
			return out;
		}
		friend std::istream& operator >> (std::istream &in, Camera camera)
		{
			in >> position_ >> up_ >> front_ >> right_ >> fov_;
			return in;
		}
	private:
		Point4D_T<float> position_;
		Point4D_T<float> up_;
		Point4D_T<float> front_;
		Point4D_T<float> right_;
		float fov_;
		float aspect_;

	}
}

#endif //AURORA_CAMERA_HPP_
