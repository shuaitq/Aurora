#ifndef AURORA_RENDERER_HPP_
#define AURORA_RENDERER_HPP_

#include "Camera.hpp"
#include "Color.hpp"

namespace Aurora
{
	class Renderer
	{
	public:

	private:
		Camera *camera_;
		RGB<float> *screen_;
		vector<float> ZBuffer;
		size_t width;
		size_t height;
	}
}

#endif //AURORA_RENDERER_HPP_
