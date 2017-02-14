#ifndef AURORA_VECTOR_HPP_
#define AURORA_VECTOR_HPP_

#include <cmath>
#include <iostream>

namespace Aurora
{
	template <typename T>
	class Vector2D_T
	{
	public:
		Vector2D_T():x_(0), y_(0){}
		Vector2D_T(const T t):x_(t), y_(t){}
		Vector2D_T(const T x, const T y):x_(x), y_(y){}
		Vector2D_T(const Vector2D_T<T> &v):x_(v.x_), y_(v.y_){}
		Vector2D_T<T>& operator = (const Vector2D_T<T> &v)
		{
			x_ = v.x_;
			y_ = v.y_;
			return *this;
		}

		bool operator == (const Vector2D_T<T> &v) const
		{
			return x_ == v.x_ && y_ == v.y_;
		}
		bool operator != (const Vector2D_T<T> &v) const
		{
			return !operator == (v);
		}

		Vector2D_T<T> operator + (const Vector2D_T<T> &v) const
		{
			return Vector2D_T<T>(x_ + v.x_, y_ + v.y_);
		}
		Vector2D_T<T>& operator += (const Vector2D_T<T> &v)
		{
			x_ += v.x_;
			y_ += v.y_;
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
			return Vector2D_T<T>(x_ * u, y_ * u);
		}
		template <typename U>
		Vector2D_T<T>& operator *= (const U u)
		{
			x_ *= u;
			y_ *= u;
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
			return Vector2D_T<T> (-x_, -y_);
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

		T Length2() const
		{
			return x_ * x_ + y_ * y_;
		}
		T Length() const
		{
			return sqrt(Length());
		}

		friend std::ostream& operator << (std::ostream &out, const Vector2D_T<T> &v)
		{
			out << v.x() << ' ' << v.y() << std::endl;
		}
		friend std::istream& operator >> (std::istream &in, Vector2D_T<T> &v)
		{
			in >> v.x() >> v.y();
		}
	private:
		T x_, y_;
	};

	template <typename T>
	Vector2D_T<T> Normalize(const Vector2D_T<T> &v)
	{
		return v / v.Length2();
	}
	template <typename T>
	T Dot(const Vector2D_T<T> &lhs, const Vector2D_T<T> &rhs)
	{
		return lhs.x() * rhs.x() + lhs.y() * rhs.y();
	}

	template <typename T>
	class Vector3D_T
	{
	public:
		Vector3D_T():x_(0), y_(0), z_(0){}
		Vector3D_T(const T t):x_(t), y_(t), z_(t){}
		Vector3D_T(const T x, const T y, const T z):x_(x), y_(y), z_(z){}
		Vector3D_T(const Vector3D_T<T> &v):x_(v.x_), y_(v.y_), z_(v.z_){}
		Vector3D_T<T>& operator = (const Vector3D_T<T> &v)
		{
			x_ = v.x_;
			y_ = v.y_;
			z_ = v.z_;
			return *this;
		}

		bool operator == (const Vector3D_T<T> &v) const
		{
			return x_ == v.x_ && y_ == v.y_ && z_ == v.z_;
		}
		bool operator != (const Vector3D_T<T> &v) const
		{
			return !operator == (v);
		}

		Vector3D_T<T> operator + (const Vector3D_T<T> &v) const
		{
			return Vector3D_T<T>(x_ + v.x_, y_ + v.y_, z_ + v.z_);
		}
		Vector3D_T<T>& operator += (const Vector3D_T<T> &v)
		{
			x_ += v.x_;
			y_ += v.y_;
			z_ += v.z_;
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
			return Vector3D_T<T>(x_ * u, y_ * u, z_ * u);
		}
		template <typename U>
		Vector3D_T<T>& operator *= (const U u)
		{
			x_ *= u;
			y_ *= u;
			z_ *= u;
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
			return Vector3D_T<T> (-x_, -y_, -z_);
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

		T Length2() const
		{
			return x_ * x_ + y_ * y_ + z_ * z_;
		}
		T Length() const
		{
			return sqrt(Length2());
		}

		friend std::ostream& operator << (std::ostream &out, const Vector3D_T<T> &v)
		{
			out << v.x() << ' ' << v.y() << ' ' << v.z() << std::endl;
		}
		friend std::istream& operator >> (std::istream &in, Vector3D_T<T> &v)
		{
			in >> v.x() >> v.y() >> v.z();
		}
	private:
		T x_, y_, z_;
	};

