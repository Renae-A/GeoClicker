#pragma once  
#include <math.h>
#include <cmath>
#include "Vector4.h"

namespace MathLibrary
{
	class Matrix4
	{
	public:
		union
		{
			struct
			{
				Vector4 xAxis;
				Vector4 yAxis;
				Vector4 zAxis;
				Vector4 translation;
			};
			Vector4 axis[4];
			float data[4][4];
		};

		MATHLIBRARY_API static const Matrix4 identity;

		// Default constructor
		MATHLIBRARY_API Matrix4();

		// Constructor taking Vector4s
		MATHLIBRARY_API Matrix4(Vector4 x, Vector4 y, Vector4 z, Vector4 t);

		// Constructor taking floats
		MATHLIBRARY_API Matrix4(float Xx, float Xy, float Xz, float Xw, float Yx, float Yy, float Yz, float Yw, float Zx, float Zy, float Zz, float Zw, float Tx, float Ty, float Tz, float Tw);

		// Copy constructor
		MATHLIBRARY_API Matrix4(const Matrix4 &other);

		// Sub - script operator [] access for each axis
		// reference access so it can be modified
		MATHLIBRARY_API Vector4& operator [] (int index);

		// const access for read-only
		MATHLIBRARY_API const Vector4& operator [] (int index) const;

		// Assignment operator
		MATHLIBRARY_API Matrix4 operator=(const Matrix4 & other);

		// A transpose method
		MATHLIBRARY_API Matrix4 transposed() const;

		// Matrix multiplication operator * overload(i.e.Matrix * Matrix)
		MATHLIBRARY_API Matrix4 operator * (const Matrix4& other) const;

		// binary * operator
		MATHLIBRARY_API Vector4 operator*(const Vector4 & v) const;

		// Float* casting
		MATHLIBRARY_API operator const float*() const;

		// Float* casting
		MATHLIBRARY_API operator float*();

		// Matrix addition operator + overload(i.e.Matrix + Matrix)
		MATHLIBRARY_API Matrix4 operator + (const Matrix4& other) const;

		// Matrix subtraction operator – overload(i.e.Matrix – Matrix)
		MATHLIBRARY_API Matrix4 operator - (const Matrix4& other) const;

		// Methods for setting up the matrices as rotation matrices :
		// Matrix4 – setRotateX(float radians)
		MATHLIBRARY_API void setRotateX(float radians);

		// Matrix4 – setRotateY(float radians)
		MATHLIBRARY_API void setRotateY(float radians);

		// Matrix4 – setRotateZ(float radians)
		MATHLIBRARY_API void setRotateZ(float radians);

		// Methods for rotating an existing matrix :
		// Matrix4 – rotateX(float radians)
		MATHLIBRARY_API void rotateX(float radians);

		// Matrix4 – rotateY(float radians)
		MATHLIBRARY_API void rotateY(float radians);

		// Matrix4 – rotateZ(float radians)
		MATHLIBRARY_API void rotateZ(float radians);

		// Setting as a Euler rotation matrix : setRotated(float pitch, float yaw, float roll)
		MATHLIBRARY_API void setEuler(float pitch, float yaw, float roll);

		// Getting as a Euler rotation matrix
		MATHLIBRARY_API void getEuler(float& pitch, float& yaw, float& roll) const;

		// Rotating by Euler angles : rotate(float pitch, float yaw, float roll)
		MATHLIBRARY_API void rotate(float pitch, float yaw, float roll);

		// Methods for scaling existing matrices:
		// Matrix4 – setScaled(float x, float y, float z) 
		MATHLIBRARY_API void setScaled(float x, float y, float z);

		// Matrix4 – setScaled(const Vector4& v) 
		MATHLIBRARY_API void setScaled(const Vector4& v);

		// Methods for creating scale matrices:
		// scale(float x, float y, float z)
		MATHLIBRARY_API void scale(float x, float y, float z);

		// scale(const Vector3& v)
		MATHLIBRARY_API void scale(const Vector4& v);

		// translate method
		MATHLIBRARY_API void translate(float x, float y, float z);

		// getScale() takes the length of each axis in the matrix using Pythagoras Theorem
		MATHLIBRARY_API Vector3 getScale();

		// Matrix4 - orientateToTargetZ(Vector4 target)
		MATHLIBRARY_API void orientateToTargetZ(Vector4 target);
	};
}