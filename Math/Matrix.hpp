#ifndef AURORA_MATRIX_HPP_
#define AURORA_MATRIX_HPP_

#include <cstring>
#include <iostream>

namespace Aurora
{
    template <typename T>
    class Matrix4X3_T{
    public:
        Matrix4X3_T()
        {
            memset(m, 0, sizeof(m));
        }
        Matrix4X3_T(const T m00_, const T m01_, const T m02_,
                    const T m10_, const T m11_, const T m12_,
                    const T m20_, const T m21_, const T m22_,
                    const T m30_, const T m31_, const T m32_):
                    m00(m00_), m01(m01_), m02(m02_),
                    m10(m10_), m11(m11_), m12(m12_),
                    m20(m20_), m21(m21_), m22(m22_),
                    m30(m30_), m31(m31_), m32(m32_){}
        Matrix4X3_T(const Matrix4X3_T<T> &matrix)
        {
            memcpy(this -> m, matrix.m, sizeof(m));
        }
        Matrix4X3_T<T>& operator = (const Matrix4X3_T<T> &matrix)
        {
            memcpy(m, matrix.m, sizeof(m));
            return *this;
        }

        bool operator == (const Matrix4X3_T<T> &matrix) const
        {
            return memcmp(m, matrix.m, sizeof(m)) == 0;
        }
        bool operator != (const Matrix4X3_T<T> &matrix) const
        {
            return !operator == (matrix);
        }

        Matrix4X3_T<T> operator * (const Matrix4X3_T<T> &matrix) const
        {
            Matrix4X3_T<T> m;
            for(size_t i = 0; i < 3; ++ i)
            {
                for(size_t j = 0; j < 3; ++ j)
                {
                     m.m[i][j] = m[i][0] * matrix.m[0][j] + m[i][1] * matrix.m[1][j] + m[i][2] * matrix.m[2][j];
                }
            }
            for(size_t i = 0; i < 3; ++ i)
            {
                m.m[3][i] = m[3][0] * matrix.m[i][0] + m[3][1] * matrix.m[i][1] + m[3][2] * matrix.m[i][2] + matrix.m[i][3];
            }
            return m;
        }
        Matrix4X3_T<T>& operator *= (const Matrix4X3_T<T> &matrix)
        {
            return *this = operator * (matrix);
        }

        friend std::ostream& operator << (std::ostream &out, const Matrix4X3_T<T> &m)
        {
            out << m[0][0] << ' ' << m[0][1] << ' ' << m[0][2] << ' ' << m[0][3] << std::endl;
            out << m[1][0] << ' ' << m[1][1] << ' ' << m[1][2] << ' ' << m[1][3] << std::endl;
            out << m[2][0] << ' ' << m[2][1] << ' ' << m[2][2] << ' ' << m[2][3] << std::endl;
            out << m[3][0] << ' ' << m[3][1] << ' ' << m[3][2] << ' ' << m[3][3];
            return out;
        }
        friend std::istream& operator >> (std::istream &in, Matrix4X3_T<T> &m)
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
                T m00, m01, m02;
                T m10, m11, m12;
                T m20, m21, m22;
                T m30, m31, m32;
            };
            T m[4][3];
        };
    private:
    };
}

#endif //AURORA_MATRIX_HPP_