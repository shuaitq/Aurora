#include "ObjectFile.hpp"

namespace Aurora
{
	namespace ObjectFile
	{
		bool Load(const char *path, std::vector<Vertex> &vertex, std::vecter<Triangle> &triangle, Texture &texture)
		{
			FILE *fp = fopen(path, "r");
			if(fp == nullptr)
			{
				return false;
			}
			char usemtl[16];
			fscanf(fp, "usemtl %s", usemtl);
			if(!texture.Load(usemtl))
			{
				return false;
			}
			char str[16];
			float x, y, z;
			while(fscanf(fp, "%s", str) != EOF)
			{
				if(str[0] == 'v'){
					switch(str[1])
					{
						case '\0': //Vector
							fscanf(fp, "%f%f%f", &x, &y, &z);
							PointMap.push_back(Point4D_T<float>(x, y, z));
							break;
						case 't': //Texture
							fscanf(fp, "%f%f", &x, &y);
							UVMap.push_back(Point2D_T<float>(x, y));
							break;
						case 'n': //Normal
							fscanf(fp, "%f%f%f", &x, &y, &z);
							NormalMap.push_back(Vector4D_T<float>(x, y, z));
							break;
						default:
							printf("Error! Unexpect Value! %c\n", str[1]);
							return false;
							break;
					}
				}
				else if(str[0] == 'f')
				{
					int v, u, n;
					std::vector<Vertex> temp;
					for(size_t i = 0; i < 3; ++ i)
					{
						fscanf(fp, "%d/%d/%d", &v, &u, &n);
						temp.push_back(Vertex(PointMap[v - 1], UVMap[u - 1], NormalMap[n - 1]));
					}
					tri.push_back(Triangle(temp));
				}
				else
				{
					printf("Error! Unexpect Value! %c\n", str[0]);
					return false;
				}
			}
			return true;
		}
	}
}
