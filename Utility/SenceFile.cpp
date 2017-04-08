#include "SenceFile.hpp"

namespace Aurora
{
	void SenceFile::Load(const std::string &path, size_t &width, size_t &height, Camera &camera, std::vector<Object<>> &object)
	{
		std::ifstream in(path);
		if(!in.is_open())
		{
			throw std::runtime_error("Sence file " + path + "doesn't exist!");
		}
		std::string sign;
		while(in >> sign)
		{
			switch(sign[0])
			{
				case '#': //continue;
					in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					break;
				case 'r': //Renderer width height
					in >> width >> height;
					camera.aspect() = (float)width / height;
					break;
				case 'c': //Camera Position Up Front Right Fov
					in >> camera;
					break;
				case 'o':
					Object<> temp;
					std::string ObjectPath;
					in >> ObjectPath;
					temp.Load(ObjectPath);
					in >> temp;
					object.push_back(temp);
					break;
			}
		}
		in.close();
	}
}
