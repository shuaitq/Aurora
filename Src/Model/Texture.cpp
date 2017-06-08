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
    RGB_T<float> Texture::Sample(float u, float v) const
    {
        if(pixels.empty())
        {
            return RGB_T<float>(0.9f);
        }
        // (-inf, +inf)
        u *= size;
        v *= size;
        // (-inf * size, +inf * size)
        auto f = [&](float a, float b)
        {
            int x = floor(u + a);
            int y = floor(v + b);
            x = ((x % size) + size) % size;
            y = ((y % size) + size) % size;
            return pixels[size * y + x] * fabs((u + a) - floor(u + 0.5f)) * fabs((v + b) - floor(v + 0.5f));
        };
        RGB_T<float> ret = f(0.5f, 0.5f);
        ret += f(0.5f, -0.5f);
        ret += f(-0.5f, 0.5f);
        ret += f(-0.5f, -0.5f);
        return ret;
    }
}