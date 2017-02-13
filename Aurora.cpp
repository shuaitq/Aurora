#include "Math/Math.hpp"
#include "Core/Vertex.hpp"
#include "Core/Object.hpp"

#include <cstdio>
#include <vector>

int main(int argc, char *argv[])
{
	using namespace Aurora;
	const char *path = "Object/cube.obj";
	FILE *fp = fopen(path, "r");
        char usemtl[16];
        fscanf(fp, "usemtl %s", usemtl);
        char str[16];
	std::vector<Point4D_T<float>> PointMap;
	std::vector<Point2D_T<float>> UVMap;
	std::vector<Vector4D_T<float>> NormalMap;
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
                                        break;
                        }
                }
                else if(str[0] == 'f')
                {
                	int v, u, n;
                        std::vector<int> temp;
                        for(size_t i = 0; i < 3; ++ i)
                        {
                        	fscanf(fp, "%d/%d/%d", &v, &u, &n);
				-- v;
				-- u;
				-- n;
				temp.push_back(v);
                                //temp.push_back(Vertex(PointMap[v], UVMap[u], NormalMap[n]));
                        }
			Vector4D_T<float> Normal;
                }
                else
                {
                        printf("Error! Unexpect Value! %c\n", str[0]);
		}	
	}
	return 0;
}
