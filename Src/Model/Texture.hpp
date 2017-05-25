#ifndef AURORA_TEXTURE_HPP_
#define AURORA_TEXTURE_HPP_

#include "../Utility/PPM.hpp"

#include <algorithm>

namespace Aurora
{
    class Texture
    {
    public:
        Texture();
        void Load(const std::string &path);
        // u = [0, 1) v = [0, 1)
        RGB_T<float> Sample(float u, float v) const;

        std::vector<RGB_T<float>> pixels;
        size_t size;
    private:
        using UV = PPM;
    };
}

#endif //AURORA_TEXTURE_HPP_