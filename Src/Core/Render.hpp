#ifndef AURORA_RENDER_HPP_
#define AURORA_RENDER_HPP_

#include "Color.hpp"
#include "../Math/Math.hpp"
#include "../Utility/SenceFile.hpp"

#include <string>
#include <vector>
#include <algorithm>

namespace Aurora
{
    class Render
    {
    public:
        Render(const std::string &path);

        std::vector<RGB_T<float>>& Work(const std::string &path);
    private:
        bool IsBackFace(const Vertex &v1, const Vertex &v2, const Vertex &v3);
        void FillFace(const Vertex &v1, const Vertex &v2, const Vertex &v3, const Texture &texture);

        using Loader = SenceFile;
        std::vector<RGB_T<float>> screen;
        std::vector<float> depth;
    };
}

#endif //AURORA_RENDER_HPP_