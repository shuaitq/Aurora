#include "SenceFile.hpp"

namespace Aurora
{
    static void SenceFile::Load(const std::string &path, Sence &sence)
    {
        nlohmann::json j;
        std::ifstream in(path);
        if(!in.is_open())
        {
            throw std::runtime_error("Object " + path + " doesn't exist!");
        }
        in >> j;
        sence.width = j["width"];
        sence.height = j["height"];

        const nlohmann::json &camera = j["camera"];
        const nlohmann::json &position = camera["position"];
        sence.camera.position.x = position[0];
        sence.camera.position.y = position[1];
        sence.camera.position.z = position[2];
        const nlohmann::json &up = camera["up"];
        sence.camera.up.x = up[0];
        sence.camera.up.y = up[1];
        sence.camera.up.z = up[2];
        const nlohmann::json &front = camera["front"];
        sence.camera.front.x = front[0];
        sence.camera.front.y = front[1];
        sence.camera.front.z = front[2];
        const nlohmann::json &right = camera["right"];
        sence.camera.right.x = right[0];
        sence.camera.right.y = right[1];
        sence.camera.right.z = right[2];
        sence.camera.fov = camera["fov"];

        const nlohmann::json &object = camera["object"];
        for(auto it = object.begin(); it != object.end(); ++ it)
        {
            
        }

        const nlohmann::json &light = camera["light"];
        for(auto it = light.begin(); it != light.end(); ++ it)
        {
            
        }
    }
}