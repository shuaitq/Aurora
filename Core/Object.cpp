#include "Object.hpp"

namespace Aurora
{
    Object::Object(const std::string &path)
    {
        Model::Load(path, *this);
    }
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
}