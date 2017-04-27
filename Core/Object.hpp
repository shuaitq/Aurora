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
    class Object
    {
    public:
        Object();
        Object(Point4D_T<float> p, Vector4D_T<float> u, Vector4D_T<float> f, Vector4D_T<float> r);
        Object& operator = (const Object &object);
        void Load(const std::string &path);

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
