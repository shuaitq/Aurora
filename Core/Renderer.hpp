#ifndef AURORA_RENDERER_HPP_
#define AURORA_RENDERER_HPP_

#include "Camera.hpp"
#include "Color.hpp"
#include "../Math/Math.hpp"
#include "Light.hpp"

#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

namespace Aurora
{
    class Renderer
    {
    public:
        Renderer(const std::string &path);
        void DrawTopTriangle(Vertex &top, Vertex &left, Vertex &right, Texture<> &texture);
        void DrawBottomTriangle(Vertex &bottom, Vertex &left, Vertex &right, Texture<> &texture);

        void Render(const std::string &path);

        friend std::ostream& operator << (std::ostream &out, const Renderer &r);
    private:
        using Sence = SenceFile;
        std::vector<float> ZBuffer_;
        std::vector<RGB_T<float>> screen_;
        float ZFlag_;
    };
}

#endif //AURORA_RENDERER_HPP_