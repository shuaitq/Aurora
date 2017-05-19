#ifndef AURORA_SENCE_FILE_HPP_
#define AURORA_SENCE_FILE_HPP_

#include "json.hpp"

#include <fstream>
#include <memory>

namespace Aurora
{
    class SenceFile
    {
    public:
        static void Load(const std::string &path);
    private:
    };
}

#endif // AURORA_SENCE_FILE_HPP_