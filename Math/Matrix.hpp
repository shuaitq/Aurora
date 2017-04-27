#ifndef AURORA_MATRIX_HPP_
#define AURORA_MATRIX_HPP_

#include <cstring>
#include <iostream>

namespace Aurora
{
    template <typename T>
    class Matrix4_T{
    public:
        Matrix4_T()
        {
            memset(m, 0, sizeof(m));
        }
        Matrix4_T(const T m11_, const T m12_, const T m13_, const T m14_,
                  const T m21_, const T m22_, const T m23_, const T m24_,
                  const T m31_, const T m32_, const T m33_, const T m34_,
                  const T m41_, const T m42_, const T m43_, const T m44_):
                  m11(m11_), m12(m12_), m13(m13_), m14(m14_),
                  m21(m21_), m22(m22_), m23(m23_), m24(m24_),
                  m31(m31_), m32(m32_), m33(m33_), m34(m34_),
                  m41(m41_), m42(m42_), m43(m43_), m44(m44_){}
        Matrix4_T(const Matrix4_T<T> &matrix)
        {
            memcpy(this -> m, matrix.m, sizeof(m));
        }
        Matrix4_T<T>& operator = (const Matrix4_T<T> &matrix)
        {
            memcpy(m, matrix.m, sizeof(m));
            return *this;
        }

        bool operator == (const Matrix4_T<T> &matrix) const
        {
            return memcmp(m, matrix.m, sizeof(m)) == 0;
        }
        bool operator != (const Matrix4_T<T> &matrix) const
        {
            return !operator == (matrix);
        }

        Matrix4_T<T> operator * (const Matrix4_T<T> &matrix) const
        {
            Matrix4_T<T> m;
            for(size_t i = 0; i < 4; ++ i)
            {
                for(size_t j = 0; j < 4; ++ j)
                {
                     m.m[i][j] = m[i][0] * matrix.m[0][j] + m[i][1] * matrix.m[1][j] + m[i][2] * matrix.m[2][j] + m[i][3] * matrix.m[3][j];
                }
            }
            return m;
        }
        Matrix4_T<T>& operator *= (const Matrix4_T<T> &matrix)
        {
            return *this = operator * (matrix);
        }

        friend std::ostream& operator << (std::ostream &out, const Matrix4_T<T> &m)
        {
            out << m[0][0] << ' ' << m[0][1] << ' ' << m[0][2] << ' ' << m[0][3] << std::endl;
            out << m[1][0] << ' ' << m[1][1] << ' ' << m[1][2] << ' ' << m[1][3] << std::endl;
            out << m[2][0] << ' ' << m[2][1] << ' ' << m[2][2] << ' ' << m[2][3] << std::endl;
            out << m[3][0] << ' ' << m[3][1] << ' ' << m[3][2] << ' ' << m[3][3];
            return out;
        }
        friend std::istream& operator >> (std::istream &in, Matrix4_T<T> &m)
        {
            in >> m[0][0] >> m[0][1] >> m[0][2] >> m[0][3];
            in >> m[1][0] >> m[1][1] >> m[1][2] >> m[1][3];
            in >> m[2][0] >> m[2][1] >> m[2][2] >> m[2][3];
            in >> m[3][0] >> m[3][1] >> m[3][2] >> m[3][3];
            return in;
        }

        union
        {
            struct
            {
                T m11, m12, m13, m14;
                T m21, m22, m23, m24;
                T m31, m32, m33, m34;
                T m41, m42, m43, m44;
            };
            T m[4][4];
        };
    private:
    };
}

#endif //AURORA_MATRIX_HPP_
