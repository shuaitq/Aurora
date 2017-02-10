#ifndef AURORA_MATRIX_HPP_
#define AURORA_MATRIX_HPP_

#include <cstring>

namespace Aurora
{
	template <typename T>
	class Matrix4_T{
	public:
		Matrix4_T()
		{
			memset(m_, 0 , sizeof(m_));
		}
		Matrix4_T(const T m11, const T m12, const T m13, const T m14,
				const T m21, const T m22, const T m23, const T m24,
				const T m31, const T m32, const T m33, const T m34,
				const T m41, const T m42, const T m43, const T m44):
				m11_(m11), m12_(m12), m13_(m13), m14_(m14),
				m21_(m21), m22_(m22), m23_(m23), m24_(m24),
				m31_(m31), m32_(m32), m33_(m33), m34_(m34),
				m41_(m41), m42_(m42), m43_(m43), m44_(m44){}
		Matrix4_T(const Matrix4_T<T> &matrix)
		{
			memcpy(this -> _m, matrix.begin(), sizeof(_m));
		}
		Martix4_T<T> operator=(const Matrix4_T<T> &matrix)
		{
			memcpy(_m, matrix.begin(), sizeof(_m));
		}

		bool operator==(const Matrix4_T<T> &matrix) const
		{
			return memcmp(_m, matrix.begin(), sizeof(_m)) == 0;
		}
		bool operator!=(const Matrix4_T<T> &matrix) const
		{
			return !operator==(matrix);
		}

		Matrix4_T<T> operator*(const Matrix4_T<T> &matrix) const
		{
			Matrix4_T<T> m;
			for(size_t i = 0; i < 4; ++ i)
			{
				for(size_t j = 0; j < 4; ++ j)
				{
					 m[i][j] = m_[i][0] * matrix[0][j] + m_[i][1] * matrix[1][j] + m_[i][2] * matrix[2][j] + m_[i][3] * matrix[3][j];
				}
			}
		}
		Matrix4_T<T>& operator*=(const Matrix4_T<T> &matrix)
		{
			return *this = operator*(matrix);
		}
		
		T& operator[](size_t row, size_t col)
		{
			return m_[row][col];
		}
		const T& operator[](size_t row, size_t col) const
		{
			return m_[row][col];
		}

		T* begin() const
		{
			return &_m[0];
		}
	private:
		union
		{
			struct
			{
				T m11_, m12_, m13_, m14_;
				T m21_, m22_, m23_, m24_;
				T m31_, m32_, m33_, m34_;
				T m41_, m42_, m43_, m44_;
			};
			T m_[4][4];
			T _m[16];
		};
	};
}

#endif //AURORA_MATRIX_HPP_
