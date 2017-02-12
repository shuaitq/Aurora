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
			return PPM::Load(path, size_, texture_);
		}
		bool Save(const char *path)
		{
			return PPM::Save(path, texture_, size_, size_);
		}
	private:
		std::vector<RGB_T<float>> texture_;
		size_t size_;
	};
}

#endif //AURORA_TEXTURE_HPP_
