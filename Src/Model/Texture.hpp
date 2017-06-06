#ifndef AURORA_TEXTURE_HPP_
#define AURORA_TEXTURE_HPP_

#include "../Utility/PPM.hpp"

#include <cmath>

namespace Aurora
{
    class Texture
    {
    public:
        Texture();
        void Load(const std::string &path);
        RGB_T<float> Sample(float u, float v) const;

    private:
        using UV = PPM;

        std::vector<RGB_T<float>> pixels;
        size_t size;
    };
}

#endif //AURORA_TEXTURE_HPP_
