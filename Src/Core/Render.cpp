#include "Render.hpp"

namespace Aurora
{
    Render::Render(const std::string &path)
    {
        Loader::Load(path);
        screen.resize(width * height);
        depth.resize(width * height);
    }

    void Render::Work(const std::string &path)
    {
        Matrix4X4_T<float> View = camera.ViewMatrix();
        Matrix4X4_T<float> Proj = camera.ProjMatrix();
        Vertex RenderVertex[3];

        std::fill(screen.begin(), screen.end(), RGB_T<float>());
        std::fill(depth.begin(), depth.end(), 0.0f);

        for(const std::shared_ptr<Light> &l : LightList)
        {
            l->Transform(View);
        }
        for(const std::shared_ptr<Model> &m : ModelList)
        {
            Matrix4X4_T<float> mv = m->ModelMatrix() * View;
            
            for(const std::array<size_t, 3> &f : m->face)
            {
                for(size_t i = 0; i < 3; ++ i)
                {
                    RenderVertex[i] = VertexList[f[i]] * mv;
                }
                if(IsBackFace(RenderVertex[0], RenderVertex[1], RenderVertex[2]))
                {
                    continue;
                }
                bool flag = false;
                for(size_t i = 0; i < 3; ++ i)
                {
                    RenderVertex[i] *= Proj;
                    RenderVertex[i].point.x /= RenderVertex[i].point.w;
                    RenderVertex[i].point.y /= RenderVertex[i].point.w;
                    RenderVertex[i].point.z /= RenderVertex[i].point.w;

                    if(RenderVertex[i].point.z < 0.0f || RenderVertex[i].point.z > 1.0f)
                    {
                        flag = true;
                        break;
                    }
                    RenderVertex[i].point.x = (RenderVertex[i].point.x + 1) * 0.5f * width;
                    RenderVertex[i].point.y = (1 - RenderVertex[i].point.y) * 0.5f * height;
                    RenderVertex[i].point.z = RenderVertex[i].point.w;
                    RenderVertex[i].point.w = 1 / RenderVertex[i].point.w;


                    RenderVertex[i].uv /= RenderVertex[i].point.z;
                    RenderVertex[i].normal /= RenderVertex[i].point.z;
                }
                if(!flag)
                {
                    FillFace(RenderVertex[0], RenderVertex[1], RenderVertex[2], m->texture);
                }
            }
        }
        auto ACESToneMapping = [](float x)
        {
            x = (x * (2.51f * x + 0.03f)) / (x * (2.43f * x + 0.59f) + 0.14f);
            x = std::max(0.0f, std::min(1.0f, x));
            return x;
        };
        for(int x = 0; x < width; ++ x)
        {
            for(int y = 0; y < height; ++ y)
            {
                screen[y * width + x].red = ACESToneMapping(screen[y * width + x].red);
                screen[y * width + x].green = ACESToneMapping(screen[y * width + x].green);
                screen[y * width + x].blue = ACESToneMapping(screen[y * width + x].blue);
            }
        }
        Saver::Save(path, width, height, screen);
    }

    bool Render::IsBackFace(const Vertex &v0, const Vertex &v1, const Vertex &v2)
    {
        return Dot(v0.point, Cross(v1.point - v0.point, v2.point - v0.point)) >= 0;
    }
    void Render::FillFace(const Vertex &v0, const Vertex &v1, const Vertex &v2, const Texture &texture)
    {
        size_t x0 = std::max(0, (int)std::min(v0.point.x, std::min(v1.point.x, v2.point.x)));
        size_t y0 = std::max(0, (int)std::min(v0.point.y, std::min(v1.point.y, v2.point.y)));
        size_t x1 = std::min(width - 1,  (int)std::max(v0.point.x, std::max(v1.point.x, v2.point.x)));
        size_t y1 = std::min(height - 1, (int)std::max(v0.point.y, std::max(v1.point.y, v2.point.y)));

        auto f = [](float x, float y, Vector4D_T<float> a, Vector4D_T<float> b)
        {
            return (a.y - b.y) * x + (b.x - a.x) * y + a.x * b.y - b.x * a.y;
        };

        float fa = f(v0.point.x, v0.point.y, v1.point, v2.point);
        float fb = f(v1.point.x, v1.point.y, v2.point, v0.point);
        float fc = f(v2.point.x, v2.point.y, v0.point, v1.point);

        for(size_t y = y0; y <= y1; ++ y)
        {
            for(size_t x = x0; x <= x1; ++ x)
            {
                float a = x + 0.5f, b = y + 0.5f;
                float f0 = f(a, b, v1.point, v2.point) / fa;
                float f1 = f(a, b, v2.point, v0.point) / fb;
                float f2 = f(a, b, v0.point, v1.point) / fc;
                if(f0 > 0 && f1 > 0 && f2 > 0)
                {
                    float oneofz = v0.point.w * f0 + v1.point.w * f1 + v2.point.w * f2;
                    if(oneofz >= depth[y * width + x])
                    {
                        depth[y * width + x] = oneofz;
                        Vector2D_T<float> uv = v0.uv * f0 + v1.uv * f1 + v2.uv * f2;
                        Vector4D_T<float> normal = v0.normal * f0 + v1.normal * f1 + v2.normal * f2;
                        uv /= oneofz;
                        normal /= oneofz;
                        screen[y * width + x] = texture.Sample(uv.x, uv.y);
                    }
                }
            }
        }
    }
}