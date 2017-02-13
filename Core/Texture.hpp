#ifndef AURORA_TEXTURE_HPP_
#define AURORA_TEXTURE_HPP_

#include "Color.hpp"
#include "../Utility/PPM.hpp"

#include <vector>

namespace Aurora
{
	class Texture
	{
	public:
		bool Load(const char *path)
		{
			size_t width, height;
			if(PPM::Load(path, width, height, texture_))
			{
				if(width == height)
				{
					size_ = height;
					return true;
				}
			}
			return false;
		}
	private:
		std::vector<RGB_T<float>> texture_;
		size_t size_;
	};
}

#endif //AURORA_TEXTURE_HPP_
