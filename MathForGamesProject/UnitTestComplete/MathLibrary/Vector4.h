#pragma once  
#include <math.h>
#include <cmath>
#include "MathFunctions.h"
#include "Vector3.h"

namespace MathLibrary
{
	class Vector3;

	class Vector4
	{
	public:
		union
		{
			struct
			{
				float x, y, z, w;
			};
			float data[4];
		};

		// Default constructor
		MATHLIBRARY_API Vector4();

		// Constructor taking floats
		MATHLIBRARY_API Vector4(float x, float y, float z, float w);

		// Copy constructor
		MATHLIBRARY_API Vector4(const Vector4 &other);

		// Point + Vector
		MATHLIBRARY_API Vector4 operator + (const Vector4& other) const;

		// Point - Vector
		MATHLIBRARY_API Vector4 operator - (const Vector4& other) const;

		// Vector * Scalar
		MATHLIBRARY_API Vector4 operator * (float scalar) const;

		// Vector / Scalar
		MATHLIBRARY_API Vector4 operator / (float scalar) const;

		// Point += Vector
		MATHLIBRARY_API Vector4& operator += (const Vector4& other);

		// Point -= Vector
		MATHLIBRARY_API Vector4& operator -= (const Vector4& other);

		// Vector *= Scalar
		MATHLIBRARY_API Vector4& operator *= (const Vector4& other);

		// Vector /= Scalar
		MATHLIBRARY_API Vector4& operator /= (float scalar);

		// Vector = Vector
		MATHLIBRARY_API Vector4& operator = (const Vector4& other);

		// Float* casting
		MATHLIBRARY_API operator const float* () const;

		MATHLIBRARY_API operator float* ();

		// Optional: Implement the sub - script operator []
		MATHLIBRARY_API float operator [] (int index) const;

		// Modifiable script operator []
		MATHLIBRARY_API float& operator[](int index);

		// Optional: implement equality operators ==
		MATHLIBRARY_API bool operator == (const Vector4& other) const;

		// Optional: implement equality operators !=
		MATHLIBRARY_API bool operator != (const Vector4& other) const;

		// Optional : Implement an inverse operator that reverses a Vector
		MATHLIBRARY_API Vector4 inverse() const;

		// Magnitude, using the format :
		// scalar = vector.magnitude()
		MATHLIBRARY_API float magnitude() const;

		// Magnitude Squared, using the format :
		// scalar = vector.magnitudeSqr()
		MATHLIBRARY_API float magnitudeSqr() const;

		// Distance between two Points, using the format :
		// scalar = point.distance(point)
		MATHLIBRARY_API float distance(const Vector4& other) const;

		// Squared Distance between two Points, using the format :
		// scalar = point.distanceSqr(point)
		MATHLIBRARY_API float distanceSqr(const Vector4& other) const;

		// Normalisation of a vector, using the format :
		// vector = vector.normalised()
		MATHLIBRARY_API Vector4 normalised() const;

		// Normalises the vector permanently
		MATHLIBRARY_API void normalise();

		// Dot Product, using the following format :
		// Scalar = vector.dot(vector)
		MATHLIBRARY_API float dot(const Vector4& other) const;

		// Cross Product, using the following format :
		// Vector = vector.cross(vector)
		MATHLIBRARY_API Vector4 cross(const Vector4& other) const;

		// Optional : Angle Between
		// Scalar = vector.angleBetween(vector)
		MATHLIBRARY_API float angleBetween(const Vector4& other) const;

		// Swizzling xyz
		MATHLIBRARY_API Vector3 xyz();

		// Swizzling xzy (swaps y and z)
		MATHLIBRARY_API Vector3 xzy();
	};

	MATHLIBRARY_API Vector4 operator * (float scalar, Vector4& vec);
}
