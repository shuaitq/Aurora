#ifndef AURORA_PPM_HPP_
#define AURORA_PPM_HPP_

#include "../Core/Color.hpp"

#include <string>
#include <vector>
#include <fstream>
#include <limits>
#include <stdexcept>

namespace Aurora
{
    class PPM
    {
    public:
        static void Load(const std::string &path, size_t &width, size_t &height, std::vector<RGB_T<double>> &ppm);

        static void Save(const std::string &path, const size_t width, const size_t height, const std::vector<RGB_T<double>> &ppm);
    private:
    };
}

#endif //AURORA_PPM_HPP_
