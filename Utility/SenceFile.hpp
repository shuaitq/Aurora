#ifndef AURORA_SENCEFILE_HPP_
#define AURORA_SENCEFILE_HPP_

#include "json.hpp"

#include <fstream>

class Sence;

namespace Aurora
{
    class SenceFile
    {
    public:
        static void Load(const std::string &path, Sence &sence);
    private:
    };
}

#endif // AURORA_SENCEFILE_HPP_