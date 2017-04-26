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
		Point2D_T(const T t = 0):x_(t), y_(t){}
		Point2D_T(const T x, const T y):x_(x), y_(y){}
		Point2D_T(const Point2D_T<T> &p):x_(p.x_), y_(p.y_){}
		Point2D_T<T>& operator = (const Point2D_T<T> &p)
		{
			x_ = p.x_;
			y_ = p.y_;
			return *this;
		}

		bool operator == (const Point2D_T<T> &p)
		{
			return x_ == p.x_ && y_ == p.y;
		}
		bool operator != (const Point2D_T<T> &p)
		{
			return !operator == (p);
		}

		Point2D_T<T> operator + (const Point2D_T<T> &p) const
		{
			return Point2D_T<T>(x_ + p.x_, y_ + p.y_);
		}
		Point2D_T<T> operator + (const Vector2D_T<T> &v) const
		{
			return Point2D_T<T>(x_ + v.x(), y_ + v.y());
		}
		Point2D_T<T>& operator += (const Vector2D_T<T> &v){
			x_ += v.x();
			y_ += v.y();
			return *this;
		}
		Vector2D_T<T> operator - (const Point2D_T<T> &p) const
		{
			return Vector2D_T<T>(x_ - p.x_, y_ - p.y_);
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
			return Point2D_T<T>(x_ * u, y_ * u);
		}
		template <typename U>
		Point2D_T<T>& operator *= (const U u)
		{
			x_ *= u;
			y_ *= u;
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
			return Point2D_T<T>(-x_, -y_);
		}

		T& x()
		{
			return x_;
		}
		const T& x() const
		{
			return x_;
		}
		T& y()
		{
			return y_;
		}
		const T& y() const
		{
			return y_;
		}

		friend std::ostream& operator << (std::ostream &out, const Point2D_T<T> &p)
		{
			out << p.x() << ' ' << p.y();
			return out;
		}
		friend std::istream& operator >> (std::istream &in, Point2D_T<T> &p)
		{
			in >> p.x() >> p.y();
			return in;
		}
		bool operator > (const Point2D_T<T> &p)
		{
			return y_ > p.y_;
		}
		bool operator < (const Point2D_T<T> &p)
		{
			return y_ < p.y_;
		}
	private:
		T x_, y_;
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
		Point3D_T(const T t = 0):x_(t), y_(t), z_(t){}
		Point3D_T(const T x, const T y, const T z):x_(x), y_(y), z_(z){}
		Point3D_T(const Point3D_T<T> &p):x_(p.x_), y_(p.y_), z_(p.z_){}
		Point3D_T<T>& operator = (const Point3D_T<T> &p)
		{
			x_ = p.x_;
			y_ = p.y_;
			z_ = p.z_;
			return *this;
		}

		bool operator == (const Point3D_T<T> &p)
		{
			return x_ == p.x_ && y_ == p.y_ && z_ == p.z_;
		}
		bool operator != (const Point3D_T<T> &p)
		{
			return !operator == (p);
		}

		Point3D_T<T> operator + (const Point3D_T<T> &p) const
		{
			return Point3D_T<T>(x_ + p.x_, y_ + p.y_, z_ + p.z_);
		}
		Point3D_T<T> operator + (const Vector3D_T<T> &v) const
		{
			return Point3D_T<T>(x_ + v.x(), y_ + v.y(), z_ + v.z());
		}
		Point3D_T<T>& operator += (const Vector3D_T<T> &v){
			x_ += v.x();
			y_ += v.y();
			z_ += v.z();
			return *this;
		}
		Vector3D_T<T> operator - (const Point3D_T<T> &p) const
		{
			return Vector3D_T<T>(x_ - p.x_, y_ - p.y_, z_ - p.z_);
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
			return Point3D_T<T>(x_ * u, y_ * u, z_ * u);
		}
		template <typename U>
		Point3D_T<T>& operator *= (const U u)
		{
			x_ *= u;
			y_ *= u;
			z_ *= u;
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
			return Point3D_T<T>(-x_, -y_, -z_);
		}

		T& x()
		{
			return x_;
		}
		const T& x() const
		{
			return x_;
		}
		T& y()
		{
			return y_;
		}
		const T& y() const
		{
			return y_;
		}
		T& z()
		{
			return z_;
		}
		const T& z() const
		{
			return z_;
		}

		friend std::ostream& operator << (std::ostream &out, const Point3D_T<T> &p)
		{
			out << p.x() << ' ' << p.y() << ' ' << p.z();
			return out;
		}
		friend std::istream& operator >> (std::istream &in, Point3D_T<T> &p)
		{
			in >> p.x() >> p.y() >> p.z();
			return in;
		}
	private:
		T x_, y_, z_;
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
		Point4D_T(const T t = 0, const T w = 1):x_(t), y_(t), z_(t), w_(w){}
		Point4D_T(const T x, const T y, const T z, const T w = 1):x_(x), y_(y), z_(z), w_(w){}
		Point4D_T(const Point4D_T<T> &p):x_(p.x_), y_(p.y_), z_(p.z_), w_(p.w_){}
		Point4D_T<T>& operator = (const Point4D_T<T> &p)
		{
			x_ = p.x_;
			y_ = p.y_;
			z_ = p.z_;
			w_ = p.w_;
			return *this;
		}

		bool operator == (const Point4D_T<T> &p)
		{
			return x_ == p.x_ && y_ == p.y_ && z_ == p.z_ && w_ == p.w_;
		}
		bool operator != (const Point4D_T<T> &p)
		{
			return !operator == (p);
		}

		Point4D_T<T> operator + (const Point4D_T<T> &p) const
		{
			return Point4D_T<T>(x_ + p.x_, y_ + p.y_, z_ + p.z_, w_ + p.w_);
		}
		Point4D_T<T> operator + (const Vector4D_T<T> &v) const
		{
			return Point4D_T<T>(x_ + v.x(), y_ + v.y() ,z_ + v.z(), w_ + v.w());
		}
		Point4D_T<T>& operator += (const Vector4D_T<T> &v)
		{
			x_ += v.x();
			y_ += v.y();
			z_ += v.z();
			w_ += v.w();
			return *this;
		}
		Vector4D_T<T> operator - (const Point4D_T<T> &p) const
		{
			return Vector4D_T<T>(x_ - p.x_, y_ - p.y_, z_ - p.z_, w_ - p.w_);
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
			return Point4D_T<T>(
					x_ * m(0, 0) + y_ * m(1, 0) + z_ * m(2, 0) + w_ * m(3, 0),
					x_ * m(0, 1) + y_ * m(1, 1) + z_ * m(2, 1) + w_ * m(3, 1),
					x_ * m(0, 2) + y_ * m(1, 2) + z_ * m(2, 2) + w_ * m(3, 2),
					x_ * m(0, 3) + y_ * m(1, 3) + z_ * m(2, 3) + w_ * m(3, 3)
					);
		}
		Point4D_T<T>& operator *= (const Matrix4_T<T> &m)
		{
			*this = operator * (m);
			return *this;
		}

		template <typename U>
		Point4D_T<T> operator * (const U u) const
		{
			return Point4D_T<T>(x_ * u, y_ * u, z_ * u, w_);
		}
		template <typename U>
		Point4D_T<T>& operator *= (const U u)
		{
			x_ *= u;
			y_ *= u;
			z_ *= u;
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
			return Point4D_T<T>(-x_, -y_, -z_, -w_);
		}

		T& x()
		{
			return x_;
		}
		const T& x() const
		{
			return x_;
		}
		T& y()
		{
			return y_;
		}
		const T& y() const
		{
			return y_;
		}
		T& z()
		{
			return z_;
		}
		const T& z() const
		{
			return z_;
		}
		T& w()
		{
			return w_;
		}
		const T& w() const
		{
			return w_;
		}

		friend std::ostream& operator << (std::ostream &out, const Point4D_T<T> &p)
		{
			out << p.x() << ' ' << p.y() << ' ' << p.z() << ' ' << p.w();
			return out;
		}
		friend std::istream& operator >> (std::istream &in, Point4D_T<T> &p)
		{
			in >> p.x() >> p.y() >> p.z();
			return in;
		}
	private:
		T x_, y_, z_, w_;
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
