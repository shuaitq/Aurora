#include "ObjectFile.hpp"

#include "../Model/Vertex.hpp"
#include "../Math/Math.hpp"

#include <fstream>

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
        double x, y, z;
        std::vector<Vector4D_T<double>> PointList;
        std::vector<Vector4D_T<double>> NormalList;
        std::vector<Vector2D_T<double>> UVList;
        while(in >> str)
        {
            switch(str[0])
            {
                case 'v':
                    switch(str[1])
                    {
                        case '\0': //Vector
                            in >> x >> y >> z;
                            PointList.push_back(Vector4D_T<double>(x, y, z, 1));
                            break;
                        case 't': //UV
                            in >> x >> y;
                            UVList.push_back(Vector2D_T<double>(x, y));
                            break;
                        case 'n': //Normal
                            in >> x >> y >> z;
                            NormalList.push_back(Vector4D_T<double>(x, y, z, 0));
                            break;
                        default:
                            throw std::runtime_error("Error! Unexpect Value!");
                            break;
                    }
                    break;
                case 'f':
                    for(size_t i = 0; i < 3; ++ i)
                    {
                        size_t v = 0, u = 0, n = 0, pos = 0;
                        std::string temp;
                        in >> temp;
                        while(temp[pos] != '/' && pos < temp.length())
                        {
                            v *= 10;
                            v += temp[pos] - '0';
                            ++ pos;
                        }
                        ++ pos;
                        while(temp[pos] != '/' && pos < temp.length())
                        {
                            u *= 10;
                            u += temp[pos] - '0';
                            ++ pos;
                        }
                        ++ pos;
                        while(pos < temp.length())
                        {
                            n *= 10;
                            n += temp[pos] - '0';
                            ++ pos;
                        }
                        if(u == 0)
                        {
                            VertexList.push_back(Vertex(PointList[v - 1], NormalList[n - 1], Vector2D_T<double>()));
                        }
                        else
                        {
                            VertexList.push_back(Vertex(PointList[v - 1], NormalList[n - 1], UVList[u - 1]));
                        }
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
                    throw std::runtime_error("Error! Unexpect Value!" + str);
                    break;
            }
        }
        in.close();
    }
}