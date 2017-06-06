#include "ObjectFile.hpp"

namespace Aurora
{
    void ObjectFile::Load(const std::string &path, std::vector<std::array<size_t, 3>> &face, Texture &texture)
    {
        std::ifstream in(path);
        if(!in.is_open())
        {
            throw std::runtime_error("Object " + path + " doesn't exist!");
        }
        std::string str;
        float x, y, z;
        std::vector<Vector4D_T<float>> PointList;
        std::vector<Vector4D_T<float>> NormalList;
        std::vector<Vector2D_T<float>> UVList;
        while(in >> str)
        {
            switch(str[0])
            {
                case 'v':
                    switch(str[1])
                    {
                        case '\0': //Vector
                            in >> x >> y >> z;
                            PointList.push_back(Vector4D_T<float>(x, y, z, 1));
                            break;
                        case 't': //UV
                            in >> x >> y;
                            UVList.push_back(Vector2D_T<float>(x, y));
                            break;
                        case 'n': //Normal
                            in >> x >> y >> z;
                            NormalList.push_back(Vector4D_T<float>(x, y, z, 0));
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
                        size_t v, u, n;
                        in >> v >> div >> u >> div >> n;
                        VertexList.push_back(Vertex(PointList[v - 1], NormalList[n - 1], UVList[u - 1]));
                    }
                    face.push_back({VertexList.size() - 3, VertexList.size() - 2, VertexList.size() - 1});
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