	template <typename T>
	Vector3D_T<T> Normalize(const Vector3D_T<T> &v)
	{
		return v / v.Length();
	}
	template <typename T>
	Vector3D_T<T> Cross(const Vector3D_T<T> &lhs, const Vector3D_T<T> &rhs)
	{
		return Vector3D_T<T>(
			lhs.y() * rhs.z() - lhs.z() * rhs.y(),
			lhs.z() * rhs.x() - lhs.x() * rhs.z(),
			lhs.x() * rhs.y() - lhs.y() * rhs.x());
	}
	template <typename T>
	T Dot(const Vector3D_T<T> &lhs, const Vector3D_T<T> &rhs)
	{
		return lhs.x() * rhs.x() + lhs.y() * rhs.y() + lhs.z() * rhs.z();
	}

	template <typename T>
	class Vector4D_T
	{
	public:
		Vector4D_T():x_(0), y_(0), z_(0), w_(0){}
		Vector4D_T(const T t):x_(t), y_(t), z_(t), w_(0){}
		Vector4D_T(const T x, const T y, const T z, const T w = 0):x_(x), y_(y), z_(z), w_(w){}
		Vector4D_T(const Vector4D_T<T> &v):x_(v.x_), y_(v.y_), z_(v.z_), w_(0){}
		Vector4D_T<T>& operator = (const Vector4D_T<T> &v)
		{
			x_ = v.x_;
			y_ = v.y_;
			z_ = v.z_;
			w_ = 0;
			return *this;
		}

		bool operator == (const Vector4D_T<T> &v) const
		{
			return x_ == v.x_ && y_ == v.y_ && z_ == v.z_ && w_ == v.w_;
		}
		bool operator != (const Vector4D_T<T> &v)
		{
			return !operator == (v);
		}

		Vector4D_T<T> operator + (const Vector4D_T<T> &v) const
		{
			return Vector4D_T<T>(x_ + v.x_, y_ + v.y_, z_ + v.z_, 0);
		}
		Vector4D_T<T>& operator += (const Vector4D_T<T> &v)
		{
			x_ += v.x_;
			y_ += v.y_;
			z_ += v.z_;
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

		template <typename U>
		Vector4D_T<T> operator * (const U u) const
		{
			return Vector4D_T<T>(x_ * u, y_ * u, z_ * u);
		}
		template <typename U>
		Vector4D_T<T>& operator *= (const U u)
		{
			x_ *= u;
			y_ *= u;
			z_ *= u;
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
			return Vector4D_T<T>(-x_, -y_, -z_, 0);
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

		T Length2() const
		{
			return x_ * x_ + y_ * y_ + z_ * z_;
		}
		T Length() const
		{
			return sqrt(Length2());
		}

		friend std::ostream& operator << (std::ostream &out, const Vector4D_T<T> &v)
		{
			out << v.x() << ' ' << v.y() << ' ' << v.z() << ' ' << v.w() << std::endl;
		}
		friend std::istream& operator >> (std::istream &in, Vector4D_T<T> &v)
		{
			in >> v.x() >> v.y() >> v.z();
		}
	private:
		T x_, y_, z_, w_;
	};

	template <typename T>
	Vector4D_T<T> Normalize(const Vector4D_T<T> &v)
	{
		return v / v.Length();
	}
	template <typename T>
	Vector4D_T<T> Cross(const Vector4D_T<T> &lhs, const Vector4D_T<T> &rhs)
	{
		return Vector4D_T<T>(
			lhs.y() * rhs.z() - lhs.z() * rhs.y(),
			lhs.z() * rhs.x() - lhs.x() * rhs.z(),
			lhs.x() * rhs.y() - lhs.y() * rhs.x());

	}
	template <typename T>
	T Dot(const Vector4D_T<T> &lhs, const Vector4D_T<T> &rhs)
	{
		return lhs.x() * rhs.x() + lhs.y() * rhs.y() + lhs.z() * rhs.z();
	}
}

#endif //AURORA_VECTOR_HPP_
