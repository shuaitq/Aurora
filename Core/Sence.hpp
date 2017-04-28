#ifndef AURORA_SENCE_HPP_
#define AURORA_SENCE_HPP_

#include "Camera.hpp"
#include "Object.hpp"
#include "Light.hpp"
#include "../Utility/SenceFile.hpp"

#include <vector>
#include <string>
#include <iostream>

namespace Aurora
{
    class SenceFile;

    class Sence
    {
    public:
        Sence(const std::string &path);

        friend std::ostream& operator << (std::ostream &out, const Sence &sence);

        int width, height;
        Camera camera;
        std::vector<Object> object;
        std::vector<Light *> light;
    private:
        using Loader = SenceFile;
    };
}

#endif // AURORA_SENCE_HPP_