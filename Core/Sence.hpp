#ifndef AURORA_SENCE_HPP_
#define AURORA_SENCE_HPP_

namespace Aurora
{
    class Sence
    {
    public:
        void Load(const std::string &path);
    private:
		int width_, height_;
		Camera camera_;
		std::vector<Object<>> object_;
		std::vector<Light*> light_;
    };
}

#endif // AURORA_SENCE_HPP_