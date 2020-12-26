#pragma once

#include "BrickEngine/Math/Vector.hpp"

namespace BrickEngine {

	template<typename T>
	struct Vector<2, T>
	{
		union { T x, r; };
		union { T y, g; };

		Vector()
			: x(0)
			, y(0) {}
		Vector(T scalar)
			: x(scalar)
			, y(scalar) {}
		Vector(T x, T y)
			: x(x)
			, y(y) {}

		static T Dot(const Vector<2, T>& v1, const Vector<2, T>& v2)
		{
			return v1.x * v2.x + v1.y * v2.y;
		}

		T Dot(const Vector<2, T>& other) const
		{
			return Vector<2, T>::Dot(*this, other);
		}

		static T LengthSqr(const Vector<2, T>& v)
		{
			return Vector<2, T>::Dot(v, v);
		}

		T LengthSqr() const
		{
			return Vector<2, T>::LengthSqr(*this);
		}

		static T Length(const Vector<2, T>& v)
		{
			return std::sqrt(LengthSqr(v));
		}

		T Length() const
		{
			return Vector<2, T>::Length(*this);
		}

		static Vector<2, T> Normalized(const Vector<2, T>& v)
		{
			return v / Vector<2, T>::Length(v);
		}

		Vector<2, T> Normalized() const
		{
			return Vector<2, T>::Normalized(*this);
		}

		Vector<2, T> operator+(const Vector<2, T>& other) const
		{
			return Vector<2, T>(
				x + other.x,
				y + other.y
			);
		}

		Vector<2, T> operator+(T scalar) const
		{
			return Vector<2, T>(
				x + scalar,
				y + scalar
			);
		}

		Vector<2, T>& operator+=(const Vector<2, T>& other)
		{
			x += other.x;
			y += other.y;
			return *this;
		}

		Vector<2, T>& operator+=(T scalar)
		{
			x += scalar;
			y += scalar;
			return *this;
		}

		Vector<2, T> operator-(const Vector<2, T>& other) const
		{
			return Vector<2, T>(
				x - other.x,
				y - other.y
			);
		}

		Vector<2, T> operator-(T scalar) const
		{
			return Vector<2, T>(
				x - scalar,
				y - scalar
			);
		}

		Vector<2, T>& operator-=(const Vector<2, T>& other)
		{
			x -= other.x;
			y -= other.y;
			return *this;
		}

		Vector<2, T>& operator-=(T scalar)
		{
			x -= scalar;
			y -= scalar;
			return *this;
		}

		Vector<2, T> operator*(const Vector<2, T>& other) const
		{
			return Vector<2, T>(
				x * other.x,
				y * other.y
			);
		}

		Vector<2, T> operator*(T scalar) const
		{
			return Vector<2, T>(
				x * scalar,
				y * scalar
			);
		}

		Vector<2, T>& operator*=(const Vector<2, T>& other)
		{
			x *= other.x;
			y *= other.y;
			return *this;
		}

		Vector<2, T>& operator*=(T scalar)
		{
			x *= scalar;
			y *= scalar;
			return *this;
		}

		Vector<2, T> operator/(const Vector<2, T>& other) const
		{
			return Vector<2, T>(
				x / other.x,
				y / other.y
			);
		}

		Vector<2, T> operator/(T scalar) const
		{
			return Vector<2, T>(
				x / scalar,
				y / scalar
			);
		}

		Vector<2, T>& operator/=(const Vector<2, T>& other)
		{
			x /= other.x;
			y /= other.y;
			return *this;
		}

		Vector<2, T>& operator/=(T scalar)
		{
			x /= scalar;
			y /= scalar;
			return *this;
		}
	};

	template<typename T>
	using Vector2				= Vector<2, T>;
	
	using Vector2uc				= Vector2<uint8>;
	using Vector2us				= Vector2<uint16>;
	using Vector2u				= Vector2<uint32>;
	using Vector2ul				= Vector2<uint64>;

	using Vector2c				= Vector2<int8>;
	using Vector2s				= Vector2<int16>;
	using Vector2i				= Vector2<int32>;
	using Vector2l				= Vector2<int64>;

	using Vector2f				= Vector2<float32>;
	using Vector2d				= Vector2<float64>;
}
