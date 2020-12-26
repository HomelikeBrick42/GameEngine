#pragma once

#include "BrickEngine/Math/Vector.hpp"

namespace BrickEngine {

	template<typename T>
	struct BRICKENGINE_API Vector<3, T>
	{
		union { T x, r; };
		union { T y, g; };
		union { T z, b; };

		Vector()
			: x(0)
			, y(0)
			, z(0) {}
		Vector(T scalar)
			: x(scalar)
			, y(scalar)
			, z(scalar) {}
		Vector(T x, T y, T z)
			: x(x)
			, y(y)
			, z(z) {}

		static T Dot(const Vector<3, T>& v1, const Vector<3, T>& v2)
		{
			return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
		}

		T Dot(const Vector<3, T>& other) const
		{
			return Vector<3, T>::Dot(*this, other);
		}

		static T LengthSqr(const Vector<3, T>& v)
		{
			return Vector<3, T>::Dot(v, v);
		}

		T LengthSqr() const
		{
			return Vector<3, T>::LengthSqr(*this);
		}

		static T Length(const Vector<3, T>& v)
		{
			return std::sqrt(LengthSqr(v));
		}

		T Length() const
		{
			return Vector<3, T>::Length(*this);
		}

		static Vector<3, T> Normalized(const Vector<3, T>& v)
		{
			return v / Vector<3, T>::Length(v);
		}

		Vector<3, T> Normalized() const
		{
			return Vector<3, T>::Normalized(*this);
		}

		Vector<3, T> operator+(const Vector<3, T>& other) const
		{
			return Vector<3, T>(
				x + other.x,
				y + other.y,
				z + other.z
			);
		}

		Vector<3, T> operator+(T scalar) const
		{
			return Vector<3, T>(
				x + scalar,
				y + scalar,
				z + scalar
			);
		}

		Vector<3, T>& operator+=(const Vector<3, T>& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			return *this;
		}

		Vector<3, T>& operator+=(T scalar)
		{
			x += scalar;
			y += scalar;
			z += scalar;
			return *this;
		}

		Vector<3, T> operator-(const Vector<3, T>& other) const
		{
			return Vector<3, T>(
				x - other.x,
				y - other.y,
				z - other.z
			);
		}

		Vector<3, T> operator-(T scalar) const
		{
			return Vector<3, T>(
				x - scalar,
				y - scalar,
				z - scalar
			);
		}

		Vector<3, T>& operator-=(const Vector<3, T>& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			return *this;
		}

		Vector<3, T>& operator-=(T scalar)
		{
			x -= scalar;
			y -= scalar;
			z -= scalar;
			return *this;
		}

		Vector<3, T> operator*(const Vector<3, T>& other) const
		{
			return Vector<3, T>(
				x * other.x,
				y * other.y,
				z * other.z
			);
		}

		Vector<3, T> operator*(T scalar) const
		{
			return Vector<3, T>(
				x * scalar,
				y * scalar,
				z * scalar
			);
		}

		Vector<3, T>& operator*=(const Vector<3, T>& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			return *this;
		}

		Vector<3, T>& operator*=(T scalar)
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;
			return *this;
		}

		Vector<3, T> operator/(const Vector<3, T>& other) const
		{
			return Vector<3, T>(
				x / other.x,
				y / other.y,
				z / other.z
			);
		}

		Vector<3, T> operator/(T scalar) const
		{
			return Vector<3, T>(
				x / scalar,
				y / scalar,
				z / scalar
			);
		}

		Vector<3, T>& operator/=(const Vector<3, T>& other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;
			return *this;
		}

		Vector<3, T>& operator/=(T scalar)
		{
			x /= scalar;
			y /= scalar;
			z /= scalar;
			return *this;
		}
	};

	template<typename T>
	using Vector3				= Vector<3, T>;
	
	using Vector3uc				= Vector3<uint8>;
	using Vector3us				= Vector3<uint16>;
	using Vector3u				= Vector3<uint32>;
	using Vector3ul				= Vector3<uint64>;

	using Vector3c				= Vector3<int8>;
	using Vector3s				= Vector3<int16>;
	using Vector3i				= Vector3<int32>;
	using Vector3l				= Vector3<int64>;

	using Vector3f				= Vector3<float32>;
	using Vector3d				= Vector3<float64>;
}
