#include "ObjectFile.hpp"

namespace Aurora
{
    void ObjectFile::Load(const std::string &path, std::vector<Vector4D_T<float>> &point, std::vector<Vector4D_T<float>> &normal, std::vector<Vector2D_T<float>> &uv, std::vector<Face> &face, Texture &texture)
    {
        std::ifstream in(path);
        if(!in.is_open())
        {
            throw std::runtime_error("Object " + path + " doesn't exist!");
        }
        std::string str;
        float x, y, z;
        Face temp;
        while(in >> str)
        {
            switch(str[0])
            {
                case 'v':
                    switch(str[1])
                    {
                        case '\0': //Vector
                            in >> x >> y >> z;
                            point.push_back(Vector4D_T<float>(x, y, z, 1));
                            break;
                        case 't': //UV
                            in >> x >> y;
                            uv.push_back(Vector2D_T<float>(x, y));
                            break;
                        case 'n': //Normal
                            in >> x >> y >> z;
                            normal.push_back(Vector4D_T<float>(x, y, z, 0));
                            break;
                        default:
                            throw std::runtime_error("Error! Unexpect Value!");
                            break;
                    }
                    break;
                case 'f':
                    for(size_t i = 0; i < 3; ++ i)
                    {
                        char div;
                        in >> temp.PointIndex[i] >> div >> temp.UVIndex[i] >> div >> temp.NormalIndex[i];
                        -- temp.PointIndex[i];
                        -- temp.UVIndex[i];
                        -- temp.NormalIndex[i];
                    }
                    face.push_back(temp);
                    break;
                case 'u':
                    in >> str;
                    texture.Load(str);
                    break;
                case '#':
                    break;
                default:
                    throw std::runtime_error("Error! Unexpect Value!");
                    break;
            }
        }
        in.close();
    }
}