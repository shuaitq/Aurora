#include "SenceFile.hpp"

#include "json.hpp"
#include "../Core/Camera.hpp"
#include "../Model/Model.hpp"
#include "../Light/Light.hpp"
#include "../Light/DirectLight.hpp"
#include "../Light/PointLight.hpp"

#include <fstream>
#include <memory>

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

        width = j["width"];
        height = j["height"];
        
        camera.Set(j["camera"]);

        const nlohmann::json &model = j["object"];
        for(auto &it : model)
        {
            std::shared_ptr<Model> m = std::make_shared<Model>();
            m->Set(it);
            ModelList.push_back(m);
        }

        const nlohmann::json &light = j["light"];
        for(auto &it : light)
        {
            std::shared_ptr<Light> l;
            if(it["type"] == "DirectLight")
            {
                l = std::make_shared<DirectLight>();
            }
            else if(it["type"] == "PointLight")
            {
                l = std::make_shared<PointLight>();
            }
            l->Set(it);
            LightList.push_back(l);
        }
        in.close();
    }
}