#ifndef AURORA_RENDER_HPP_
#define AURORA_RENDER_HPP_

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
    class Render
    {
    public:
        Render(const std::string &path);

        friend std::ostream& operator << (std::ostream &out, const Render &render);
    private:
        using Loader = SenceFile;
        int width, height;
        Camera camera;
        Sence sence;

    };
}

#endif //AURORA_RENDER_HPP_