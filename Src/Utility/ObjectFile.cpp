#include "ObjectFile.hpp"

namespace Aurora
{
    void ObjectFile::Load(const std::string &path)
    {
        std::ifstream in(path);
        if(!in.is_open())
        {
            throw std::runtime_error("Object " + path + " doesn't exist!");
        }
        std::string str;
        std::vector<size_t> index;
        Texture texture;
        float x, y, z;
        int v, u, n;
        size_t PointSize = PointList.size();
        size_t NormalSize = NormalList.size();
        size_t UVSize = UVList.size();
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
                        in >> v >> div >> u >> div >> n;
                        VertexList.push_back(Vertex(PointSize + v - 1, NormalSize + n - 1, UVSize + u - 1));
                    }
                    sizt_t VertexSize = VertexList.size();
                    FaceList.push_back(Face(VertexSize - 3, VertexSize - 2, VertexSize - 1));
                    index.push_back(Face.size() - 1);
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
        ObjectList.push_back(Object());
        in.close();
    }
}