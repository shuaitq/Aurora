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
		// u = [0, 1) v = [0, 1)
		RGB_T<float> Sample(float u, float v) const
		{
			if(u > 1)
			{
				u = 1;
			}
			if(u < 0)
			{
				u = 0;
			}
			if(v > 1)
			{
				v = 1;
			}
			if(v < 0)
			{
				v = 0;
			}
			int i = u * (size_ - 1), j = v * (size_ - 1);
			float x = u * (size_  - 1) - i, y = v * (size_ - 1) - j;
			return texture_[j * size_ + i] * (1 - x) * (1 - y) + texture_[(j+1) * size_ + i] * y * (1 - x) + texture_[j * size_ + (i + 1)] * (1 - y) * x + texture_[(j + 1) * size_ + (i + 1)] * y * x;
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
