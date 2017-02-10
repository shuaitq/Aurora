#ifndef AURORA_VECTOR_HPP_
#define AURORA_VECTOR_HPP_

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
		Vector2D_T<T>& operator=(const Vector2D_T<T> &v)
		{
			x_ = v.x_;
			y_ = v.y_;
			return *this;
		}

		bool operator==(const Vector2D_T<T> &v) const
		{
			return x_ == v.x_ && y_ == v.y_;
		}
		bool operator!=(const Vector2D_T<T> &v) const
		{
			return !operator==(v);
		}

		Vector2D_T<T> operator+(const Vector2D_T<T> &v) const
		{
			return Vecotr2D_T<T>(x_ + v.x_, y_ + v.y_);
		}
		Vector2D_T<T>& operator+=(const Vector2D_T<T> &v)
		{
			x_ += v.x_;
			y_ += v.y_;
			return *this;
		}
		Vector2D_T<T> operator-(const Vector2D_T<T> &v) const
		{
			return *this + (-v);
		}
		Vector2D_T<T>& operator-=(const Vector2D_T<T> &v)
		{
			return *this += (-v);
		}

		template <typename U>
		Vector2D_T<T> operator*(const U u) const
		{
			return Vector2D_T<T>(x_ * u, y_ * u);
		}
		template <typename U>
		Vector2D_T<T>& operator*=(const U u)
		{
			x_ *= u;
			y_ *= u;
			return *this;
		}
		Vector2D_T<T> operator/(const U u) const
		{
			return operator*(T(1) / u);
		}
		Vector2D_T<T>& operator/=(const U u)
		{
			return operator*=(T(1) / u);
		}

		Vector2D_T<T> operator-() const
		{
			return Vector2D_T<T> (-x_, -y_);
		}
	private:
		T x_, y_;
	}

	template <typename T>
	class Vector3D_T
	{
	public:
		Vector3D_T():x_(0), y_(0), z_(0){}
		Vector3D_T(const T t):x_(t), y_(t), z_(t){}
		Vector3D_T(const T x, const T y, const T z):x_(x), y_(y), z_(z){}
		Vector3D_T(const Vector3D_T<T> &v):x_(v.x_), y_(v.y_), z_(v.z_){}
		Vector3D_T<T>& operator=(const Vector3D_T<T> &v)
		{
			x_ = v.x_;
			y_ = v.y_;
			z_ = v.z_;
			return *this;
		}

		bool operator==(const Vector3D_T<T> &v) const
		{
			return x_ == v.x_ && y_ == v.y_ && z_ == v.z_;
		}
		bool operator!=(const Vector3D_T<T> &v) const
		{
			return !operator==(v);
		}

		Vector3D_T<T> operator+(const Vector3D_T<T> &v) const
		{
			return Vecotr3D_T<T>(x_ + v.x_, y_ + v.y_, z_ + v.z_);
		}
		Vector3D_T<T>& operator+=(const Vector3D_T<T> &v)
		{
			x_ += v.x_;
			y_ += v.y_;
			z_ += v.z_;
			return *this;
		}
		Vector3D_T<T> operator-(const Vector3D_T<T> &v) const
		{
			return *this + (-v);
		}
		Vector3D_T<T>& operator-=(const Vector3D_T<T> &v)
		{
			return *this += (-v);
		}

		template <typename U>
		Vector3D_T<T> operator*(const U u) const
		{
			return Vector3D_T<T>(x_ * u, y_ * u, z_ * u);
		}
		template <typename U>
		Vector3D_T<T>& operator*=(const U u)
		{
			x_ *= u;
			y_ *= u;
			z_ *= u;
			return *this;
		}
		Vector3D_T<T> operator/(const U u) const
		{
			return operator*(T(1) / u);
		}
		Vector3D_T<T>& operator/=(const U u)
		{
			return operator*=(T(1) / u);
		}

		Vector3D_T<T> operator-() const
		{
			return Vector3D_T<T> (-x_, -y_, -z_);
		}
	private:
		T x_, y_, z_;
	}

	template <typename T>
	class Vector4D_T
	{
	public:
		Vector4D_T():x_(0), y_(0), z_(0), w_(0){}
		Vector4D_T(const T t):x_(t), y_(t), z_(t), w_(0){}
		Vector4D_T(const T x, const T y, const T z):x_(x), y_(y), z_(z), w_(0){}
		Vector4D_T(const Vector4D_T<T> &v):x_(v.x_), y_(v.y_), z_(v.z_), w_(0){}
		Vector4D_T<T>& operator=(const Vector4D_T<T>)
		{
			x_ = v.x_;
			y_ = v.y_;
			z_ = v.z_;
			w_ = 0;
			return *this;
		}

		bool operator==(const Vector4D_T<T> &v) const
		{
			return x_ == v.x_ && y_ == v.y_ && z_ == v.z_ && w_ == v.w_;
		}
		bool operator!=(const Vector4D_T<T>)
		{
			return !operator==(v);
		}

		Vector4D_T<T> operator+(const Vector4D_T<T> &v) const
		{
			return Vector4D_T<T>(x_ + v.x_, y_ + v.y_, z_ + v.z_, 0);
		}
		Vector4D_T<T>& operator+=(const Vector4D_T<T> &v)
		{
			x_ += v.x_;
			y_ += v.y_;
			z_ += v.z_;
			return *this;
		}
		Vector4D_T<T> operator-(const Vector4D_T<T> &v) const
		{
			return *this + (-v);
		}
		Vector4D_T<T>& operator-=(const Vector4D_T<T> &v)
		{
			return *this += (-v);
		}

		template <typename U>
		Vector4D_T<T> operator*(const U u) const
		{
			return Vector4D_T<T>(x_ * u, y_ * u, z_ * u);
		}
		template <typename U>
		Vector4D_T<T>& operator*=(const U u)
		{
			x_ *= u;
			y_ *= u;
			z_ *= u;
			return *this;
		}
		template <typename U>
		Vector4D_T<T> operator/(const U u) const
		{
			return *this*(T(1) / u);
		}
		template <typename U>
		Vector4D_T<T>& operator/=(const U u)
		{
			return *this*=(T(1) / u);
		}

		Vector4D_T<T> operator-() const
		{
			return Vector4D_T<T>(-x_, -y_, -z_, 0);
		}
	private:
		T x_, y_, z_, w_;
	}
}

#endif //AURORA_VECTOR_HPP_
