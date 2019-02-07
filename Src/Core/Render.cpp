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
        RenderVertex v[3];

        std::fill(screen.begin(), screen.end(), RGB_T<double>());
        std::fill(depth.begin(), depth.end(), 0.0);

        for(const std::shared_ptr<Light> &l : LightList)
        {
            l->Transform(camera.ViewMatrix());
        }

        for(const std::shared_ptr<Model> &m : ModelList)
        {
            Matrix4X4_T<double> mv = m->ModelMatrix() * camera.ViewMatrix();
            Matrix4X4_T<double> mvp = mv * camera.ProjMatrix();
            
            for(const std::array<size_t, 3> &f : m->face)
            {
                bool OutOfRange = false;
                for(size_t i = 0; i < 3; ++ i)
                {
                    v[i].point = VertexList[f[i]].point * mvp;
                    v[i].view = VertexList[f[i]].point * mv;
                    v[i].normal = VertexList[f[i]].normal * mv;
                    v[i].uv = VertexList[f[i]].uv;

                    v[i].point.x /= v[i].point.w;
                    v[i].point.y /= v[i].point.w;
                    v[i].point.z /= v[i].point.w;

                    if(v[i].point.z < 0.0 || v[i].point.z > 1.0)
                    {
                        OutOfRange = true;
                        break;
                    }

                }
                if(OutOfRange || IsBackFace(v[0].view, v[1].view, v[2].view))
                {
                    continue;
                }
                for(size_t i = 0; i < 3; ++ i)
                {
                    v[i].point.x = (v[i].point.x + 1.0) * 0.5 * width;
                    v[i].point.y = (1.0 - v[i].point.y) * 0.5 * height;
                    v[i].point.z = v[i].point.w;
                    v[i].point.w = 1 / v[i].point.w;

                    v[i].view /= v[i].point.z;
                    v[i].uv /= v[i].point.z;
                    v[i].normal /= v[i].point.z;
                }

                FillFace(v[0], v[1], v[2], m->texture);
            }
        }

        auto ACESToneMapping = [](double x)
        {
            x = (x * (2.51 * x + 0.03)) / (x * (2.43 * x + 0.59) + 0.14);
            x = std::max(0.0, std::min(1.0, x));
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

    bool Render::IsBackFace(const Vector4D_T<double> &v0, const Vector4D_T<double> &v1, const Vector4D_T<double> &v2)
    {
        return Dot(v0, Cross(v1 - v0, v2 - v0)) >= 0;
    }
    void Render::FillFace(const RenderVertex &v0, const RenderVertex &v1, const RenderVertex &v2, const Texture &texture)
    {
        size_t x0 = std::max(0, (int)std::floor(std::min(v0.point.x, std::min(v1.point.x, v2.point.x))));
        size_t y0 = std::max(0, (int)std::floor(std::min(v0.point.y, std::min(v1.point.y, v2.point.y))));
        size_t x1 = std::min(width - 1,  (int)std::max(v0.point.x, std::max(v1.point.x, v2.point.x)));
        size_t y1 = std::min(height - 1, (int)std::max(v0.point.y, std::max(v1.point.y, v2.point.y)));

        auto f = [](double x, double y, Vector4D_T<double> a, Vector4D_T<double> b)
        {
            return (a.y - b.y) * x + (b.x - a.x) * y + a.x * b.y - b.x * a.y;
        };

        double fa = f(v0.point.x, v0.point.y, v1.point, v2.point);
        double fb = f(v1.point.x, v1.point.y, v2.point, v0.point);
        double fc = f(v2.point.x, v2.point.y, v0.point, v1.point);

        for(size_t y = y0; y <= y1; ++ y)
        {
            for(size_t x = x0; x <= x1; ++ x)
            {
                double a = x + 0.5, b = y + 0.5;
                double f0 = f(a, b, v1.point, v2.point) / fa;
                double f1 = f(a, b, v2.point, v0.point) / fb;
                double f2 = f(a, b, v0.point, v1.point) / fc;
                if(f0 >= 0 && f1 >= 0 && f2 >= 0)
                {
                    double OnePreZ = v0.point.w * f0 + v1.point.w * f1 + v2.point.w * f2;
                    if(OnePreZ >= depth[y * width + x])
                    {
                        depth[y * width + x] = OnePreZ;
                        Vector2D_T<double> uv = v0.uv * f0 + v1.uv * f1 + v2.uv * f2;
                        Vector4D_T<double> view = v0.view * f0 + v1.view * f1 + v2.view * f2;
                        Vector4D_T<double> normal = v0.normal * f0 + v1.normal * f1 + v2.normal * f2;
                        uv /= OnePreZ;
                        view /= OnePreZ;
                        normal /= OnePreZ;
                        RGB_T<double> color;
                        for(const std::shared_ptr<Light> &l : LightList)
                        {
                            color += l->Sample(view, normal);
                        }
                        screen[y * width + x] = color * texture.Sample(uv.x, uv.y);
                    }
                }
            }
        }
    }

    Render::RenderVertex::RenderVertex():point(0, 1), view(0, 1), normal(0, 0), uv(){};
}