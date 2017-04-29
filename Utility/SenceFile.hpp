#ifndef AURORA_SENCEFILE_HPP_
#define AURORA_SENCEFILE_HPP_

#include "json.hpp"
#include "../Core/Sence.hpp"
#include "../Light/DirectLight.hpp"
#include "../Light/PointLight.hpp"
#include "../Core/Object.hpp"

#include <fstream>
#include <memory>

namespace Aurora
{
    class Sence;

    class SenceFile
    {
    public:
        static void Load(const std::string &path, Sence &sence);
    private:
    };
}

#endif // AURORA_SENCEFILE_HPP_