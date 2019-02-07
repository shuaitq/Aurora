#include "Model.hpp"

namespace Aurora
{
    std::vector<std::shared_ptr<Model>> ModelList;
    Model::Model():position(0, 1), u(0, 0), v(0, 0), n(0, 0), texture(), face(){}
    void Model::Set(const nlohmann::json &json)
    {
        Load(json["path"]);
        const nlohmann::json &Position = json["position"];
        position.x = Position[0];
        position.y = Position[1];
        position.z = Position[2];
        position.w = 1;
        const nlohmann::json &U = json["u"];
        u.x = U[0];
        u.y = U[1];
        u.z = U[2];
        u.w = 0;
        const nlohmann::json &V = json["v"];
        v.x = V[0];
        v.y = V[1];
        v.z = V[2];
        v.w = 0;
        const nlohmann::json &N = json["n"];
        n.x = N[0];
        n.y = N[1];
        n.z = N[2];
        n.w = 0;
    }
    Matrix4X4_T<double> Model::ModelMatrix()
    {
        return Matrix4X4_T<double>(u.x, u.y, u.z, 0,
                                   v.x, v.y, v.z, 0,
                                   n.x, n.y, n.z, 0,
                                   position.x, position.y, position.z, 1);
    }

    void Model::Load(const std::string &path)
    {
        Loader::Load(path, face, texture);
    }
}