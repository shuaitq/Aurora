#ifndef AURORA_VECTOR_HPP_
#define AURORA_VECTOR_HPP_

#include "Matrix.hpp"

#include <cmath>
#include <iostream>
//#include <utility>

namespace Aurora
{
    template <typename T>
    class Vector2D_T
    {
    public:
        Vector2D_T(const T t = 0):x(t), y(t){}
        Vector2D_T(const T x_, const T y_):x(x_), y(y_){}
        Vector2D_T(const Vector2D_T<T> &v):x(v.x), y(v.y){}
        Vector2D_T<T>& operator = (const Vector2D_T<T> &v)
        {
            x = v.x;
            y = v.y;
            return *this;
        }

        bool operator == (const Vector2D_T<T> &v) const
        {
            return x == v.x && y == v.y;
        }
        bool operator != (const Vector2D_T<T> &v) const
        {
            return !operator == (v);
        }

        Vector2D_T<T> operator + (const Vector2D_T<T> &v) const
        {
            return Vector2D_T<T>(x + v.x, y + v.y);
        }
        Vector2D_T<T>& operator += (const Vector2D_T<T> &v)
        {
            x += v.x;
            y += v.y;
            return *this;
        }
        Vector2D_T<T> operator - (const Vector2D_T<T> &v) const
        {
            return *this + (-v);
        }
        Vector2D_T<T>& operator -= (const Vector2D_T<T> &v)
        {
            return *this += (-v);
        }

        template <typename U>
        Vector2D_T<T> operator * (const U u) const
        {
            return Vector2D_T<T>(x * u, y * u);
        }
        template <typename U>
        Vector2D_T<T>& operator *= (const U u)
        {
            x *= u;
            y *= u;
            return *this;
        }
        template <typename U>
        Vector2D_T<T> operator / (const U u) const
        {
            return operator * (T(1) / u);
        }
        template <typename U>
        Vector2D_T<T>& operator /= (const U u)
        {
            return operator *= (T(1) / u);
        }

        Vector2D_T<T> operator - () const
        {
            return Vector2D_T<T> (-x, -y);
        }

        T Length2() const
        {
            return x * x + y * y;
        }
        T Length() const
        {
            return sqrt(Length());
        }

        friend std::ostream& operator << (std::ostream &out, const Vector2D_T<T> &v)
        {
            out << v.x << ' ' << v.y;
            return out;
        }
        friend std::istream& operator >> (std::istream &in, Vector2D_T<T> &v)
        {
            in >> v.x >> v.y;
            return in;
        }

        T x, y;
    private:
    };

    template <typename U, typename T>
    Vector2D_T<T> operator * (const U u, const Vector2D_T<T> &v)
    {
        return v * u;
    }
    template <typename U, typename T>
    Vector2D_T<T> operator / (const U u, const Vector2D_T<T> &v)
    {
        return v / u;
    }
    template <typename T>
    Vector2D_T<T> Normalize(const Vector2D_T<T> &v)
    {
        return v / v.Length2();
    }
    template <typename T>
    T Dot(const Vector2D_T<T> &lhs, const Vector2D_T<T> &rhs)
    {
        return lhs.x * rhs.x + lhs.y * rhs.y;
    }

    template <typename T>
    class Vector3D_T
    {
    public:
        Vector3D_T(const T t = 0):x(t), y(t), z(t){}
        Vector3D_T(const T x_, const T y_, const T z_):x(x_), y(y_), z(z_){}
        Vector3D_T(const Vector3D_T<T> &v):x(v.x), y(v.y), z(v.z){}
        Vector3D_T<T>& operator = (const Vector3D_T<T> &v)
        {
            x = v.x;
            y = v.y;
            z = v.z;
            return *this;
        }

        bool operator == (const Vector3D_T<T> &v) const
        {
            return x == v.x && y == v.y && z == v.z;
        }
        bool operator != (const Vector3D_T<T> &v) const
        {
            return !operator == (v);
        }

        Vector3D_T<T> operator + (const Vector3D_T<T> &v) const
        {
            return Vector3D_T<T>(x + v.x, y + v.y, z + v.z);
        }
        Vector3D_T<T>& operator += (const Vector3D_T<T> &v)
        {
            x += v.x;
            y += v.y;
            z += v.z;
            return *this;
        }
        Vector3D_T<T> operator - (const Vector3D_T<T> &v) const
        {
            return *this + (-v);
        }
        Vector3D_T<T>& operator -= (const Vector3D_T<T> &v)
        {
            return *this += (-v);
        }

        template <typename U>
        Vector3D_T<T> operator * (const U u) const
        {
            return Vector3D_T<T>(x * u, y * u, z * u);
        }
        template <typename U>
        Vector3D_T<T>& operator *= (const U u)
        {
            x *= u;
            y *= u;
            z *= u;
            return *this;
        }
        template <typename U>
        Vector3D_T<T> operator / (const U u) const
        {
            return operator * (T(1) / u);
        }
        template <typename U>
        Vector3D_T<T>& operator /= (const U u)
        {
            return operator *= (T(1) / u);
        }

        Vector3D_T<T> operator - () const
        {
            return Vector3D_T<T> (-x, -y, -z);
        }

        T Length2() const
        {
            return x * x + y * y + z * z;
        }
        T Length() const
        {
            return sqrt(Length2());
        }

        friend std::ostream& operator << (std::ostream &out, const Vector3D_T<T> &v)
        {
            out << v.x << ' ' << v.y << ' ' << v.z;
            return out;
        }
        friend std::istream& operator >> (std::istream &in, Vector3D_T<T> &v)
        {
            in >> v.x >> v.y >> v.z;
            return in;
        }

