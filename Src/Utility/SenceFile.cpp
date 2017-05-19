#include "SenceFile.hpp"

namespace Aurora
{
    void SenceFile::Load(const std::string &path)
    {
        nlohmann::json j;
        std::ifstream in(path);
        if(!in.is_open())
        {
            throw std::runtime_error("Object " + path + " doesn't exist!");
        }
        in >> j;
        camera.width = j["width"];
        camera.height = j["height"];
        camera.aspect = static_cast<float>(camera.width) / camera.height;

        const nlohmann::json &c = j["camera"];
        camera.near = c["near"];
        camera.far = c["far"];
        camera.rotatex = c["rotatex"];
        camera.rotatey = c["rotatey"];
        camera.rotatez = c["rotatez"];
        camera.fov = c["fov"];
        const nlohmann::json &position = c["position"];
        camera.position.x = position[0];
        camera.position.y = position[1];
        camera.position.z = position[2];

        const nlohmann::json &object = j["object"];
        for(auto &it : object)
        {
            std::shared_ptr<Object> o = std::make_shared<Object>();
            o->Load(it["path"]);
            const nlohmann::json &position = it["position"];
            o->position.x = position[0];
            o->position.y = position[1];
            o->position.z = position[2];
            o->rotatex = it["rotatex"];
            o->rotatey = it["rotatey"];
            o->rotatez = it["rotatez"];
            sence.object.push_back(o);
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