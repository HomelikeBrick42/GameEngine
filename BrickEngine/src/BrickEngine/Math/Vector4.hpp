#pragma once

#include "BrickEngine/Math/Vector.hpp"

namespace BrickEngine {

	template<typename T>
	struct Vector<4, T>
	{
		union { T x, r; };
		union { T y, g; };
		union { T z, b; };
		union { T w, a; };

		Vector()
			: x(0)
			, y(0)
			, z(0)
			, w(0) {}
		Vector(T scalar)
			: x(scalar)
			, y(scalar)
			, z(scalar)
			, w(scalar) {}
		Vector(T x, T y, T z, T w)
			: x(x)
			, y(y)
			, z(z)
			, w(w) {}

		static T Dot(const Vector<4, T>& v1, const Vector<4, T>& v2)
		{
			return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
		}

		T Dot(const Vector<4, T>& other) const
		{
			return Vector<4, T>::Dot(*this, other);
		}

		static T LengthSqr(const Vector<4, T>& v)
		{
			return Vector<4, T>::Dot(v, v);
		}

		T LengthSqr() const
		{
			return Vector<4, T>::LengthSqr(*this);
		}

		static T Length(const Vector<4, T>& v)
		{
			return std::sqrt(LengthSqr(v));
		}

		T Length() const
		{
			return Vector<4, T>::Length(*this);
		}

		static Vector<4, T> Normalized(const Vector<4, T>& v)
		{
			return v / Vector<4, T>::Length(v);
		}

		Vector<4, T> Normalized() const
		{
			return Vector<4, T>::Normalized(*this);
		}

		Vector<4, T> operator+(const Vector<4, T>& other) const
		{
			return Vector<4, T>(
				x + other.x,
				y + other.y,
				z + other.z,
				w + other.w
			);
		}

		Vector<4, T> operator+(T scalar) const
		{
			return Vector<4, T>(
				x + scalar,
				y + scalar,
				z + scalar,
				w + scalar
			);
		}

		Vector<4, T>& operator+=(const Vector<4, T>& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;
			return *this;
		}

		Vector<4, T>& operator+=(T scalar)
		{
			x += scalar;
			y += scalar;
			z += scalar;
			w += scalar;
			return *this;
		}

		Vector<4, T> operator-(const Vector<4, T>& other) const
		{
			return Vector<4, T>(
				x - other.x,
				y - other.y,
				z - other.z,
				w - other.w
			);
		}

		Vector<4, T> operator-(T scalar) const
		{
			return Vector<4, T>(
				x - scalar,
				y - scalar,
				z - scalar,
				w - scalar
			);
		}

		Vector<4, T>& operator-=(const Vector<4, T>& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;
			return *this;
		}

		Vector<4, T>& operator-=(T scalar)
		{
			x -= scalar;
			y -= scalar;
			z -= scalar;
			w -= scalar;
			return *this;
		}

		Vector<4, T> operator*(const Vector<4, T>& other) const
		{
			return Vector<4, T>(
				x * other.x,
				y * other.y,
				z * other.z,
				w * other.w
			);
		}

		Vector<4, T> operator*(T scalar) const
		{
			return Vector<4, T>(
				x * scalar,
				y * scalar,
				z * scalar,
				w * scalar
			);
		}

		Vector<4, T>& operator*=(const Vector<4, T>& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;
			return *this;
		}

		Vector<4, T>& operator*=(T scalar)
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;
			w *= scalar;
			return *this;
		}

		Vector<4, T> operator/(const Vector<4, T>& other) const
		{
			return Vector<4, T>(
				x / other.x,
				y / other.y,
				z / other.z,
				w / other.w
			);
		}

		Vector<4, T> operator/(T scalar) const
		{
			return Vector<4, T>(
				x / scalar,
				y / scalar,
				z / scalar,
				w / scalar
			);
		}

		Vector<4, T>& operator/=(const Vector<4, T>& other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;
			w /= other.w;
			return *this;
		}

		Vector<4, T>& operator/=(T scalar)
		{
			x /= scalar;
			y /= scalar;
			z /= scalar;
			w /= scalar;
			return *this;
		}
	};

	template<typename T>
	using Vector4				= Vector<4, T>;
	
	using Vector4uc				= Vector4<uint8>;
	using Vector4us				= Vector4<uint16>;
	using Vector4u				= Vector4<uint32>;
	using Vector4ul				= Vector4<uint64>;

	using Vector4c				= Vector4<int8>;
	using Vector4s				= Vector4<int16>;
	using Vector4i				= Vector4<int32>;
	using Vector4l				= Vector4<int64>;

	using Vector4f				= Vector4<float32>;
	using Vector4d				= Vector4<float64>;
}
