#include "ObjectFile.hpp"

namespace Aurora
{
	namespace ObjectFile
	{
		void Load(const std::string &path, std::vector<Vertex> &vertex, std::vector<Triangle> &triangle, Texture &texture)
		{
			std::ifstream in(path);
			if(!in.is_open())
			{
				throw std::runtime_error("Object " + path + " doesn't exist!");
			}
			std::string usemtl;
			in >> usemtl;
			if(usemtl != "usemtl")
			{
				throw std::runtime_error("Error! Unexpect Value! usemtl:" + usemtl);
			}
			in >> usemtl;
			texture.Load(usemtl);
			std::string str;
			std::vector<Point4D_T<float>> PointMap;
			std::vector<Point2D_T<float>> UVMap;
			std::vector<Vector4D_T<float>> NormalMap;
			float x, y, z;
			while(!in.eof())
			{
				in >> str;
				if(str[0] == 'v'){
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
							throw std::runtime_error("Error! Unexpect Value! ");
							break;
					}
				}
				else if(str[0] == 'f')
				{
					int v, u, n;
					std::vector<Vertex> temp;
					size_t IndexVertex = temp.size();
					for(size_t i = 0; i < 3; ++ i)
					{
						char div;
						in >> v >> div >> u >> div >> n;
						-- v;
						-- u;
						-- n;
						temp.push_back(Vertex(PointMap[v], UVMap[u], NormalMap[n]));
					}
					size_t IndexTriangle = triangle.size();
					temp[temp.size()-1].push_back(IndexTriangle);
					temp[temp.size()-2].push_back(IndexTriangle);
					temp[temp.size()-3].push_back(IndexTriangle);
					triangle.push_back(Triangle(IndexVertex + 0,IndexVertex + 1,IndexVertex + 2));
				}
				else
				{
					throw std::runtime_error("Error! Unexpect Value! ");
				}
			}
			in.close();
		}
	}
}
