#include "Texture.hpp"

namespace Aurora
{
    Texture::Texture(const std::string &path)
    {
        UV::Load(path, *this);
    }
    // u = [0, 1) v = [0, 1)
    RGB_T<float> Texture::Sample(float u, float v) const
    {
        if(u > 1)
        {
            u = 1;
        }
        if(u < 0)
        {
            u = 0;
        }
        if(v > 1)
        {
            v = 1;
        }
        if(v < 0)
        {
            v = 0;
        }
        int i = u * (size_ - 1), j = v * (size_ - 1);
        float x = u * (size_  - 1) - i, y = v * (size_ - 1) - j;
        return texture_[j * size_ + i] * (1 - x) * (1 - y) + texture_[(j+1) * size_ + i] * y * (1 - x) + texture_[j * size_ + (i + 1)] * (1 - y) * x + texture_[(j + 1) * size_ + (i + 1)] * y * x;
    }

    std::ostream& operator << (std::ostream &out, const Texture &texture)
    {
        out << "Size" << std::endl;
        out << size;
        return out;
    }
}