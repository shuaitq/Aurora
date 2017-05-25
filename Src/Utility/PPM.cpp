#include "PPM.hpp"

namespace Aurora
{
    void PPM::Load(const std::string &path, size_t &width, size_t &height, std::vector<RGB_T<float>> &ppm)
    {
        std::ifstream in(path);
        if(!in.is_open())
        {
            throw std::runtime_error("PPM file " + path + " doesnt't exist!");
        }
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        in >> width >> height;
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        int red, green, blue;
        for(size_t i = 0; i < height * width; ++ i)
        {
            in >> red >> green >> blue;
            ppm.push_back(RGBA_T<float>(red / 255.0, green / 255.0, blue / 255.0));
        }
        in.close();
    }
    void PPM::Save(const std::string &path, const size_t width, const size_t height, const std::vector<RGB_T<float>> &ppm)
    {
        std::ofstream in(path);
        if(!in.is_open())
        {
            throw std::runtime_error("Can't open file " + path);
        }
        in << "P3" << std::endl << width << ' ' << height << std::endl << "255" << std::endl;
        for(auto it = ppm.begin(); it != ppm.end(); ++ it)
        {
            in << (int)(it->red*255) << ' ' << (int)(it->green*255) << ' ' << (int)(it->blue*255) << ' ';
        }
        in.close();
    }
}