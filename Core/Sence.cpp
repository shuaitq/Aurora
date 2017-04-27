#include "Sence.hpp"

namespace Aurora
{
    void Sence::Load(const std::string &path)
    {
        Loader::Load(path, *this);
    }
}