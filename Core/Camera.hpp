#ifndef AURORA_CAMERA_HPP_
#define AURORA_CAMERA_HPP_

#include "../Math/Math.hpp"

namespace Aurora
{
	class Camera
	{
	public:
		
	private:
		float fov_;
		float aspect_;
		Point4D_T<float> position_;
		Point4D_T<float> up_;
		Point4D_T<float> front_;
		Point4D_T<float> right_;
	}
}

#endif //AURORA_CAMERA_HPP_
