#ifndef AURORA_RENDER_HPP_
#define AURORA_RENDER_HPP_

#include "Color.hpp"
#include "../Math/Math.hpp"
#include "../Utility/SenceFile.hpp"
#include "../Utility/PPM.hpp"

#include <string>
#include <vector>
#include <algorithm>
#include <array>

namespace Aurora
{
    class Render
    {
    public:
        Render(const std::string &path);

        void Work(const std::string &path);
    private:
        class RenderVertex
        {
        public:
            RenderVertex();

            Vector4D_T<float> point;
            Vector4D_T<float> view;
            Vector4D_T<float> normal;
            Vector2D_T<float> uv;
        };

        bool IsBackFace(const Vector4D_T<float> &v1, const Vector4D_T<float> &v2, const Vector4D_T<float> &v3);
        void FillFace(const RenderVertex &v1, const RenderVertex &v2, const RenderVertex &v3, const Texture &texture);

        using Loader = SenceFile;
        using Saver = PPM;
        std::vector<RGB_T<float>> screen;
        std::vector<float> depth;
    };
}

#endif //AURORA_RENDER_HPP_