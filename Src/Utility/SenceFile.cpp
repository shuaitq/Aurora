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

        width = j["width"];
        height = j["height"];

        camera.Set(j["camera"]);

        const nlohmann::json &object = j["object"];
        for(auto &it : object)
        {
            std::shared_ptr<Object> o = std::make_shared<Object>();
            o->Set(it);
            ObjectList.push_back(o);
        }

        const nlohmann::json &light = j["light"];
        for(auto &it : light)
        {
            std::shared_ptr<Light> l;
            if(it["type"] == "directlight")
            {
                l = std::make_shared<DirectLight>();
            }
            else if(it["type"] == "pointlight")
            {
                l = std::make_shared<PointLight>();
            }
            l->Set(it);
            LightList.push_back(l);
        }
    }
}