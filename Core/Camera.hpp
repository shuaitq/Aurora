#ifndef AURORA_CAMERA_HPP_
#define AURORA_CAMERA_HPP_

#include "../Math/Math.hpp"

#include <iostream>

namespace Aurora
{
	class Camera
	{
	public:	
		Matrix4_T<float>& MakeMatrix()
		{
			float PdotR = position_.x() * right_.x() + position_.y() * right_.y() + position_.z() * right_.z();
			float PdotU = position_.x() * up_.x() + position_.y() * up_.y() + position_.z() * up_.z();
			float PdotF = position_.x() * front_.x() + position_.y() * front_.y() + position_.z() * front_.z();
			WorldToCamera_ = Matrix4_T<float>(
							right_.x(), up_.x(), front_.x(), 0,
							right_.y(), up_.y(), front_.y(), 0,
							right_.z(), up_.z(), front_.z(), 0,
							-PdotR, -PdotU, -PdotF, 1
							);
			return WorldToCamera_;
		}

		Point4D_T<float>& position()
		{
			return position_;
		}
		const Point4D_T<float>& position() const
		{
			return position_;
		}
		Vector4D_T<float>& up()
		{
			return up_;
		}
		const Vector4D_T<float>& up() const
		{
			return up_;
		}
		Vector4D_T<float>& front()
		{
			return front_;
		}
		const Vector4D_T<float>& front() const
		{
			return front_;
		}
		Vector4D_T<float>& right()
		{
			return right_;
		}
		const Vector4D_T<float>& right() const
		{
			return right_;
		}
		Matrix4_T<float>& WorldToCamera()
		{
			return WorldToCamera_;
		}
		const Matrix4_T<float>& WorldToCamera() const
		{
			return WorldToCamera_;
		}
		float& fov()
		{
			return fov_;
		}
		const float& fov() const
		{
			return fov_;
		}
		float& aspect()
		{
			return aspect_;
		}
		const float& aspect() const
		{
			return aspect_;
		}

		friend std::ostream& operator << (std::ostream &out, const Camera &camera)
		{
			out << "# Camera" << std::endl;
			out << "# position" <<std::endl;
			out << camera.position();
			out << "# up" << std::endl;
			out << camera.up();
			out << "# front" << std::endl;
			out << camera.front();
			out << "# right" << std::endl;
			out << camera.right();
			out << "# fov" << std::endl;
			out << camera.fov() << std::endl;
			out << "# aspect" << std::endl;
			out << camera.aspect() << std::endl;
			return out;
		}
		friend std::istream& operator >> (std::istream &in, Camera &camera)
		{
			in >> camera.position() >> camera.up() >> camera.front() >> camera.right() >> camera.fov();
			return in;
		}
	private:
		Point4D_T<float> position_;
		Vector4D_T<float> up_;
		Vector4D_T<float> front_;
		Vector4D_T<float> right_;
		Matrix4_T<float> WorldToCamera_;
		float fov_;
		float aspect_;
	};
}

#endif //AURORA_CAMERA_HPP_
