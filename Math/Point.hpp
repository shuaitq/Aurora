#ifndef AURORA_POINT_H_
#define AURORA_POINT_H_

#include "Vector.hpp"

namespace Aurora
{
	template <typename T>
	class Point2D_T
	{
	public:
		Point2D_T():x_(0), y_(0){}
		Point2D_T(const T t):x_(t), y_(t){}
		Point2D_T(const T x, const T y):x_(x), y_(y){}
		Point2D_T(const Point2D_T<T> &p):x_(p.x_), y_(p.y_){}
		Point2D_T<T>& operator=(const Point2D_T<T> &p)
		{
			x_ = p.x_;
			y_ = p.y_;
			return *this;
		}

		bool operator==(const Point2D_T<T> &p)
		{
			return x_ == p.x_ && y_ == p.y;
		}
		bool operator!=(const Point2D_T<T> &p)
		{
			return !operator==(p);
		}

		Point2D_T<T> operator+(const Point2D_T<T> &p) const
		{
			return Point2D_T<T>(x_ + p.x_, y_ + p.y_);
		}
		Point2D_T<T> operator+(const Vector2D_T<T> &v) const
		{
			return Point2D_T<T>(x_ + v.x_, y_ + v.y_);
		}
		Point2D_T<T>& operator+=(const Vector2D_T<T> &v){
			x_ += v.x_;
			y_ += v.y_;
			return *this;
		}
		Vector2D_T<T> operator-(const Point2D_T<T> &p) const
		{
			return Vector2D_T<T>(x_ - p.x_, y_ - p.y_);
		}
		Point2D_T<T> operator-(const Vector2D_T<T> &v) const
		{
			return *this+(-v);
		}
		Point2D_T<T>& operator-=(const Vector2D_T<T> &v)
		{
			return *this+=(-v);
		}

		template <typename U>
		Point2D_T<T> operator*(const U u) const
		{
			return Point2D_T<T>(x_ * u, y_ * u);
		}
		template <typename U>
		Point2D_T<T>& operator*=(const U u)
		{
			x_ *= u;
			y_ *= u;
			return *this;
		}
		template <typename U>
		Point2D_T<T> operator/(const U u) const
		{
			return operator*(T(1) / u);
		}
		template <typename U>
		Point2D_T<T>& operator/=(const U u)
		{
			return operator*=(T(1) / u);
		}

		Point2D_T<T> operator-() const
		{
			return Point2D_T<T>(-x_, -y_);
		}
	private:
		T x_, y_;
	};

	template <typename T>
	class Point3D_T
	{
	public:
		Point3D_T():x_(0), y_(0), z_(0){}
		Point3D_T(const T t):x_(t), y_(t), z_(t){}
		Point3D_T(const T x, const T y, const T z):x_(x), y_(y), z_(z){}
		Point3D_T(const Point3D_T<T> &p):x_(p.x_), y_(p.y_), z_(p.z_){}
		Point3D_T<T>& operator=(const Point3D_T<T> &p)
		{
			x_ = p.x_;
			y_ = p.y_;
			z_ = p.z_;
			return *this;
		}

		bool operator==(const Point3D_T<T> &p)
		{
			return x_ == p.x_ && y_ == p.y_ && z_ == p.z_;
		}
		bool operator!=(const Point3D_T<T> &p)
		{
			return !operator==(p);
		}

		Point3D_T<T> operator+(const Point3D_T<T> &p) const
		{
			return Point3D_T<T>(x_ + p.x_, y_ + p.y_, z_ + p.z_);
		}
		Point3D_T<T> operator+(const Vector3D_T<T> &v) const
		{
			return Point3D_T<T>(x_ + v.x_, y_ + v.y_, z_ + v.z_);
		}
		Point3D_T<T>& operator+=(const Vector3D_T<T> &v){
			x_ += v.x_;
			y_ += v.y_;
			z_ += v.z_;
			return *this;
		}
		Vector3D_T<T> operator-(const Point3D_T<T> &p) const
		{
			return Vector3D_T<T>(x_ - p.x_, y_ - p.y_, z_ - p.z_);
		}
		Point3D_T<T> operator-(const Vector3D_T<T> &v) const
		{
			return *this+(-v);
		}
		Point3D_T<T>& operator-=(const Vector3D_T<T> &v)
		{
			return *this+=(-v);
		}

