#include "SenceFile.hpp"

namespace Aurora
{
    void SenceFile::Load(const std::string &path, Sence &sence)
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
        sence.camera.aspect = static_cast<float>(sence.width) / sence.height;

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

        const nlohmann::json &object = j["object"];
        for(auto &it : object)
        {
            std::shared_ptr<Object> temp = std::make_shared<Object>();
            temp->Load(it["path"]);
            const nlohmann::json &position = it["position"];
            temp->position.x = position[0];
            temp->position.y = position[1];
            temp->position.z = position[2];
            const nlohmann::json &up = it["up"];
            temp->up.x = up[0];
            temp->up.y = up[1];
            temp->up.z = up[2];
            const nlohmann::json &front = it["front"];
            temp->front.x = front[0];
            temp->front.y = front[1];
            temp->front.z = front[2];
            const nlohmann::json &right = it["right"];
            temp->right.x = right[0];
            temp->right.y = right[1];
            temp->right.z = right[2];
            sence.object.push_back(temp);
        }

        const nlohmann::json &light = j["light"];
        for(auto &it : light)
        {
            std::shared_ptr<Light> light;
            if(it["type"] == "directlight")
            {
                light = std::make_shared<DirectLight>();
            }
            else if(it["type"] == "pointlight")
            {
                light = std::make_shared<PointLight>();
            }
            const nlohmann::json &position = it["position"];
            light->position.x = position[0];
            light->position.y = position[1];
            light->position.z = position[2];
            const nlohmann::json &direction = it["direction"];
            light->direction.x = direction[0];
            light->direction.y = direction[1];
            light->direction.z = direction[2];
            const nlohmann::json &color = it["color"];
            light->color.red = color[0];
            light->color.green = color[1];
            light->color.blue = color[2];
            sence.light.push_back(light);
        }
    }
}