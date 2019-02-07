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
    RGB_T<double> Texture::Sample(double u, double v) const
    {
        if(pixels.empty())
        {
            return RGB_T<double>(0.9);
        }
        // (-inf, +inf)
        u *= size;
        v *= size;
        // (-inf * size, +inf * size)
        auto f = [&](double a, double b)
        {
            int x = floor(u + a);
            int y = floor(v + b);
            x = ((x % size) + size) % size;
            y = ((y % size) + size) % size;
            return pixels[size * y + x] * fabs((u + a) - floor(u + 0.5)) * fabs((v + b) - floor(v + 0.5));
        };
        RGB_T<double> ret = f(0.5, 0.5);
        ret += f(0.5, -0.5);
        ret += f(-0.5, 0.5);
        ret += f(-0.5, -0.5);
        return ret;
    }
}