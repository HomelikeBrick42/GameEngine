#pragma once

#include "BrickEngine/Math/Vector.hpp"

namespace BrickEngine {

	template<typename T>
	struct BRICKENGINE_API Vector<1, T>
	{
		union { T x, r; };

		Vector()
			: x(0) {}
		Vector(T x)
			: x(x) {}

		static T Dot(const Vector<1, T>& v1, const Vector<1, T>& v2)
		{
			return v1.x * v1.x;
		}

		T Dot(const Vector<1, T>& other) const
		{
			return Vector<1, T>::Dot(*this, other);
		}

		static T LengthSqr(const Vector<1, T>& v)
		{
			return Vector<1, T>::Dot(v, v);
		}

		T LengthSqr() const
		{
			return Vector<1, T>::LengthSqr(*this);
		}

		static T Length(const Vector<1, T>& v)
		{
			return std::sqrt(LengthSqr(v));
		}

		T Length() const
		{
			return Vector<1, T>::Length(*this);
		}

		static Vector<1, T> Normalized(const Vector<1, T>& v)
		{
			return v / Vector<1, T>::Length(v);
		}

		Vector<1, T> Normalized() const
		{
			return Vector<1, T>::Normalized(*this);
		}

		Vector<1, T> operator+(const Vector<1, T>& other) const
		{
			return Vector<1, T>(
				x + other.x
			);
		}

		Vector<1, T> operator+(T scalar) const
		{
			return Vector<1, T>(
				x + scalar
			);
		}

		Vector<1, T>& operator+=(const Vector<1, T>& other)
		{
			x += other.x;
			return *this;
		}

		Vector<1, T>& operator+=(T scalar)
		{
			x += scalar;
			return *this;
		}

		Vector<1, T> operator-(const Vector<1, T>& other) const
		{
			return Vector<1, T>(
				x - other.x
			);
		}

		Vector<1, T> operator-(T scalar) const
		{
			return Vector<1, T>(
				x - scalar
			);
		}

		Vector<1, T>& operator-=(const Vector<1, T>& other)
		{
			x -= other.x;
			return *this;
		}

		Vector<1, T>& operator-=(T scalar)
		{
			x -= scalar;
			return *this;
		}

		Vector<1, T> operator*(const Vector<1, T>& other) const
		{
			return Vector<1, T>(
				x * other.x
			);
		}

		Vector<1, T> operator*(T scalar) const
		{
			return Vector<1, T>(
				x * scalar
			);
		}

		Vector<1, T>& operator*=(const Vector<1, T>& other)
		{
			x *= other.x;
			return *this;
		}

		Vector<1, T>& operator*=(T scalar)
		{
			x *= scalar;
			return *this;
		}

		Vector<1, T> operator/(const Vector<1, T>& other) const
		{
			return Vector<1, T>(
				x / other.x
			);
		}

		Vector<1, T> operator/(T scalar) const
		{
			return Vector<1, T>(
				x / scalar
			);
		}

		Vector<1, T>& operator/=(const Vector<1, T>& other)
		{
			x /= other.x;
			return *this;
		}

		Vector<1, T>& operator/=(T scalar)
		{
			x /= scalar;
			return *this;
		}
	};

	template<typename T>
	using Vector1				= Vector<1, T>;
	
	using Vector1uc				= Vector1<uint8>;
	using Vector1us				= Vector1<uint16>;
	using Vector1u				= Vector1<uint32>;
	using Vector1ul				= Vector1<uint64>;

	using Vector1c				= Vector1<int8>;
	using Vector1s				= Vector1<int16>;
	using Vector1i				= Vector1<int32>;
	using Vector1l				= Vector1<int64>;

	using Vector1f				= Vector1<float32>;
	using Vector1d				= Vector1<float64>;
}
