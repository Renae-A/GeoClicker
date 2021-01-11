#pragma once  
#include <math.h>
#include <cmath>
#include "MathFunctions.h"

namespace MathLibrary
{
	class Vector3;

	class Vector2
	{
	public:
		union
		{
			struct
			{
				float x, y;
			};
			float data[2];
		};

		// Default constructor
		MATHLIBRARY_API Vector2();

		// Constructor taking floats
		MATHLIBRARY_API Vector2(float x, float y);

		// Copy constructor
		MATHLIBRARY_API Vector2(const Vector2 &other);

		// Point + Vector
		MATHLIBRARY_API Vector2 operator + (const Vector2& other) const;

		// Point - Vector
		MATHLIBRARY_API Vector2 operator - (const Vector2& other) const;

		// Vector * Scalar
		MATHLIBRARY_API Vector2 operator * (float scalar) const;

		// Vector / Scalar
		MATHLIBRARY_API Vector2 operator / (float scalar) const;

		// Point += Vector
		MATHLIBRARY_API Vector2& operator += (const Vector2& other);

		// Point -= Vector
		MATHLIBRARY_API Vector2& operator -= (const Vector2& other);

		// Vector *= Scalar
		MATHLIBRARY_API Vector2& operator *= (float scalar);

		// Vector /= Scalar
		MATHLIBRARY_API Vector2& operator /= (float scalar);

		// Vector = Vector
		MATHLIBRARY_API Vector2& operator = (const Vector2& other);

		// Float* casting
		MATHLIBRARY_API operator const float* () const;

		MATHLIBRARY_API operator float* ();

		// Optional: Implement the sub - script operator []
		MATHLIBRARY_API float operator [] (int index) const;

		// Modifiable script operator []
		MATHLIBRARY_API float& operator[](int index);

		// Optional: implement equality operators ==
		MATHLIBRARY_API bool operator == (const Vector2& other) const;

		// Optional: implement equality operators !=
		MATHLIBRARY_API bool operator != (const Vector2& other) const;

		// Optional : Implement an inverse operator that reverses a Vector
		MATHLIBRARY_API Vector2 inverse() const;

		// Magnitude, using the format :
		// scalar = vector.magnitude()
		MATHLIBRARY_API float magnitude() const;

		// Magnitude Squared, using the format :
		// scalar = vector.magnitudeSqr()
		MATHLIBRARY_API float magnitudeSqr() const;

		// Distance between two Points, using the format :
		// scalar = point.distance(point)
		MATHLIBRARY_API float distance(const Vector2& other) const;

		// Squared Distance between two Points, using the format :
		// scalar = point.distanceSqr(point)
		MATHLIBRARY_API float distanceSqr(const Vector2& other) const;

		// Normalisation of a vector, using the format :
		// vector = vector.normalised()
		MATHLIBRARY_API Vector2 normalised() const;

		// Normalises the vector permanently
		MATHLIBRARY_API void normalise();

		// Dot Product, using the following format :
		// Scalar = vector.dot(vector)
		MATHLIBRARY_API float dot(const Vector2& other) const;

		// Cross Product, using the following format :
		// Float = vector.cross(vector)
		MATHLIBRARY_API float cross(const Vector2& other) const;

		// Optional : 2 - D Perpendicular Vector
		// Vector2 = vector2.getPerpendicular()
		MATHLIBRARY_API Vector2 getPerpendicularRH() const;

		MATHLIBRARY_API Vector2 getPerpendicularLH() const;

		// Optional : Angle Between
		// Scalar = vector.angleBetween(vector)
		MATHLIBRARY_API float angleBetween(const Vector2& other) const;

		// Up cast to Vector3
		MATHLIBRARY_API Vector3 upCast();
	};

	MATHLIBRARY_API Vector2 operator * (float scalar, Vector2& vec);
}

