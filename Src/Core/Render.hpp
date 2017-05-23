#ifndef AURORA_RENDER_HPP_
#define AURORA_RENDER_HPP_

#include "Color.hpp"
#include "../Math/Math.hpp"
#include "../Utility/SenceFile.hpp"

#include <string>
#include <vector>

namespace Aurora
{
    class Render
    {
    public:
        Render(const std::string &path);

        std::vector<RGBA_T<float>>& Work(const std::string &path);
    private:
        using Loader = SenceFile;
        std::vector<RGBA_T<float>> screen;
        std::vector<float> depth;
    };
}

#endif //AURORA_RENDER_HPP_