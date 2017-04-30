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
        void Load(const std::string &path);

        friend std::ostream& operator << (std::ostream &out, const Object &object);

        Point3D_T<float> position;
        float rotatex, rotatey, rotatez;
        std::vector<Triangle> triangle;
        Texture texture;
    private:
        using Model = ObjectFile;
    };
}

#endif //AURORA_OBJECT_HPP_
