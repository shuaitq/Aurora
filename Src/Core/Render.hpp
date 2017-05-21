#ifndef AURORA_RENDER_HPP_
#define AURORA_RENDER_HPP_

namespace Aurora
{
    class Render
    {
    public:
        Render(const std::string &path);

        std::vector<RGB_T<float>>& Work();
    private:
        using Loader = SenceFile;
        std::vector<RGBA_T<float>> screen;
        std::vector<float> depth;
    };
}

#endif //AURORA_RENDER_HPP_