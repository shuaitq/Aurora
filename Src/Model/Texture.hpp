#ifndef AURORA_TEXTURE_HPP_
#define AURORA_TEXTURE_HPP_

#include "../Core/Color.hpp"

#include <string>
#include <vector>

namespace Aurora
{
    class Texture
    {
    public:
        Texture();
        void Load(const std::string &path);
        RGB_T<double> Sample(double u, double v) const;

    private:
        std::vector<RGB_T<double>> pixels;
        size_t size;
    };
}

#endif //AURORA_TEXTURE_HPP_
