#ifndef AURORA_OBJECT_HPP_
#define AURORA_OBJECT_HPP_

#include "../Math/Math.hpp"
#include "../Utility/json.hpp"
#include "../Utility/ObjectFile.hpp"
#include "Face.hpp"
#include "Texture.hpp"

#include <vector>

namespace Aurora
{
    class Object
    {
    public:
        Object();
        void Set(const nlohmann::json &json);

        Vector4D_T<float> position;
        Vector4D_T<float> u, v, n;
        Texture texture;
        std::vector<Vector4D_T<float>> point;
        std::vector<Vector4D_T<float>> normal;
        std::vector<Vector2D_T<float>> uv;
        std::vector<Face> face;
    private:
        using Loader = ObjectFile;
        void Load(const std::string &path);
    };
    std::vector<std::shared_ptr<Object>> ObjectList;
};

#endif // AURORA_OBJECT_HPP_