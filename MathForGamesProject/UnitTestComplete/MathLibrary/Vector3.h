#pragma once  
#include <math.h>
#include <cmath>
#include "MathFunctions.h"

namespace MathLibrary
{
	class Vector2;
	class Vector4;

	class Vector3
	{
	public:
		union
		{
			struct
			{
				float x, y;
				union
				{
					float z, w;
				};
			};
			float data[3];
		};

		// Default constructor
		MATHLIBRARY_API Vector3();

		// Constructor taking floats
		MATHLIBRARY_API Vector3(float x, float y, float z);

		// Copy constructor
		MATHLIBRARY_API Vector3(const Vector3 &other);

		// Point + Vector
		MATHLIBRARY_API Vector3 operator + (const Vector3& other) const;

		// Point - Vector
		MATHLIBRARY_API Vector3 operator - (const Vector3& other) const;

		// Vector * Scalar
		MATHLIBRARY_API Vector3 operator * (float scalar) const;

		// Vector / Scalar
		MATHLIBRARY_API Vector3 operator / (float scalar) const;

		// Point += Vector
		MATHLIBRARY_API Vector3& operator += (const Vector3& other);

		// Point -= Vector
		MATHLIBRARY_API Vector3& operator -= (const Vector3& other);

		// Vector *= Scalar
		MATHLIBRARY_API Vector3& operator *= (float scalar);

		// Vector /= Scalar
		MATHLIBRARY_API Vector3& operator /= (float scalar);

		// Vector = Vector
		MATHLIBRARY_API Vector3& operator = (const Vector3& other);

		// Float* casting
		MATHLIBRARY_API operator const float* () const;

		MATHLIBRARY_API operator float* ();

		// Optional: Implement the sub - script operator []
		MATHLIBRARY_API float operator [] (int index) const;

		// Modifiable script operator []
		MATHLIBRARY_API float& operator[](int index);

		// Optional: implement equality operators ==
		MATHLIBRARY_API bool operator == (const Vector3& other) const;

		// Optional: implement equality operators !=
		MATHLIBRARY_API bool operator != (const Vector3& other) const;

		// Optional : Implement an inverse operator that reverses a Vector
		MATHLIBRARY_API Vector3 inverse() const;

		// Magnitude, using the format :
		// scalar = vector.magnitude()
		MATHLIBRARY_API float magnitude() const;

		// Magnitude Squared, using the format :
		// scalar = vector.magnitudeSqr()
		MATHLIBRARY_API float magnitudeSqr() const;

		// Distance between two Points, using the format :
		// scalar = point.distance(point)
		MATHLIBRARY_API float distance(const Vector3& other) const;

		// Squared Distance between two Points, using the format :
		// scalar = point.distanceSqr(point)
		MATHLIBRARY_API float distanceSqr(const Vector3& other) const;

		// Normalisation of a vector, using the format :
		// vector = vector.normalised()
		MATHLIBRARY_API Vector3 normalised() const;

		// Normalises the vector permanently
		MATHLIBRARY_API void normalise();

		// Dot Product, using the following format :
		// Scalar = vector.dot(vector)
		MATHLIBRARY_API float dot(const Vector3& other) const;

		// Cross Product, using the following format :
		// Vector = vector.cross(vector)
		MATHLIBRARY_API Vector3 cross(const Vector3& other) const;

		// Optional : Angle Between
		// Scalar = vector.angleBetween(vector)
		MATHLIBRARY_API float angleBetween(const Vector3& other) const;

		// Swizzling xy 
		MATHLIBRARY_API Vector2 xy();

		// Swizzling xz
		MATHLIBRARY_API Vector2 xz();

		// Up cast to Vector4
		MATHLIBRARY_API Vector4 upCast();
	};

	MATHLIBRARY_API Vector3 operator * (float scalar, Vector3& vec);
}