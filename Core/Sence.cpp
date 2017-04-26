#include "Sence.hpp"

namespace Aurora
{
    void Sence::Load(const std::string &path)
    {
        std::ifstream in(path);
		if(!in.is_open())
		{
			throw std::runtime_error("Object " + path + " doesn't exist!");
		}
    }
}