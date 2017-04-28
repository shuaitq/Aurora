#ifndef AURORA_OBJECT_HPP_
#define AURORA_OBJECT_HPP_

#include "Texture.hpp"
#include "Triangle.hpp"
#include "../Utility/ObjectFile.hpp"

#include <vector>
#include <string>
#include <iostream>

namespace Aurora
{
    class ObjectFile;

    class Object
    {
    public:
        Object(const std::string &path);
        Object(const Object &object);
        Object& operator = (const Object &object);
        Object& operator *= (const Matrix4_T<float> &m);
        void ObjectToWorld();

        friend std::ostream& operator << (std::ostream &out, const Object &object);

        Point4D_T<float> position;
        Vector4D_T<float> up;
        Vector4D_T<float> front;
        Vector4D_T<float> right;
        std::vector<Triangle> triangle;
        Texture texture;
    private:
        using Model = ObjectFile;
    };
}

#endif //AURORA_OBJECT_HPP_
