#ifndef AURORA_RENDERER_HPP_
#define AURORA_RENDERER_HPP_

#include "Camera.hpp"
#include "Color.hpp"
#include "Sence.hpp"

#include <memery>

namespace Aurora
{
	class Renderer
	{
	public:

	private:
		Camera camera_;
		std::shared_ptr<RGB<float>> screen_;
		vector<float> ZBuffer;
		Sence sence_;
		size_t width;
		size_t height;
	}
}

#endif //AURORA_RENDERER_HPP_
