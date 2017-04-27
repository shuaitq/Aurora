#include "Object.hpp"

namespace Aurora
{
    Object::Object():position(), up(), front(), right(){}
    Object::Object(Point4D_T<float> p, Vector4D_T<float> u, Vector4D_T<float> f, Vector4D_T<float> r):position(p), up(u), front(f), right(r){}
    Object& Object::operator = (const Object &object)
    {
        position = object.position;
        up = object.up;
        front = object.front;
        right = object.right;
        triangle = object.triangle;
        texture = object.texture;
        return *this;
    }
    void Object::Load(const std::string &path)
    {
        Model::Load(path, *this);
    }
}