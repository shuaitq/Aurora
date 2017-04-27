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
    std::ostream& operator << (std::ostream &out, const Object &object)
    {
        out << "Position" << std::endl;
        out << object.position << std::endl;
        out << "Up" << std::endl;
        out << object.up << std::endl;
        out << "Front" << std::endl;
        out << object.front << std::endl;
        out << "Right" << std::endl;
        out << object.right << std::endl;
        out << "Triangle" << std::endl;
        for(auto it = object.triangle.begin(); it != object.triangle.end(); ++ it)
        {
            out << *it << std::endl;
        }
        out << "Texture" << std::endl;
        out << object.texture; 
        return out;
    }
}