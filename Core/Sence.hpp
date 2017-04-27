#ifndef AURORA_SENCE_HPP_
#define AURORA_SENCE_HPP_

namespace Aurora
{
    class Sence
    {
    public:
        Sence(const std::string &path);
        int& width();
        const int& width() const;
        int& height();
        const int& height() const;
        Camera& camera();
        const Camera& camera() const;
        std::vector<Object>& object();
        const std::vector<Object>& object() const;
        std::vector<Light *>& light();
        const std::vector<Light *>& light() const;
    private:
        using Loader = SenceFile;
		int width_, height_;
		Camera camera_;
		std::vector<Object> object_;
		std::vector<Light *> light_;
    };
}

#endif // AURORA_SENCE_HPP_