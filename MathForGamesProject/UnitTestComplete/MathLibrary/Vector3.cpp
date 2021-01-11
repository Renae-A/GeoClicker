#include "stdafx.h"
#include "Vector3.h"
#include "Vector2.h"
#include "Vector4.h"

namespace MathLibrary
{
	//Default constructor
	Vector3::Vector3()
	{

	}

	// Constructor taking floats
	Vector3::Vector3(float X, float Y, float Z)
	{
		x = X;
		y = Y;
		z = Z;
	}

	// Copy constructor
	Vector3::Vector3(const Vector3 & other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
	}

	// Point + Vector
	Vector3 Vector3::operator+(const Vector3 & other) const
	{
		return { x + other.x, y + other.y, z + other.z };
	}

	// Point - Vector
	Vector3 Vector3::operator-(const Vector3 & other) const
	{
		return { x - other.x, y - other.y, z - other.z };
	}

	// Vector * Scalar
	Vector3 Vector3::operator*(float scalar) const
	{
		return { x * scalar, y * scalar, z * scalar };
	}

	// Vector / Scalar
	Vector3 Vector3::operator/(float scalar) const
	{
		return { x / scalar, y / scalar, z / scalar };
	}

	// Point += Vector
	Vector3 & Vector3::operator+=(const Vector3 & other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	// Point -= Vector
	Vector3 & Vector3::operator-=(const Vector3 & other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	// Vector *= Scalar
	Vector3 & Vector3::operator*=(float scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
		return *this;
	}

	// Vector /= Scalar
	Vector3 & Vector3::operator/=(float scalar)
	{
		x /= scalar;
		y /= scalar;
		z /= scalar;
		return *this;
	}

	// Vector = Vector
	Vector3 & Vector3::operator=(const Vector3 & other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}

	// Float* casting
	Vector3::operator const float*() const
	{
		return data;
	}

	Vector3::operator float*()
	{
		return data;
	}

	// Optional: Implement the sub - script operator []
	float Vector3::operator[](int index) const
	{
		return data[index];
	}

	float & Vector3::operator[](int index)
	{
		return data[index];
	}

	// Optional: implement equality operators ==
	bool Vector3::operator==(const Vector3 & other) const
	{
		return (Functions::IsEqual(x, other.x) && Functions::IsEqual(y, other.y) && Functions::IsEqual(z, other.z));
		return false;
	}

	// Optional: implement equality operators !=
	bool Vector3::operator!=(const Vector3 & other) const
	{
		if (!operator==(other))
		{
			return true;
		}
		return false;
	}

	// Optional : Implement an inverse operator that reverses a Vector
	Vector3 Vector3::inverse() const
	{
		float inverse = -1.0f;
		return { x * inverse, y * inverse, z * inverse };
	}

	// Magnitude, using the format :
	// scalar = vector.magnitude()
	float Vector3::magnitude() const
	{
		float X = powf(x, x);
		float Y = powf(y, y);
		float Z = powf(z, z);
		return sqrt(X + Y + Z);
	}

	// Magnitude Squared, using the format :
	// scalar = vector.magnitudeSqr()
	float Vector3::magnitudeSqr() const
	{
		float X = powf(x, x);
		float Y = powf(y, y);
		float Z = powf(z, z);
		return (X + Y + Z);
	}

	// Distance between two Points, using the format :
	// scalar = point.distance(point)
	float Vector3::distance(const Vector3 & other) const
	{
		float diffX = x - other.x;
		float diffY = y - other.y;
		float diffZ = z - other.z;
		float X = powf(diffX, diffX);
		float Y = powf(diffY, diffY);
		float Z = powf(diffZ, diffZ);

		return sqrt(X + Y + Z);
	}

	// Squared Distance between two Points, using the format :
	// scalar = point.distanceSqr(point)
	float Vector3::distanceSqr(const Vector3 & other) const
	{
		float diffX = x - other.x;
		float diffY = y - other.y;
		float diffZ = z - other.z;
		float X = powf(diffX, diffX);
		float Y = powf(diffY, diffY);
		float Z = powf(diffZ, diffZ);

		return (X + Y + Z);
	}

	// Normalisation of a vector, using the format :
	// vector = vector.normalised()
	Vector3 Vector3::normalised() const
	{
		float mag = magnitude();
		return { x / mag, y / mag, z / mag };
	}

	// Normalises the vector permanently
	void Vector3::normalise()
	{
		float mag = magnitude();
		x /= mag;
		y /= mag;
		z /= mag;
	}

	// Dot Product, using the following format :
	// Scalar = vector.dot(vector)
	float Vector3::dot(const Vector3 & other) const
	{
		return x * other.x + y * other.y + z * other.z;
	}

	// Cross Product, using the following format :
	// Vector = vector.cross(vector)
	Vector3 Vector3::cross(const Vector3 & other) const
	{
		return { y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x };
	}

	// Optional : Angle Between
	// Scalar = vector.angleBetween(vector)
	float Vector3::angleBetween(const Vector3 & other) const
	{
		// normalise the vectors
		Vector3 a = normalised();
		Vector3 b = other.normalised();

		// calculate the dot product
		float d = a.x * b.x + a.y * b.y + a.z * b.z;

		// return the angle between them
		return acos(d);
	}

	// Swizzling xy
	Vector2 Vector3::xy()
	{
		return Vector2(x, y);
	}

	// Swizzling xz
	Vector2 Vector3::xz()
	{
		return Vector2(x, z);
	}

	// Up cast to Vector4
	Vector4 Vector3::upCast()
	{
		return Vector4(x, y, z, 0);
	}

	// Scalar * Vector
	Vector3 operator*(float scalar, Vector3 & vec)
	{
		return vec * scalar;
	}
}