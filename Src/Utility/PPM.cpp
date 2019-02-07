#include "PPM.hpp"

#include <fstream>
#include <sstream>
#include <limits>
#include <stdexcept>

namespace Aurora
{
    void PPM::Load(const std::string &path, size_t &width, size_t &height, std::vector<RGB_T<double>> &ppm)
    {
        std::ifstream in(path);
        std::string line;
        double max;

        if(!in.is_open())
        {
            throw std::runtime_error("PPM file " + path + " can't open!");
        }

        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        in >> width >> height;
        in >> max;

        int red, green, blue;
        for(size_t i = 0; i < height * width; ++ i)
        {
            in >> red >> green >> blue;
            ppm.push_back(RGB_T<double>(red / max, green / max, blue / max));
        }
        in.close();
    }
    void PPM::Save(const std::string &path, const size_t width, const size_t height, const std::vector<RGB_T<double>> &ppm)
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