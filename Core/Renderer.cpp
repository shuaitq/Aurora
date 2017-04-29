#include "Renderer.hpp"

namespace Aurora
{
    Renderer::Renderer(const std::string &path)
    {
        Loader::Load(path, sence);
    }
    void Renderer::Render(const std::string &path)
    {
        Init();
        ObjectToWorld();
        WorldToCamera();
        CameraToCVV();
        Clip();
        CVVToScreen();
        Rasterization();
        Save(path);
    }

    std::ostream& operator << (std::ostream &out, const Renderer &renderer)
    {
        out << "Sence" << std::endl;
        out << renderer.sence;
        return out;
    }

    void Renderer::ObjectToWorld()
    {
        for(std::shared_ptr<Object> &o : render_sence.object)
        {
            o->ObjectToWorld();
        }
    }
    void Renderer::WorldToCamera()
    {
        Matrix4_T<float> m = sence.camera.WorldToCamera();
        for(std::shared_ptr<Object> &o : render_sence.object)
        {
            *o *= m;
        }
        for(std::shared_ptr<Light> &l : render_sence.light)
        {
            *l *= m;
        }
    }
    void Renderer::CameraToCVV()
    {
        Matrix4_T<float> m = sence.camera.CameraToCVV();
        for()
        {
            
        }
    }
    void Renderer::Clip()
    {

    }
    void Renderer::CVVToScreen()
    {

    }
    void Renderer::Rasterization()
    {

    }
    void Renderer::Init()
    {
        render_sence = sence;
    }
    void Renderer::Save(const std::string &path)
    {

    }
}