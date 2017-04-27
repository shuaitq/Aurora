#include "Camera.hpp"

namespace Aurora
{
    Point4D_T<float>& Camera::position()
    {
        return position_;
    }
    const Point4D_T<float>& Camera::position() const
    {
        return position_;
    }
    Vector4D_T<float>& Camera::up()
    {
        return up_;
    }
    const Vector4D_T<float>& Camera::up() const
    {
        return up_;
    }
    Vector4D_T<float>& Camera::front()
    {
        return front_;
    }
    const Vector4D_T<float>& Camera::front() const
    {
        return front_;
    }
    Vector4D_T<float>& Camera::right()
    {
        return right_;
    }
    const Vector4D_T<float>& Camera::right() const
    {
        return right_;
    }
    float& Camera::fov()
    {
        return fov_;
    }
    const float& Camera::fov() const
    {
        return fov_;
    }
    float& Camera::aspect()
    {
        return aspect_;
    }
    const float& Camera::aspect() const
    {
        return aspect_;
    }

    std::ostream& operator << (std::ostream &out, const Camera &camera)
    {
        out << "# Camera" << std::endl;
        out << "# position" << std::endl;
        out << camera.position() << std::endl;
        out << "# up" << std::endl;
        out << camera.up() << std::endl;
        out << "# front" << std::endl;
        out << camera.front() << std::endl;
        out << "# right" << std::endl;
        out << camera.right() << std::endl;
        out << "# fov" << std::endl;
        out << camera.fov() << std::endl;
        out << "# aspect" << std::endl;
        out << camera.aspect();
        return out;
    }
    std::istream& operator >> (std::istream &in, Camera &camera)
    {
        in >> camera.position() >> camera.up() >> camera.front() >> camera.right() >> camera.fov();
        return in;
    }
}