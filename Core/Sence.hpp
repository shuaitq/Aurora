#ifndef AURORA_SENCE_HPP_
#define AURORA_SENCE_HPP_

#include "../Math/Math.hpp"
#include "Object.hpp"
#include "../Utility/SenceFile.hpp"

#include <vector>
#include <string>

namespace Aurora
{
	class Sence
	{
	public:
		void Load(const string &path)
		{
			SenceFile::Load(path, object_);
		}
	private:
		std::vector<Object> object_;
	}
}

#endif //AURORA_SENCE_HPP_
