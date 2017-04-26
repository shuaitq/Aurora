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
		RGB_T<float> Sample(float u, float v) const;
		void Load(const std::string &path);
	private:
		using UV = PPM;
		std::vector<RGB_T<float>> texture_;
		size_t size_;
	};
}

#endif //AURORA_TEXTURE_HPP_
