#ifndef AURORA_POINT_HPP_
#define AURORA_POINT_HPP_

#include "Vector.hpp"
#include "Matrix.hpp"

#include <iostream>

namespace Aurora
{
    template <typename T>
    class Point2D_T
    {
    public:
        Point2D_T(const T t = 0):x(t), y(t){}
        Point2D_T(const T x_, const T y_):x(x_), y(y_){}
        Point2D_T(const Point2D_T<T> &p):x(p.x), y(p.y){}
        Point2D_T<T>& operator = (const Point2D_T<T> &p)
        {
            x = p.x;
            y = p.y;
            return *this;
        }

        bool operator == (const Point2D_T<T> &p)
        {
            return x == p.x && y == p.y;
        }
        bool operator != (const Point2D_T<T> &p)
        {
            return !operator == (p);
        }

        Point2D_T<T> operator + (const Point2D_T<T> &p) const
        {
            return Point2D_T<T>(x + p.x, y + p.y);
        }
        Point2D_T<T> operator + (const Vector2D_T<T> &v) const
        {
            return Point2D_T<T>(x + v.x, y + v.y);
        }
        Point2D_T<T>& operator += (const Vector2D_T<T> &v){
            x += v.x;
            y += v.y;
            return *this;
        }
        Vector2D_T<T> operator - (const Point2D_T<T> &p) const
        {
            return Vector2D_T<T>(x - p.x, y - p.y);
        }
        Point2D_T<T> operator - (const Vector2D_T<T> &v) const
        {
            return *this + (-v);
        }
        Point2D_T<T>& operator -= (const Vector2D_T<T> &v)
        {
            return *this += (-v);
        }

        template <typename U>
        Point2D_T<T> operator * (const U u) const
        {
            return Point2D_T<T>(x * u, y * u);
        }
        template <typename U>
        Point2D_T<T>& operator *= (const U u)
        {
            x *= u;
            y *= u;
            return *this;
        }
        template <typename U>
        Point2D_T<T> operator / (const U u) const
        {
            return operator * (T(1) / u);
        }
        template <typename U>
        Point2D_T<T>& operator /= (const U u)
        {
            return operator *= (T(1) / u);
        }

        Point2D_T<T> operator - () const
        {
            return Point2D_T<T>(-x, -y);
        }

        friend std::ostream& operator << (std::ostream &out, const Point2D_T<T> &p)
        {
            out << p.x << ' ' << p.y;
            return out;
        }
        friend std::istream& operator >> (std::istream &in, Point2D_T<T> &p)
        {
            in >> p.x >> p.y;
            return in;
        }

        T x, y;
    private:
    };
    template <typename U, typename T>
    Point2D_T<T> operator * (const U u, const Point2D_T<T> &p)
    {
        return p * u;
    }
    template <typename U, typename T>
    Point2D_T<T> operator / (const U u, const Point2D_T<T> &p)
    {
        return p / u;
    }

    template <typename T>
    class Point3D_T
    {
    public:
        Point3D_T(const T t = 0):x(t), y(t), z(t){}
        Point3D_T(const T x_, const T y_, const T z_):x(x_), y(y_), z(z_){}
        Point3D_T(const Point3D_T<T> &p):x(p.x), y(p.y), z(p.z){}
        Point3D_T<T>& operator = (const Point3D_T<T> &p)
        {
            x = p.x;
            y = p.y;
            z = p.z;
            return *this;
        }

        bool operator == (const Point3D_T<T> &p)
        {
            return x == p.x && y == p.y && z == p.z;
        }
        bool operator != (const Point3D_T<T> &p)
        {
            return !operator == (p);
        }

        Point3D_T<T> operator + (const Point3D_T<T> &p) const
        {
            return Point3D_T<T>(x + p.x, y + p.y, z + p.z);
        }
        Point3D_T<T> operator + (const Vector3D_T<T> &v) const
        {
            return Point3D_T<T>(x + v.x, y + v.y, z + v.z);
        }
        Point3D_T<T>& operator += (const Vector3D_T<T> &v){
            x += v.x;
            y += v.y;
            z += v.z;
            return *this;
        }
        Vector3D_T<T> operator - (const Point3D_T<T> &p) const
        {
            return Vector3D_T<T>(x - p.x, y - p.y, z - p.z);
        }
        Point3D_T<T> operator - (const Vector3D_T<T> &v) const
        {
            return *this + (-v);
        }
        Point3D_T<T>& operator -= (const Vector3D_T<T> &v)
        {
            return *this += (-v);
        }

        template <typename U>
        Point3D_T<T> operator * (const U u) const
        {
            return Point3D_T<T>(x * u, y * u, z * u);
        }
        template <typename U>
        Point3D_T<T>& operator *= (const U u)
        {
            x *= u;
            y *= u;
            z *= u;
            return *this;
        }
        template <typename U>
        Point3D_T<T> operator / (const U u) const
        {
            return operator * (T(1) / u);
        }
        template <typename U>
        Point3D_T<T>& operator /= (const U u)
        {
            return operator *= (T(1) / u);
        }

        Point3D_T<T> operator - () const
        {
            return Point3D_T<T>(-x, -y, -z);
        }

