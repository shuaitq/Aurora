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
    class Sence
    {
    public:
        friend std::ostream& operator << (std::ostream &out, const Sence &sence);

        std::vector<std::shared_ptr<Object>> object;
        std::vector<std::shared_ptr<Light>> light;
        Camera camera;
        int width, height;
    private:
    };
}

#endif // AURORA_SENCE_HPP_