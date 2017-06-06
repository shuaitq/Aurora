#include "Camera.hpp"

namespace Aurora
{
    Camera camera;
    int width, height;
    Camera::Camera():position(0, 1), u(0, 0), v(0, 0), n(0, 0), fov(), near(), far(), aspect(){}
    void Camera::Set(const nlohmann::json &json)
    {
        aspect = static_cast<float>(width) / height;

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

        fov = json["fov"];
        fov *= M_PI;
        fov /= 180.0f;
        near = json["near"];
        far = json["far"];
    }
    Matrix4X4_T<float> Camera::ViewMatrix()
    {
        return Matrix4X4_T<float>(u.x, v.x, n.x, 0,
                                  u.y, v.y, n.y, 0,
                                  u.z, v.z, n.z, 0,
                                  -Dot(position, u), -Dot(position, v), -Dot(position, n), 1);
    }
    Matrix4X4_T<float> Camera::ProjMatrix()
    {
        float cot = 1 / tan(fov * 0.5f);
        return Matrix4X4_T<float>(cot / aspect, 0, 0, 0,
                                  0, cot, 0, 0,
                                  0, 0, far /(far - near), 1,
                                  0, 0, far * near / (near - far), 0);
    }
}