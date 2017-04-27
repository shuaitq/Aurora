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
        Texture(const std::string &path);
        // u = [0, 1) v = [0, 1)
        RGB_T<float> Sample(float u, float v) const;

        friend std::ostream& operator << (std::ostream &out, const Texture &texture);

        std::vector<RGB_T<float>> pixels;
        size_t size;
    private:
        using UV = PPM;
    };
}

#endif //AURORA_TEXTURE_HPP_
