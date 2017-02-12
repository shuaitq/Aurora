#ifndef AURORA_OBJECT_FILE_HPP_
#define AURORA_OBJECT_FILE_HPP_

#include "../Core/Triangle.hpp"
#include "../Math/Math.hpp"
#include "../Core/Vertex.hpp"

#include <cstdio>
#include <vector>

namespace Aurora
{
	namespace ObjectFile
	{
		bool Load(const char *path, std::vector<Triangle> &tri)
		{
			FILE *fp = fopen(path, "r");
			if(fp == nullptr)
			{
				return false;
			}
			char usemtl[16];
			fscanf(fp, "usemtl %s", usemtl);
			char str[16];
			std::vector<Vector4D_T<float>> VectorMap;
			std::vector<Vector2D_T<float>> UVMap;
			std::vector<Vector4D_T<float>> NormalMap;
			float x, y, z;
			while(fscanf(fp, "%s", str) != EOF)
			{
				if(str[0] == 'v'){
					switch(str[1])
					{
						case ' ': //Vector
							fscanf(fp, "%f%f%f", &x, &y, &z);
							VectorMap.push_back(Vector4D_T<float>(x, y, z, 0));
							break;
						case 't': //Texture
							fscanf(fp, "%f%f", &x, &y);
							UVMap.push_back(Vector2D_T<float>(x, y));
							break;
						case 'n': //Normal
							fscanf(fp, "%f%f%f", &x, &y, &z);
							NormalMap.push_back(Vector4D_T<float>(x, y, z, 0));
							break;
						default:
							printf("Error! Unexpect Value!\n");
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
						temp.push_back(Vertex(VectorMap[v - 1], UVMap[u - 1], NormalMap[n - 1]));
					}
					tri.push_back(Triangle(temp));
				}
				else
				{
					printf("Error! Unexpect Value!\n");
					return false;
				}
			}
			return true;
		}
	}
}

#endif //AURORA_OBJECT_FILE_HPP_
