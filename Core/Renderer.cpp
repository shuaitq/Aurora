#include "Renderer.hpp"

namespace Aurora
{
    Renderer::Renderer(const std::string &path)
    {
        Sence::Load(path, width_, height_, camera_, object_);
        screen_.resize(width_ * height_);
        ZBuffer_.resize(width_ * height_);
        ZFlag_ = 0;
    }
    void Render(const std::string &path)
    {
        Init();
        ObjectToWorld();
        WorldToCamera();
        CameraToCVV();
        Clip();
        CVVToScreen();
        Rasterization();
    }

    void ObjectToWorld()
    {
        for(Object &o : render_sence.object)
        {
            o.ObjectToWorld();
        }
        for(Light &l : render_sence.light)
        {
            l.LightToWorld();
        }
    }
    void WorldToCamera()
    {
        Martix4_T<float> m = sence.camera.WorldToCamera();
        for(Object &o : render_sence.object)
        {
            o *= m;
        }
        for(Light &l : render_sence.light)
        {
            l *= m;
        }
    }
    void CameraToCVV()
    {

    }
    void Clip()
    {

    }
    void CVVToScreen()
    {

    }
    void Rasterization()
    {

    }
    void Init()
    {
        render_sence = sence;
    }
}