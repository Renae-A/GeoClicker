#pragma once  
#include <math.h>
#include <cmath>
#include "Vector2.h"

namespace MathLibrary
{
	class Matrix2
	{
	public:
		union
		{
			struct
			{
				Vector2 xAxis;
				Vector2 yAxis;
			};
			Vector2 axis[2];
			float data[2][2];
		};

		MATHLIBRARY_API static const Matrix2 identity;

		// Default constructor
		MATHLIBRARY_API Matrix2();

		// Constructor taking Vector2s
		MATHLIBRARY_API Matrix2(Vector2 x, Vector2 y);

		// Constructor taking floats
		MATHLIBRARY_API Matrix2(float Xx, float Xy, float Yx, float Yy);

		// Copy constructor
		MATHLIBRARY_API Matrix2(const Matrix2 &other);

		// Sub - script operator [] access for each axis
		// reference access so it can be modified
		MATHLIBRARY_API Vector2& operator [] (int index);

		// const access for read-only
		MATHLIBRARY_API const Vector2& operator [] (int index) const;

		// Assignment operator
		MATHLIBRARY_API Matrix2 operator=(const Matrix2 & other);

		// A transpose method
		MATHLIBRARY_API Matrix2 transposed() const;

		// Matrix multiplication operator * overload(i.e.Matrix * Matrix)
		MATHLIBRARY_API Matrix2 operator * (const Matrix2& other) const;

		// Matrix by Vector multiplication operator * overload(i.e.Matrix * Vector)
		// binary * operator
		MATHLIBRARY_API Vector2 operator * (const Vector2& v) const;

		// Float* casting
		MATHLIBRARY_API operator const float*() const;

		// Float* casting
		MATHLIBRARY_API operator float*();

		// Matrix addition operator + overload(i.e.Matrix + Matrix)
		MATHLIBRARY_API Matrix2 operator + (const Matrix2& other) const;

		// Matrix subtraction operator – overload(i.e.Matrix – Matrix)
		MATHLIBRARY_API Matrix2 operator - (const Matrix2& other) const;

		// Method for setting up the matrices as rotation matrices :
		// Matrix2 – setRotate(float radians)
		MATHLIBRARY_API void setRotate(float radians);

		// Methods for rotating an existing matrix :
		// Matrix2 – rotate(float radians)
		MATHLIBRARY_API void rotate(float radians);

		// Methods for scaling existing matrices:
		// Matrix2 - setScaled(float x, float y) 
		MATHLIBRARY_API void setScaled(float x, float y);

		// Matrix2 – setScaled(const Vector2& v) 
		MATHLIBRARY_API void setScaled(const Vector2& v);

		// Methods for creating scale matrices:
		// scale(float x, float y)
		MATHLIBRARY_API void scale(float x, float y);

		// scale(const Vector2& v)
		MATHLIBRARY_API void scale(const Vector2& v);

		// getScale() takes the length of each axis in the matrix using Pythagoras Theorem
		MATHLIBRARY_API Vector2 getScale();

		// Matrix2 - getEuler returns float
		MATHLIBRARY_API float getEuler();

		// Matrix2 - orientateToTargetY(Vector2 target)
		MATHLIBRARY_API void orientateToTargetY(Vector2 target);
	};
}