        friend std::ostream& operator << (std::ostream &out, const Point3D_T<T> &p)
        {
            out << p.x << ' ' << p.y << ' ' << p.z;
            return out;
        }
        friend std::istream& operator >> (std::istream &in, Point3D_T<T> &p)
        {
            in >> p.x >> p.y >> p.z;
            return in;
        }

        T x, y, z;
    private:
    };
    template <typename U, typename T>
    Point3D_T<T> operator * (const U u, const Point3D_T<T> &p)
    {
        return p * u;
    }
    template <typename U, typename T>
    Point3D_T<T> operator / (const U u, const Point3D_T<T> &p)
    {
        return p / u;
    }

    template <typename T>
    Vector3D_T<T> CalcNormal(const Point3D_T<T> &p1, const Point3D_T<T> &p2, const Point3D_T<T> &p3)
    {
        return Cross(p3 - p2, p2 - p1);
    }

    template <typename T>
    class Point4D_T
    {
    public:
        Point4D_T(const T t = 0, const T w_ = 1):x(t), y(t), z(t), w(w_){}
        Point4D_T(const T x_, const T y_, const T z_, const T w_ = 1):x(x_), y(y_), z(z_), w(w_){}
        Point4D_T(const Point4D_T<T> &p):x(p.x), y(p.y), z(p.z), w(p.w){}
        Point4D_T<T>& operator = (const Point4D_T<T> &p)
        {
            x = p.x;
            y = p.y;
            z = p.z;
            w = p.w;
            return *this;
        }

        bool operator == (const Point4D_T<T> &p)
        {
            return x == p.x && y == p.y && z == p.z && w == p.w;
        }
        bool operator != (const Point4D_T<T> &p)
        {
            return !operator == (p);
        }

        Point4D_T<T> operator + (const Point4D_T<T> &p) const
        {
            return Point4D_T<T>(x + p.x, y + p.y, z + p.z, w + p.w);
        }
        Point4D_T<T> operator + (const Vector4D_T<T> &v) const
        {
            return Point4D_T<T>(x + v.x, y + v.y ,z + v.z, w + v.w);
        }
        Point4D_T<T>& operator += (const Vector4D_T<T> &v)
        {
            x += v.x;
            y += v.y;
            z += v.z;
            w += v.w;
            return *this;
        }
        Vector4D_T<T> operator - (const Point4D_T<T> &p) const
        {
            return Vector4D_T<T>(x - p.x, y - p.y, z - p.z, w - p.w);
        }
        Point4D_T<T> operator - (const Vector4D_T<T> &v) const
        {
            return *this + (-v);
        }
        Point4D_T<T>& operator -= (const Vector4D_T<T> &v)
        {
            return *this += (-v);
        }

        Point4D_T<T> operator * (const Matrix4_T<T> &m) const
        {
            return Point4D_T<T>(x * m.m[0][0] + y * m.m[1][0] + z * m.m[2][0] + w * m.m[3][0],
                                x * m.m[0][1] + y * m.m[1][1] + z * m.m[2][1] + w * m.m[3][1],
                                x * m.m[0][2] + y * m.m[1][2] + z * m.m[2][2] + w * m.m[3][2],
                                x * m.m[0][3] + y * m.m[1][3] + z * m.m[2][3] + w * m.m[3][3]);
        }
        Point4D_T<T>& operator *= (const Matrix4_T<T> &m)
        {
            *this = operator * (m);
            return *this;
        }

        template <typename U>
        Point4D_T<T> operator * (const U u) const
        {
            return Point4D_T<T>(x * u, y * u, z * u, w);
        }
        template <typename U>
        Point4D_T<T>& operator *= (const U u)
        {
            x *= u;
            y *= u;
            z *= u;
            return *this;
        }
        template <typename U>
        Point4D_T<T> operator / (const U u) const
        {
            return operator * (T(1) / u);
        }
        template <typename U>
        Point4D_T<T>& operator /= (const U u)
        {
            return operator *= (T(1) / u);
        }

        Point4D_T<T> operator - () const
        {
            return Point4D_T<T>(-x, -y, -z, -w);
        }

        friend std::ostream& operator << (std::ostream &out, const Point4D_T<T> &p)
        {
            out << p.x << ' ' << p.y << ' ' << p.z << ' ' << p.w;
            return out;
        }
        friend std::istream& operator >> (std::istream &in, Point4D_T<T> &p)
        {
            in >> p.x >> p.y >> p.z;
            return in;
        }

        T x, y, z, w;
    private:
    };
    template <typename U, typename T>
    Point4D_T<T> operator * (const U u, const Point4D_T<T> &p)
    {
        return p * u;
    }
    template <typename U, typename T>
    Point4D_T<T> operator / (const U u, const Point4D_T<T> &p)
    {
        return p / u;
    }

    template <typename T>
    Vector4D_T<T> CalcNormal(const Point4D_T<T> &p1, const Point4D_T<T> &p2, const Point4D_T<T> &p3)
    {
        return Cross(p3 - p2, p2 - p1);
    }
}

#endif //AURORA_POINT_HPP_