#ifndef AURORA_RENDERER_HPP_
#define AURORA_RENDERER_HPP_

#include "Camera.hpp"
#include "Color.hpp"
#include "../Math/Math.hpp"
#include "Light.hpp"
#include "../Utility/SenceFile.hpp"

#include <memory>
#include <vector>
#include <string>
#include <algorithm>

namespace Aurora
{
    class Renderer
    {
    public:
        Renderer(const std::string &path);

        friend std::ostream& operator << (std::ostream &out, const Renderer &renderer);
    private:
        using Loader = SenceFile;
        Sence sence;
    };
}

#endif //AURORA_RENDERER_HPP_