        T x, y, z;
    private:
    };

    template <typename U, typename T>
    Vector3D_T<T> operator * (const U u, const Vector3D_T<T> &v)
    {
        return v * u;
    }
    template <typename U, typename T>
    Vector3D_T<T> operator / (const U u, const Vector3D_T<T> &v)
    {
        return v / u;
    }
    template <typename T>
    Vector3D_T<T> Normalize(const Vector3D_T<T> &v)
    {
        return v / v.Length();
    }
    template <typename T>
    Vector3D_T<T> Cross(const Vector3D_T<T> &lhs, const Vector3D_T<T> &rhs)
    {
        return Vector3D_T<T>(lhs.y * rhs.z - lhs.z * rhs.y,
                             lhs.z * rhs.x - lhs.x * rhs.z,
                             lhs.x * rhs.y - lhs.y * rhs.x);
    }
    template <typename T>
    T Dot(const Vector3D_T<T> &lhs, const Vector3D_T<T> &rhs)
    {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
    }

    template <typename T>
    class Vector4D_T
    {
    public:
        Vector4D_T(const T t = 0, const T w_ = 0):x(t), y(t), z(t), w(w_){}
        Vector4D_T(const T x_, const T y_, const T z_, const T w_ = 0):x(x_), y(y_), z(z_), w(w_){}
        Vector4D_T(const Vector4D_T<T> &v):x(v.x), y(v.y), z(v.z), w(v.w){}
        Vector4D_T<T>& operator = (const Vector4D_T<T> &v)
        {
            x = v.x;
            y = v.y;
            z = v.z;
            w = v.w;
            return *this;
        }

        bool operator == (const Vector4D_T<T> &v) const
        {
            return x == v.x && y == v.y && z == v.z && w == v.w;
        }
        bool operator != (const Vector4D_T<T> &v)
        {
            return !operator == (v);
        }

        Vector4D_T<T> operator + (const Vector4D_T<T> &v) const
        {
            return Vector4D_T<T>(x + v.x, y + v.y, z + v.z, w + v.w);
        }
        Vector4D_T<T>& operator += (const Vector4D_T<T> &v)
        {
            x += v.x;
            y += v.y;
            z += v.z;
            w += v.w;
            return *this;
        }
        Vector4D_T<T> operator - (const Vector4D_T<T> &v) const
        {
            return *this + (-v);
        }
        Vector4D_T<T>& operator -= (const Vector4D_T<T> &v)
        {
            return *this += (-v);
        }

        Vector4D_T<T> operator * (const Matrix4_T<T> &m) const
        {
            return Vector4D_T<T>(x * m.m[0][0] + y * m.m[1][0] + z * m.m[2][0] + w * m.m[3][0],
                                 x * m.m[0][1] + y * m.m[1][1] + z * m.m[2][1] + w * m.m[3][1],
                                 x * m.m[0][2] + y * m.m[1][2] + z * m.m[2][2] + w * m.m[3][2],
                                 x * m.m[0][3] + y * m.m[1][3] + z * m.m[2][3] + w * m.m[3][3]);
        }
        Vector4D_T<T>& operator *= (const Matrix4_T<T> &m)
        {
            *this = operator * (m);
            return *this;
        }
        template <typename U>
        Vector4D_T<T> operator * (const U u) const
        {
            return Vector4D_T<T>(x * u, y * u, z * u, w * u);
        }
        template <typename U>
        Vector4D_T<T>& operator *= (const U u)
        {
            x *= u;
            y *= u;
            z *= u;
            w *= u;
            return *this;
        }
        template <typename U>
        Vector4D_T<T> operator / (const U u) const
        {
            return *this * (T(1) / u);
        }
        template <typename U>
        Vector4D_T<T>& operator /= (const U u)
        {
            return *this *= (T(1) / u);
        }

        Vector4D_T<T> operator - () const
        {
            return Vector4D_T<T>(-x, -y, -z, -w);
        }

        T Length2() const
        {
            return x * x + y * y + z * z;
        }
        T Length() const
        {
            return sqrt(Length2());
        }

        friend std::ostream& operator << (std::ostream &out, const Vector4D_T<T> &v)
        {
            out << v.x << ' ' << v.y << ' ' << v.z << ' ' << v.w;
            return out;
        }
        friend std::istream& operator >> (std::istream &in, Vector4D_T<T> &v)
        {
            in >> v.x >> v.y >> v.z;
            return in;
        }

        T x, y, z, w;
    private:
    };

    template <typename U, typename T>
    Vector4D_T<T> operator * (const U u, const Vector4D_T<T> &v)
    {
        return v * u;
    }
    template <typename U, typename T>
    Vector4D_T<T> operator / (const U u, const Vector4D_T<T> &v)
    {
        return v * u;
    }
    template <typename T>
    Vector4D_T<T> Normalize(const Vector4D_T<T> &v)
    {
        return v / v.Length();
    }
    template <typename T>
    Vector4D_T<T> Cross(const Vector4D_T<T> &lhs, const Vector4D_T<T> &rhs)
    {
        return Vector4D_T<T>(lhs.y * rhs.z - lhs.z * rhs.y,
                             lhs.z * rhs.x - lhs.x * rhs.z,
                             lhs.x * rhs.y - lhs.y * rhs.x);

    }
    template <typename T>
    T Dot(const Vector4D_T<T> &lhs, const Vector4D_T<T> &rhs)
    {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
    }
}

#endif //AURORA_VECTOR_HPP_
