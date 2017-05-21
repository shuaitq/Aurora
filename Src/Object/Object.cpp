#include "Object.hpp"

namespace Aurora
{
    Object::Object():position(0, 1), u(0, 0), v(0, 0), n(0, 0), texture(), point(), normal(), uv(), face(){}
    void Object::Set(const nlohmann::json &json)
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

    void Object::Load(const std::string &path)
    {
        Loader::Load(path, point, normal, uv, face, texture);
    }
}