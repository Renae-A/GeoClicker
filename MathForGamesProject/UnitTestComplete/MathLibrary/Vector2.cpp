#include "stdafx.h"
#include "Vector2.h"
#include "Vector3.h"

namespace MathLibrary
{
	//Default constructor
	Vector2::Vector2()
	{

	}

	// Constructor taking floats
	Vector2::Vector2(float X, float Y)
	{
		x = X;
		y = Y;
	}

	// Copy constructor
	Vector2::Vector2(const Vector2 & other)
	{
		x = other.x;
		y = other.y;
	}

	// Point + Vector
	Vector2 Vector2::operator+(const Vector2 & other) const
	{
		return { x + other.x, y + other.y, };
	}

	// Point - Vector
	Vector2 Vector2::operator-(const Vector2 & other) const
	{
		return { x - other.x, y - other.y, };
	}

	// Vector * Scalar
	Vector2 Vector2::operator*(float scalar) const
	{
		return { x * scalar, y * scalar };
	}

	// Vector / Scalar
	Vector2 Vector2::operator/(float scalar) const
	{
		return { x / scalar, y / scalar };
	}

	// Point += Vector
	Vector2 & Vector2::operator+=(const Vector2 & other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	// Point -= Vector
	Vector2 & Vector2::operator-=(const Vector2 & other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	// Vector *= Scalar
	Vector2 & Vector2::operator*=(float scalar)
	{
		x *= scalar;
		y *= scalar;
		return *this;
	}

	// Vector /= Scalar
	Vector2 & Vector2::operator/=(float scalar)
	{
		x /= scalar;
		y /= scalar;
		return *this;
	}

	// Vector = Vector
	Vector2 & Vector2::operator=(const Vector2 & other)
	{
		x = other.x;
		y = other.y;
		return *this;
	}

	// Float* casting
	Vector2::operator const float*() const
	{
		return data;
	}

	Vector2::operator float*()
	{
		return data;
	}

	// Optional: Implement the sub - script operator []
	float Vector2::operator[](int index) const
	{
		return data[index];
	}

	float& Vector2::operator[](int index)
	{
		return data[index];
	}

	// Optional: implement equality operators !=
	bool Vector2::operator==(const Vector2 & other) const
	{
		return (Functions::IsEqual(x, other.x) && Functions::IsEqual(y, other.y));
	}

	// Optional: implement equality operators !=
	bool Vector2::operator!=(const Vector2 & other) const
	{
		if (!operator==(other))
		{
			return true;
		}
		return false;
	}

	// Optional : Implement an inverse operator that reverses a Vector
	Vector2 Vector2::inverse() const
	{
		float inverse = -1.0f;
		return { x * inverse, y * inverse };
	}

	// Magnitude, using the format :
	// scalar = vector.magnitude()
	float Vector2::magnitude() const
	{
		float X = powf(x, x);
		float Y = powf(y, y);
		return sqrt(X + Y);
	}

	// Magnitude Squared, using the format :
	// scalar = vector.magnitudeSqr()
	float Vector2::magnitudeSqr() const
	{
		float X = powf(x, x);
		float Y = powf(y, y);
		return (X + Y);
	}

	// Distance between two Points, using the format :
	// scalar = point.distance(point)
	float Vector2::distance(const Vector2 & other) const
	{
		float diffX = x - other.x;
		float diffY = y - other.y;
		float X = powf(diffX, diffX);
		float Y = powf(diffY, diffY);

		return sqrt(X + Y);
	}

	// Squared Distance between two Points, using the format :
	// scalar = point.distanceSqr(point)
	float Vector2::distanceSqr(const Vector2 & other) const
	{
		float diffX = x - other.x;
		float diffY = y - other.y;
		float X = powf(diffX, diffX);
		float Y = powf(diffY, diffY);

		return (X + Y);
	}

	// Normalisation of a vector, using the format :
	// vector = vector.normalised()
	Vector2 Vector2::normalised() const
	{
		float mag = magnitude();
		return { x / mag, y / mag };
	}

	// Normalises the vector permanently
	void Vector2::normalise()
	{
		float mag = magnitude();

		if (mag > EPSILON)
		{
			x /= mag;
			y /= mag;
		}
	}

	// Dot Product, using the following format :
	// Scalar = vector.dot(vector)
	float Vector2::dot(const Vector2 & other) const
	{
		return { x * other.x + y * other.y };
	}

	// Cross Product, using the following format :
	// Float = vector.cross(vector)
	float Vector2::cross(const Vector2 & other) const
	{
		return { x * other.y - y * other.x };
	}

	// Optional : 2 - D Perpendicular Vector
	// Vector2 = vector2.getPerpendicular()
	Vector2 Vector2::getPerpendicularRH() const
	{
		return { -y, x };
	}

	Vector2 Vector2::getPerpendicularLH() const
	{
		return { y, -x };
	}

	float Vector2::angleBetween(const Vector2 & other) const
	{
		// normalise the vectors
		Vector2 a = normalised();
		Vector2 b = other.normalised();

		// calculate the dot product
		float d = a.x * b.x + a.y * b.y;

		// return the angle between them
		return acos(d);
	}

	// Up cast to Vector3
	Vector3 Vector2::upCast()
	{
		return Vector3(x, y, 0);
	}

	// Scalar * Vector
	Vector2 operator*(float scalar, Vector2 & vec)
	{
		return vec * scalar;
	}
}

