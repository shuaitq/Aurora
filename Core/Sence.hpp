#ifndef AURORA_SENCE_HPP_
#define AURORA_SENCE_HPP_

namespace Aurora
{
    class Sence
    {
    public:
        Sence(const std::string &path);

        friend std::ostream& operator << (std::ostream &out, const Sence &sence) const;

        int width, height;
        Camera camera;
        std::vector<Object> object;
        std::vector<Light *> light;
    private:
        using Loader = SenceFile;
    };
}

#endif // AURORA_SENCE_HPP_