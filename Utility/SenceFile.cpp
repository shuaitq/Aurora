#include "SenceFile.hpp"

namespace Aurora
{
	namespace SenceFile
	{
		void Load(const string &path, std::vector<Object> &object)
		{
			std::ifstream in(path);
			if(!in.is_open())
			{
				throw std::runtime_error("Sence file " + path + "doesn't exist!");
			}
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
		}
	}
}
