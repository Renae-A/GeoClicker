#pragma once  
#include <math.h>
#include <cmath>
#include "Vector3.h"

namespace MathLibrary
{
	class Matrix3
	{
	public:
		union
		{
			struct
			{
				Vector3 xAxis;
				Vector3 yAxis;
				union
				{
					Vector3 zAxis;
					Vector3 translation;
				};
			};
			Vector3 axis[3];
			float data[3][3];
		};

		MATHLIBRARY_API static const Matrix3 identity;

		// Default constructor
		MATHLIBRARY_API Matrix3();

		// Constructor taking Vector3s
		MATHLIBRARY_API Matrix3(Vector3 x, Vector3 y, Vector3 z);

		// Constructor taking floats
		MATHLIBRARY_API Matrix3(float Xx, float Xy, float Xz, float Yx, float Yy, float Yz, float Zx, float Zy, float Zz);

		// Copy constructor
		MATHLIBRARY_API Matrix3(const Matrix3 &other);

		// Sub - script operator [] access for each axis
		// reference access so it can be modified
		MATHLIBRARY_API Vector3& operator [] (int index);

		// const access for read-only
		MATHLIBRARY_API const Vector3& operator [] (int index) const;

		// Assignment operator
		MATHLIBRARY_API Matrix3 operator=(const Matrix3 & other);

		// A transpose method
		MATHLIBRARY_API Matrix3 transposed() const;

		// Matrix multiplication operator * overload(i.e.Matrix * Matrix)
		MATHLIBRARY_API Matrix3 operator * (const Matrix3& other) const;

		// Matrix by Vector multiplication operator * overload(i.e.Matrix * Vector)
		// binary * operator
		MATHLIBRARY_API Vector3 operator*(const Vector3 & v) const;

		// Float* casting
		MATHLIBRARY_API operator const float*() const;

		// Float* casting
		MATHLIBRARY_API operator float*();

		// Matrix addition operator + overload(i.e.Matrix + Matrix)
		MATHLIBRARY_API Matrix3 operator + (const Matrix3& other) const;

		// Matrix subtraction operator – overload(i.e.Matrix – Matrix)
		MATHLIBRARY_API Matrix3 operator - (const Matrix3& other) const;

		// Methods for setting up the matrices as rotation matrices :
		// Matrix3 – setRotateX(float radians)
		MATHLIBRARY_API void setRotateX(float radians); 

		// Matrix3 – setRotateY(float radians)
		MATHLIBRARY_API void setRotateY(float radians);

		// Matrix3 – setRotateZ(float radians)
		MATHLIBRARY_API void setRotateZ(float radians);

		// Methods for rotating an existing matrix :
		// Matrix3 – rotateX(float radians)
		MATHLIBRARY_API void rotateX(float radians);

		// Matrix3 – rotateY(float radians)
		MATHLIBRARY_API void rotateY(float radians);

		// Matrix3 – rotateZ(float radians)
		MATHLIBRARY_API void rotateZ(float radians);

		// Setting as a Euler rotation matrix : setRotated(float pitch, float yaw, float roll)
		MATHLIBRARY_API void setEuler(float pitch, float yaw, float roll);

		// Rotating by Euler angles : rotate(float pitch, float yaw, float roll)
		MATHLIBRARY_API void rotate(float pitch, float yaw, float roll);

		// Methods for scaling existing matrices:
		// Matrix3 – setScaled(float x, float y, float z) 
		MATHLIBRARY_API void setScaled(float x, float y, float z);

		// Matrix3 – setScaled(const Vector3& v) 
		MATHLIBRARY_API void setScaled(const Vector3& v);

		// Methods for creating scale matrices:
		// scale(float x, float y, float z)
		MATHLIBRARY_API void scale(float x, float y, float z = 1);

		// scale(const Vector3& v)
		MATHLIBRARY_API void scale(const Vector3& v);

		// translate method
		MATHLIBRARY_API void translate(float x, float y, float z);

		MATHLIBRARY_API void translate(float x, float y);

		// getScale() takes the length of each axis in the matrix using Pythagoras Theorem
		MATHLIBRARY_API Vector3 getScale();

		// Matrix3 - orientateHomogenousToTargetY(Vector3 target)
		MATHLIBRARY_API void orientateHomogenousToTargetY(Vector3 target);

		// Matrix3 - getEuler returns float for 2D
		MATHLIBRARY_API float getEuler();
	};
}