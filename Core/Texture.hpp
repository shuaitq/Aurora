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
			int width = u / 1.0f * size_, height = v / 1.0f * size_;
			if(width < 0)
			{
				width = 0;
			}
			if(width >= size_)
			{
				width = size_ - 1;
			}
			if(height < 0)
			{
				height = 0;
			}
			if(height >= size_)
			{
				height = size_ - 1;
			}
			return texture_[height * size_ + width];
		}
		void Load(const std::string &path)
		{
			size_t width, height;
			PPM::Load(path, width, height, texture_);
			if(width != height)
			{
				throw std::runtime_error("Texture width not equals to height");
			}
			size_ = height;
		}
	private:
		std::vector<RGB_T<float>> texture_;
		size_t size_;
	};
}

#endif //AURORA_TEXTURE_HPP_
