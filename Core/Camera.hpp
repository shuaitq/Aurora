#ifndef AURORA_CAMERA_HPP_
#define AURORA_CAMERA_HPP_

#include "../Math/Math.hpp"

#include <iostream>

namespace Aurora
{
	class Camera
	{
	public:
		Point4D_T<float>& position();
		const Point4D_T<float>& position() const;
		Vector4D_T<float>& up();
		const Vector4D_T<float>& up() const;
		Vector4D_T<float>& front();
		const Vector4D_T<float>& front() const;
		Vector4D_T<float>& right();
		const Vector4D_T<float>& right() const;
		float& fov();
		const float& fov() const;
		float& aspect();
		const float& aspect() const;
	private:
		Point4D_T<float> position_;
		Vector4D_T<float> up_;
		Vector4D_T<float> front_;
		Vector4D_T<float> right_;
		float fov_;
		float aspect_;
	};
	std::ostream& operator << (std::ostream &out, const Camera &camera);
	std::istream& operator >> (std::istream &in, Camera &camera);
}

#endif //AURORA_CAMERA_HPP_
