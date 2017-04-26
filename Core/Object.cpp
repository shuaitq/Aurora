#include "Object.hpp"

namespace Aurora
{
    Object::Object() = default;
    Object::Object(Point4D_T<float> position, Vector4D_T<float> up, Vector4D_T<float> front, Vector4D_T<float> right):position_(position), up_(up), front_(front), right_(right){}
    Object& Object::operator = (const Object &object)
    {
        position_ = object.position_;
        up_ = object.up_;
        front_ = object.front_;
        right_ = object.right_;
        triangle_ = object.triangle_;
        vertex_ = object.vertex_;
        texture_ = object.texture_;
        return *this;
    }
    void Object::Load(const std::string &path)
    {
        Model::Load(path, vertex_, triangle_, texture_);
    }
    void Object::RotateX(const float angle)
    {
        Matrix4_T<float> m(1, 0, 0, 0,
                0, cos(angle), sin(angle), 0,
                0, -sin(angle), cos(angle), 0,
                0, 0, 0, 1);
        for(auto &vertex : vertex_)
        {
            vertex.point() *= m;
            vertex.normal() *= m;
        }
    }
    void Object::RotateY(const float angle)
    {
        Matrix4_T<float> m(cos(angle), 0, -sin(angle), 0,
                0, 1, 0, 0,
                sin(angle), 0, cos(angle), 0,
                0, 0, 0, 1);
        for(auto &vertex : vertex_)
        {
            vertex.point() *= m;
            vertex.normal() *= m;
        }
    }
    void Object::RotateZ(const float angle)
    {
        Matrix4_T<float> m(cos(angle), sin(angle), 0, 0,
                -sin(angle), cos(angle), 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1);
        for(auto &vertex : vertex_)
        {
            vertex.point() *= m;
            vertex.normal() *= m;
        }
    }

    std::vector<Triangle>& Object::triangle()
    {
        return triangle_;
    }
    const std::vector<Triangle>& Object::triangle() const
    {
        return triangle_;
    }
    std::vector<Vertex>& Object::vertex()
    {
        return vertex_;
    }
    const std::vector<Vertex>& Object::vertex() const
    {
        return vertex_;
    }
    Texture<>& Object::texture()
    {
        return texture_;
    }
    const Texture<>& Object::texture() const
    {
        return texture_;
    }
    Point4D_T<float>& Object::position()
    {
        return position_;
    }
    const Point4D_T<float>& Object::position() const
    {
        return position_;
    }
    Vector4D_T<float>& Object::up()
    {
        return up_;
    }
    const Vector4D_T<float>& Object::up() const
    {
        return up_;
    }
    Vector4D_T<float>& Object::front()
    {
        return front_;
    }
    const Vector4D_T<float>& Object::front() const
    {
        return front_;
    }
    Vector4D_T<float>& Object::right()
    {
        return right_;
    }
    const Vector4D_T<float>& Object::right() const
    {
        return right_;
    }

    std::ostream& operator << (std::ostream &out, const Object &object)
    {
        out << "# Object" << std::endl;
        out << "# position" << std::endl;
        out << object.position();
        out << "# up" << std::endl;
        out << object.up();
        out << "# front" << std::endl;
        out << object.front();
        out << "# right" << std::endl;
        out << object.right();
        out << "# triangle" << std::endl;
        for(auto it = object.triangle().begin(); it != object.triangle().end(); ++ it)
        {
            out << *it;
        }
        return out;
    }
    std::istream& operator >> (std::istream &in, Object &object)
    {
        in >> object.position() >> object.up() >> object.front() >> object.right();
        return in;
    }
}