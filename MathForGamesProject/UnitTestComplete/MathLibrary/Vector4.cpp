#include "stdafx.h"
#include "Vector4.h"
#include "Vector3.h"

namespace MathLibrary
{
	//Default constructor
	Vector4::Vector4()
	{

	}

	// Constructor taking floats
	Vector4::Vector4(float X, float Y, float Z, float W)
	{
		x = X;
		y = Y;
		z = Z;
		w = W;
	}

	// Copy constructor
	Vector4::Vector4(const Vector4 & other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
		w = other.w;
	}

	// Point + Vector
	Vector4 Vector4::operator+(const Vector4 & other) const
	{
		return { x + other.x, y + other.y, z + other.z, w + other.w };
	}

	// Point - Vector
	Vector4 Vector4::operator-(const Vector4 & other) const
	{
		return { x - other.x, y - other.y, z - other.z, w - other.w };
	}

	// Vector * Scalar
	Vector4 Vector4::operator*(float scalar) const
	{
		return { x * scalar, y * scalar, z * scalar, w * scalar };
	}

	// Vector / Scalar
	Vector4 Vector4::operator/(float scalar) const
	{
		return { x / scalar, y / scalar, z / scalar, w / scalar };
	}

	// Point += Vector
	Vector4 & Vector4::operator+=(const Vector4 & other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;
		return *this;
	}

	// Point -= Vector
	Vector4 & Vector4::operator-=(const Vector4 & other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;
		return *this;
	}

	// Vector *= Scalar
	Vector4 & Vector4::operator*=(const Vector4 & other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		w *= other.w;
		return *this;
	}

	// Vector /= Scalar
	Vector4 & Vector4::operator/=(float scalar)
	{
		x /= scalar;
		y /= scalar;
		z /= scalar;
		w /= scalar;
		return *this;
	}

	// Vector = Vector
	Vector4 & Vector4::operator=(const Vector4 & other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
		w = other.w;
		return *this;
	}

	// Float* casting
	Vector4::operator const float*() const
	{
		return data;
	}

	Vector4::operator float*()
	{
		return data;
	}

	// Optional: Implement the sub - script operator []
	float Vector4::operator[](int index) const
	{
		return data[index];
	}

	float & Vector4::operator[](int index)
	{
		return data[index];
	}

	// Optional: implement equality operators ==
	bool Vector4::operator==(const Vector4 & other) const
	{
		return (Functions::IsEqual(x, other.x) && Functions::IsEqual(y, other.y) && Functions::IsEqual(z, other.z) && Functions::IsEqual(w, other.w));
	}

	// Optional: implement equality operators !=
	bool Vector4::operator!=(const Vector4& other) const
	{
		if (!operator==(other))
		{
			return true;
		}
		return false;
	}

	// Optional : Implement an inverse operator that reverses a Vector
	Vector4 Vector4::inverse() const
	{
		float inverse = -1.0f;
		return { x * inverse, y * inverse, z * inverse, w * inverse };
	}

	// Magnitude, using the format :
	// scalar = vector.magnitude()
	float Vector4::magnitude() const
	{
		return sqrt(x * x + y * y + z * z);
	}

	// Magnitude Squared, using the format :
	// scalar = vector.magnitudeSqr()
	float Vector4::magnitudeSqr() const
	{
		return (x * x + y * y + z * z);
	}

	// Distance between two Points, using the format :
	// scalar = point.distance(point)
	float Vector4::distance(const Vector4 & other) const
	{
		return (other - *this).magnitude();
	}

	// Squared Distance between two Points, using the format :
	// scalar = point.distanceSqr(point)
	float Vector4::distanceSqr(const Vector4 & other) const
	{
		return ((other - *this).magnitude() * (other - *this).magnitude());
	}

	// Normalisation of a vector, using the format :
	// vector = vector.normalised()
	Vector4 Vector4::normalised() const
	{
		float mag = magnitude();
		return { x / mag, y / mag, z / mag, w / mag };
	}

	// Normalises the vector permanently
	void Vector4::normalise()
	{
		float mag = magnitude();
		(*this) /= mag;
	}

	// Dot Product, using the following format :
	// Scalar = vector.dot(vector)
	float Vector4::dot(const Vector4 & other) const
	{
		return x * other.x + y * other.y + z * other.z;
	}

	Vector4 Vector4::cross(const Vector4 & other) const
	{
		return { y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x, 0 };
	}

	// Optional : Angle Between
	// Scalar = vector.angleBetween(vector)
	float Vector4::angleBetween(const Vector4 & other) const
	{
		// normalise the vectors
		Vector4 a = normalised();
		Vector4 b = other.normalised();

		// calculate the dot product
		float d = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;

		// return the angle between them
		return acos(d);
	}

	// Swizzling xyz
	Vector3 Vector4::xyz()
	{
		return Vector3(x, y, z);
	}

	// Swizzling xzy
	Vector3 Vector4::xzy()
	{
		return Vector3(x, z, y);
	}

	// Scalar * Vector
	Vector4 operator*(float scalar, Vector4 & vec)
	{
		return vec * scalar;
	}
}