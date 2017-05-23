#include "Texture.hpp"

namespace Aurora
{
    Texture::Texture():pixels(), size(){}
    void Texture::Load(const std::string &path)
    {
        size_t width, height;
        UV::Load(path, width, height, pixels);
        if(width != height)
        {
            throw std::runtime_error("Texture width not equals to height");
        }
        size = height;
    }
    // u = [0, 1) v = [0, 1)
    RGBA_T<float> Texture::Sample(float u, float v) const
    {
        u = std::max(0.0f, std::min(1.0f, u));
        v = std::max(0.0f, std::min(1.0f, v));
        int i = u * (size - 1), j = v * (size - 1);
        float x = u * (size  - 1) - i, y = v * (size - 1) - j;
        return pixels[j * size + i] * (1 - x) * (1 - y) + pixels[(j+1) * size + i] * y * (1 - x) + pixels[j * size + (i + 1)] * (1 - y) * x + pixels[(j + 1) * size + (i + 1)] * y * x;
    }
}