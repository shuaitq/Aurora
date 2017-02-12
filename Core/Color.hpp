#ifndef AURORA_COLOR_HPP_
#define AURORA_COLOR_HPP_

#include <cstdio>

namespace Aurora
{
	template <typename T>
	class RGB_T
	{
	public:
		RGB_T():red_(0), green_(0), blue_(0){}
		RGB_T(const T t):red_(t), green_(t), blue_(t){}
		RGB_T(const T red, const T green, const T blue):red_(red), green_(green), blue_(blue){}
		RGB_T(const RGB_T<T> &rgb):red_(rgb.red_), green_(rgb.green_), blue_(rgb.blue_){}
		RGB_T<T>& operator=(const RGB_T<T> &rgb)
		{
			red_ = rgb.red_;
			green_ = rgb.green_;
			blue_ = rgb.blue_;
			return *this;
		}

		RGB_T<T> operator*(RGB_T<T> &rgb) const
		{
			return RGB_T<T>(red_ * rgb.red_, green_ * rgb.green_, blue_ * rgb.blue_);
		}
		RGB_T<T>& operator*=(RGB_T<T> &rgb)
		{
			red_ *= rgb.red_;
			green_ *= rgb.green_;
			blue_ *= rgb.blue_;
			return *this;
		}

		template <typename U>
		RGB_T<T> operator*(const U u) const
		{
			return RGB_T<T>(red_ * u, green_ * u, blue_ * u);
		}
		template <typename U>
		RGB_T<T>& operator*=(const U u)
		{
			red_ *= u;
			green_ *= u;
			blue_ *= u;
			return *this;
		}
		template <typename U>
		RGB_T<T> operator/(const U u) const
		{
			return operator*(T(1)/u);
		}
		template <typename U>
		RGB_T<T>& operator/=(const U u)
		{
			return operator*=(T(1)/u);
		}

		T& operator[](size_t index)
		{
			return col_[index];
		}
		const T& operator[](size_t index) const
		{
			return col_[index];
		}
		T& red()
		{
			return red_;
		}
		const T& red() const
		{
			return red_;
		}
		T& green()
		{
			return green_;
		}
		const T& green() const
		{
			return green_;
		}
		T& blue()
		{
			return blue_;
		}
		const T& blue() const
		{
			return blue_;
		}

		const static RGB_T<T> black;
		const static RGB_T<T> white;

	private:
		union
		{
			struct
			{
				T red_, green_, blue_;
			};
			T col_[3];
		};
	};

	template <typename T>
	class RGBA_T
	{
	public:
		RGBA_T():red_(0), green_(0), blue_(0), alpha_(1){}
		RGBA_T(const T t, const T alpha = 1):red_(t), green_(t), blue_(t), alpha_(alpha){}
		RGBA_T(const T red, const T green, const T blue, const T alpha = 1):red_(red), green_(green), blue_(blue), alpha_(alpha){}
		RGBA_T(const RGBA_T<T> &rgba):red_(rgba.red_), green_(rgba.green_), blue_(rgba.blue_), alpha_(rgba.alpha_){}
		RGBA_T<T>& operator=(const RGBA_T<T> &rgba)
		{
			red_ = rgba.red_;
			green_ = rgba.green_;
			blue_ = rgba.blue_;
			alpha_ = rgba.alpha_;
			return *this;
		}

		template <typename U>
		RGBA_T<T> operator*(const U u) const
		{
			return RGBA_T<T>(red_ * u, green_ * u, blue_ * u, alpha_);
		}
		template <typename U>
		RGBA_T<T>& operator*(const U u)
		{
			red_ *= u;
			green_ *= u;
			blue_ *= u;
			return *this;
		}
		template <typename U>
		RGBA_T<T> operator/(const U u) const
		{
			return operator*(T(1)/u);
		}
		template <typename U>
		RGBA_T<T>& operator/=(const U u)
		{
			return operator*=(T(1)/u);
		}

		T& operator[](size_t index)
		{
			return col_[index];
		}
		const T& operator[](size_t index) const
		{
			return col_[index];
		}
		T& red()
		{
			return red_;
		}
		const T& red() const
		{
			return red_;
		}
		T& green()
		{
			return green_;
		}
		const T& green() const
		{
			return green_;
		}
		T& blue()
		{
			return blue_;
		}
		const T& blue() const
		{
			return blue_;
		}
		T& alpha()
		{
			return alpha_;
		}
		const T& alpha() const
		{
			return alpha_;
		}

		const static RGBA_T<T> black;
		const static RGBA_T<T> white;

	private:
		union
		{
			struct
			{
				T red_, green_, blue_, alpha_;
			};
			T col_[4];
		};
	};
}

#endif //AURORA_COLOR_HPP_
