#ifndef AURORA_MODEL_HPP_
#define AURORA_MODEL_HPP_

#include "../Math/Math.hpp"
#include "../Utility/json.hpp"
#include "../Utility/ObjectFile.hpp"
#include "Face.hpp"
#include "Texture.hpp"

#include <vector>

namespace Aurora
{
    class Model
    {
    public:
        Model();
        void Set(const nlohmann::json &json);
        Matrix4X4_T<float> ModelMatrix();

        Vector4D_T<float> position;
        Vector4D_T<float> u, v, n;
        Texture texture;
        std::vector<Vertex> vertex;
        std::vector<Face> face;
    private:
        using Loader = ObjectFile;
        void Load(const std::string &path);
    };
    extern std::vector<std::shared_ptr<Model>> ModelList;
};

#endif // AURORA_MODEL_HPP_