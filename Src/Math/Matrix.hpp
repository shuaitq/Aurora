#ifndef AURORA_MATRIX_HPP_
#define AURORA_MATRIX_HPP_

#include <cstring>
#include <iostream>

namespace Aurora
{
    template <typename T>
    class Matrix4X4_T{
    public:
        Matrix4X4_T():m00(0), m01(0), m02(0), m03(0),
                      m10(0), m11(0), m12(0), m13(0),
                      m20(0), m21(0), m22(0), m23(0),
                      m30(0), m31(0), m32(0), m33(0){}
        Matrix4X4_T(const T m00_, const T m01_, const T m02_, const T m03_,
                    const T m10_, const T m11_, const T m12_, const T m13_,
                    const T m20_, const T m21_, const T m22_, const T m23_,
                    const T m30_, const T m31_, const T m32_, const T m33_):
                    m00(m00_), m01(m01_), m02(m02_), m03(m03_),
                    m10(m10_), m11(m11_), m12(m12_), m13(m13_),
                    m20(m20_), m21(m21_), m22(m22_), m23(m23_),
                    m30(m30_), m31(m31_), m32(m32_), m33(m33_){}
        Matrix4X4_T(const Matrix4X4_T<T> &matrix)
        {
            memcpy(this -> m, matrix.m, sizeof(m));
        }
        Matrix4X4_T<T>& operator = (const Matrix4X4_T<T> &matrix)
        {
            memcpy(m, matrix.m, sizeof(m));
            return *this;
        }

        Matrix4X4_T<T> operator * (const Matrix4X4_T<T> &matrix) const
        {
            Matrix4X4_T<T> ret;
            for(size_t i = 0; i < 4; ++ i)
            {
                for(size_t j = 0; j < 4; ++ j)
                {
                     ret.m[i][j] = m[i][0] * matrix.m[0][j] + m[i][1] * matrix.m[1][j] + m[i][2] * matrix.m[2][j] + m[i][3] * matrix.m[3][j];
                }
            }
            return ret;
        }
        Matrix4X4_T<T>& operator *= (const Matrix4X4_T<T> &matrix)
        {
            return *this = operator * (matrix);
        }

        friend std::ostream& operator << (std::ostream &out, const Matrix4X4_T<T> &m)
        {
            out << m.m[0][0] << ' ' << m.m[0][1] << ' ' << m.m[0][2] << ' ' << m.m[0][3] << std::endl;
            out << m.m[1][0] << ' ' << m.m[1][1] << ' ' << m.m[1][2] << ' ' << m.m[1][3] << std::endl;
            out << m.m[2][0] << ' ' << m.m[2][1] << ' ' << m.m[2][2] << ' ' << m.m[2][3] << std::endl;
            out << m.m[3][0] << ' ' << m.m[3][1] << ' ' << m.m[3][2] << ' ' << m.m[3][3];
            return out;
        }
        friend std::istream& operator >> (std::istream &in, Matrix4X4_T<T> &m)
        {
            in >> m.m[0][0] >> m.m[0][1] >> m.m[0][2] >> m.m[0][3];
            in >> m.m[1][0] >> m.m[1][1] >> m.m[1][2] >> m.m[1][3];
            in >> m.m[2][0] >> m.m[2][1] >> m.m[2][2] >> m.m[2][3];
            in >> m.m[3][0] >> m.m[3][1] >> m.m[3][2] >> m.m[3][3];
            return in;
        }

        union
        {
            struct
            {
                T m00, m01, m02, m03;
                T m10, m11, m12, m13;
                T m20, m21, m22, m23;
                T m30, m31, m32, m33;
            };
            T m[4][4];
        };
    private:
    };
}

#endif //AURORA_MATRIX_HPP_