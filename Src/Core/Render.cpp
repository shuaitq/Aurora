#include "Render.hpp"

namespace Aurora
{
    Render::Render(const std::string &path)
    {
        Loader::Load(path);
        screen.resize(width * height);
        depth.resize(width * height);
    }

    std::vector<RGB_T<float>>& Render::Work(const std::string &path)
    {
        Matrix4X4_T<float> View = camera.ViewMatrix();
        Matrix4X4_T<float> Proj = camera.ProjMatrix();
        Matrix4X4_T<float> Wind = camera.WindMatrix();
        Vertex RenderVertex[3];

        std::fill(screen.begin(), screen.end(), RGB_T<float>());
        std::fill(depth.begin(), depth.end(), 0.0f);

        for(const std::shared_ptr<Light> &l : LightList)
        {
            l->Transform(View);
        }
        for(const std::shared_ptr<Model> &m : ModelList)
        {
            Matrix4X4_T<float> Model = m->ModelMatrix();
            Matrix4X4_T<float> mv = Model * View;
            Matrix4X4_T<float> mvp = mv * Proj;
            
            for(const Face &f : m->face)
            {
                for(size_t i = 0; i < 3; ++ i)
                {
                    RenderVertex[i] = VertexList[f.index[i]] * mv;
                }
                if(IsBackFace(RenderVertex[0], RenderVertex[0], VertexVertex[0]))
                {
                    continue;
                }
                bool flag = false;;
                for(size_t i = 0; i < 3; ++ i)
                {
                    RenderVertex[i] *= Proj;
                    if(RenderVertex[i].point.z < 0.0f || RenderVertex[i].point.z > 1.0f)
                    {
                        flag = true;
                    }
                    RenderVertex[i] *= Wind;
                }
                if(!flag)
                {
                    FillFace(RenderVertex[0], RenderVertex[1], RenderVertex[2]);
                }
            }
        }
        return screen;
    }

    bool Render::IsBackFace(const Vertex &v1, const Vertex &v2, const Vertex &v3)
    {
        if(Dot(v1.point, CalcNormal(v1.point, v2.point, v3.point)) < 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    void Render::FillFace(const Vertex &v1, const Vertex &v2, const Vertex &v3, const Texture &texture)
    {
        size_t x0 = std::max(0, (int)std::floor());
    }
}