#ifndef AURORA_PPM_HPP_
#define AURORA_PPM_HPP_

#include "../Core/Color.hpp"

#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include <stdexcept>
#include <sstream>

namespace Aurora
{
    class PPM
    {
    public:
        static void Load(const std::string &path, Texture &texture);

        static void Save(const std::string &path, Texture &texture);
    private:
    };
}

#endif //AURORA_PPM_HPP_
