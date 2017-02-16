#ifndef AURORA_TEXTURE_HPP_
#define AURORA_TEXTURE_HPP_

#include "Color.hpp"
#include "../Utility/PPM.hpp"

#include <vector>
#include <string>
#include <stdexcept>

namespace Aurora
{
	class Texture
	{
	public:
		RGB_T<float> Sample(float u, float v) const
		{
			return texture_[v / 1.0f * size_ * size_ + u / 1.0f * size_];
		}
		void Load(const std::string &path)
		{
			size_t width, height;
			PPM::Load(path, width, height, texture_);
			if(width != height)
			{
				throw std::runtime_error("Texture width not equal to height");
			}
			size_ = height;
		}
	private:
		std::vector<RGB_T<float>> texture_;
		size_t size_;
	};
}

#endif //AURORA_TEXTURE_HPP_
