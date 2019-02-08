#ifndef AURORA_MODEL_HPP_
#define AURORA_MODEL_HPP_

#include "../Math/Math.hpp"
#include "../Utility/json.hpp"
#include "Texture.hpp"

#include <vector>
#include <array>

namespace Aurora
{
    class Model
    {
    public:
        Model();
        void Set(const nlohmann::json &json, const std::string &root);
        Matrix4X4_T<double> ModelMatrix();

        Vector4D_T<double> position;
        Vector4D_T<double> u, v, n;
        Texture texture;
        std::vector<std::array<size_t, 3>> face;
    private:
        void Load(const std::string &path);
    };
    extern std::vector<std::shared_ptr<Model>> ModelList;
};

#endif // AURORA_MODEL_HPP_