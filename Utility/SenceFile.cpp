#include "SenceFile.hpp"

namespace Aurora
{
	namespace SenceFile
	{
		void Load(const std::string &path, size_t &width, size_t &height, Camera &camera, std::vector<Object> &object)
		{
			std::ifstream in(path);
			if(!in.is_open())
			{
				throw std::runtime_error("Sence file " + path + "doesn't exist!");
			}
			std::string line;
			while(!in.eof())
			{
				std::getline(in, line);
				switch(line[0])
				{
					case '#': //continue;
						break;
					case 'r': //Renderer width height
						in >> width >> height;
						break;
					case 'c': //Camera Position Up Front Right Fov
						in >> camera
						break;
					case 'o':
						break;
				}
			}
			// Renderer width height
			in >> width >> height;
			std::string ObjectName;
			Point4D_T<float> position;
			Point4D_T<float> up;
			Point4D_T<float> front;
			Point4D_T<float> right;
			while(!in.eof())
			{
				in >> ObjectName;
				in >> position.x() >> position.y() >> position.z();
				in >> up.x() >> up.y() >> up.z();
				in >> front.x() >> front.y() >> front.z();
				in >> right.x() >> right.y() >> right.z();
				object.push_back(Object(position, up, front, right));
				object.back().Load(ObjectName);
			}
			in.close();
		}
	}
}