		template <typename U>
		Point3D_T<T> operator*(const U u) const
		{
			return Point3D_T<T>(x_ * u, y_ * u, z_ * u);
		}
		template <typename U>
		Point3D_T<T>& operator*=(const U u)
		{
			x_ *= u;
			y_ *= u;
			z_ *= u;
			return *this;
		}
		template <typename U>
		Point3D_T<T> operator/(const U u) const
		{
			return operator*(T(1) / u);
		}
		template <typename U>
		Point3D_T<T>& operator/=(const U u)
		{
			return operator*=(T(1) / u);
		}

		Point3D_T<T> operator-() const
		{
			return Point3D_T<T>(-x_, -y_, -z_);
		}
	private:
		T x_, y_, z_;
	};

	template <typename T>
	class Point4D_T
	{
	public:
		Point4D_T():x_(0), y_(0), z_(0), w_(1){}
		Point4D_T(const T t, const T w = 1):x_(t), y_(t), z_(t), w_(w){}
		Point4D_T(const T x, const T y, const T z, const T w = 1):x_(x), y_(y), z_(z), w_(w){}
		Point4D_T(const Point4D_T<T> &p):x_(p.x_), y_(p.y_), z_(p.z_), w_(p.w_){}
		Point4D_T<T>& operator=(const Point4D_T<T> &p)
		{
			x_ = p.x_;
			y_ = p.y_;
			z_ = p.z_;
			w_ = p.w_;
			return *this;
		}

		bool operator==(const Point4D_T<T> &p)
		{
			return x_ == p.x_ && y_ == p.y_ && z_ == p.z_ && w_ == p.w_;
		}
		bool operator!=(const Point4D_T<T> &p)
		{
			return !operator==(p);
		}

		Point4D_T<T> operator+(const Point4D_T<T> &p) const
		{
			return Point4D_T<T>(x_ + p.x_, y_ + p.y_, z_ + p.z_, 1);
		}
		Point4D_T<T> operator+(const Vector4D_T<T> &v) const
		{
			return Point4D_T<T>(x_ + v.x_, y_ + v.y_ ,z_ + v.z_, 1);
		}
		Point4D_T<T>& operator+=(const Vector4D_T<T> &v)
		{
			x_ += v.x_;
			y_ += v.y_;
			z_ += v.z_;
			return *this;
		}
		Vector4D_T<T> operator-(const Point4D_T<T> &p) const
		{
			return Vector4D_T<T>(x_ - p.x_, y_ - p.y_, z_ - p.z_, 0);
		}
		Point4D_T<T> operator-(const Vector4D_T<T> &v) const
		{
			return *this+(-v);
		}
		Point4D_T<T>& operator-=(const Vector4D_T<T> &v)
		{
			return *this+=(-v);
		}

		template <typename U>
		Point4D_T<T> operator*(const U u) const
		{
			return Point4D_T<T>(x_ * u, y_ * u, z_ * u, 1);
		}
		template <typename U>
		Point4D_T<T>& operator*=(const U u)
		{
			x_ *= u;
			y_ *= u;
			z_ *= u;
			return *this;
		}
		template <typename U>
		Point4D_T<T> operator/(const U u) const
		{
			return operator*(T(1) / u);
		}
		template <typename U>
		Point4D_T<T>& operator/=(const U u)
		{
			return operator*=(T(1) / u);
		}

		Point4D_T<T> operator-() const
		{
			return Point4D_T<T>(-x_, -y_, -z_, 1);
		}
	private:
		T x_, y_, z_, w_;
	};
}

#endif //AURORA_POINT_H_
