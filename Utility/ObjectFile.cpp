#include "ObjectFile.hpp"

namespace Aurora
{
    void ObjectFile::Load(const std::string &path, Object &object)
    {
        std::ifstream in(path);
        if(!in.is_open())
        {
            throw std::runtime_error("Object " + path + " doesn't exist!");
        }
        std::string str;
        std::vector<Point4D_T<float>> PointMap;
        std::vector<Point2D_T<float>> UVMap;
        std::vector<Vector4D_T<float>> NormalMap;
        float x, y, z;
        int v, u, n;
        Triangle tri;
        while(in >> str)
        {
            switch(str[0])
            {
                case 'v':
                    switch(str[1])
                    {
                        case '\0': //Vector
                            in >> x >> y >> z;
                            PointMap.push_back(Point4D_T<float>(x, y, z));
                            break;
                        case 't': //Texture
                            in >> x >> y;
                            UVMap.push_back(Point2D_T<float>(x, y));
                            break;
                        case 'n': //Normal
                            in >> x >> y >> z;
                            NormalMap.push_back(Vector4D_T<float>(x, y, z));
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
                        in >> v >> div >> u >> div >> n;
                        tri[i] = Vertex(PointMap[v - 1], UVMap[u - 1], NormalMap[n - 1]);
                    }
                    triangle.push_back(tri);
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