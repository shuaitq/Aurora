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
#include <cstdlib>

namespace Aurora
{
    class Renderer
    {
    public:
        Renderer(const std::string &path);

        void Render(const std::string &path);

        friend std::ostream& operator << (std::ostream &out, const Renderer &renderer);

    private:
        using Loader = SenceFile;
        void ObjectToWorld();
        void WorldToCamera();
        void CameraToCVV();
        void Clip();
        void CVVToScreen();
        void Rasterization();
        void Init();

        Sence sence, render_sence;
    };
}

#endif //AURORA_RENDERER_HPP_