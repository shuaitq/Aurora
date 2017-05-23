#ifndef AURORA_SENCE_FILE_HPP_
#define AURORA_SENCE_FILE_HPP_

#include "json.hpp"
#include "../Core/Camera.hpp"
#include "../Model/Model.hpp"
#include "../Light/Light.hpp"
#include "../Light/DirectLight.hpp"
#include "../Light/PointLight.hpp"

#include <fstream>
#include <memory>
#include <string>

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