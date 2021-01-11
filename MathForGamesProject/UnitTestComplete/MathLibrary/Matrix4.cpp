#include "stdafx.h"
#include "Matrix4.h"

namespace MathLibrary
{
	// create a static const identity matrix
	const Matrix4 Matrix4::identity = Matrix4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);


	// Default constructor
	Matrix4::Matrix4()
	{

	}

	// Constructor taking Vector4s
	Matrix4::Matrix4(Vector4 x, Vector4 y, Vector4 z, Vector4 t)
	{
		xAxis = x;
		yAxis = y;
		zAxis = z;
		translation = t;
	}

	// Constructor taking floats
	Matrix4::Matrix4(float Xx, float Xy, float Xz, float Xw, float Yx, float Yy, float Yz, float Yw, float Zx, float Zy, float Zz, float Zw, float Tx, float Ty, float Tz, float Tw)
	{
		xAxis = {Xx, Xy, Xz, Xw};
		yAxis = {Yx, Yy, Yz, Yw};
		zAxis = {Zx, Zy, Zz, Zw};
		translation = {Tx, Ty, Tz, Tw};
	}

	// Copy constructor
	Matrix4::Matrix4(const Matrix4 & other)
	{
		xAxis = other.xAxis;
		yAxis = other.yAxis;
		zAxis = other.zAxis;
		translation = other.translation;
	}

	// Sub - script operator [] access for each axis
	// reference access so it can be modified
	Vector4 & Matrix4::operator[](int index)
	{
		return axis[index];
	}

	// const access for read-only
	const Vector4 & Matrix4::operator[](int index) const
	{
		return axis[index];
	}

	// Assignment operator
	Matrix4 Matrix4::operator=(const Matrix4 & other)
	{
		xAxis = other.xAxis;
		yAxis = other.yAxis;
		zAxis = other.zAxis;
		translation = other.translation;

		return *this;
	}

	Matrix4 Matrix4::transposed() const
	{
		Matrix4 result;

		// flip row and column
		for (int r = 0; r < 4; ++r)
			for (int c = 0; c < 4; ++c)
				result.data[r][c] = data[c][r];

		return result;
	}

	// binary * operator
	Matrix4 Matrix4::operator*(const Matrix4 & other) const
	{
		Matrix4 result;

		for (int r = 0; r < 4; ++r) {
			for (int c = 0; c < 4; ++c) {
				result.data[c][r] = data[0][r] * other.data[c][0] +
					data[1][r] * other.data[c][1] +
					data[2][r] * other.data[c][2] +
					data[3][r] * other.data[c][3];
			}
		}
		return result;
	}

	// binary * operator
	Vector4 Matrix4::operator * (const Vector4& v) const 
	{

		Vector4 result;

		for (int r = 0; r < 4; ++r) {
			result[r] = data[0][r] * v[0] +
				data[1][r] * v[1] +
				data[2][r] * v[2] +
				data[3][r] * v[3];
		}

		return result;
	}

	// Float* casting
	Matrix4::operator const float*() const
	{
		return &data[0][0];
	}

	// Float* casting
	Matrix4::operator float*()
	{
		return &data[0][0];
	}

	// Matrix addition operator + overload(i.e.Matrix + Matrix)
	Matrix4 Matrix4::operator+(const Matrix4 & other) const
	{
		Matrix4 result;

		for (int r = 0; r < 4; ++r) {
			for (int c = 0; c < 4; ++c) {
				result.data[c][r] = data[0][r] + other.data[c][0] +
					data[1][r] + other.data[c][1] +
					data[2][r] + other.data[c][2] +
					data[3][r] + other.data[c][3];
			}
		}
		return result;
	}

	// Matrix subtraction operator – overload(i.e.Matrix – Matrix)
	Matrix4 Matrix4::operator-(const Matrix4 & other) const
	{
		Matrix4 result;

		for (int r = 0; r < 4; ++r) {
			for (int c = 0; c < 4; ++c) {
				result.data[c][r] = data[0][r] - other.data[c][0] +
					data[1][r] - other.data[c][1] +
					data[2][r] - other.data[c][2] +
					data[3][r] - other.data[c][3];
			}
		}
		return result;
	}

	// Methods for setting up the matrices as rotation matrices :
	// Matrix4 – setRotateX(float radians)
	void Matrix4::setRotateX(float radians)
	{
		// leave X axis and elements unchanged 
		xAxis = { 1, 0, 0, 0 };
		yAxis = { 0, cosf(radians), sinf(radians), 0 };
		zAxis = { 0, -sinf(radians), cosf(radians), 0 };
		translation = { 0, 0, 0, 1 };
	}

	// Matrix4 – setRotateY(float radians)
	void Matrix4::setRotateY(float radians)
	{
		// leave Y axis and elements unchanged 
		xAxis = { cosf(radians), 0, -sinf(radians), 0 };
		yAxis = { 0, 1, 0, 0 };
		zAxis = { sinf(radians), 0, cosf(radians), 0 };
		translation = { 0, 0, 0, 1 };
	}

	// Matrix4 – setRotateZ(float radians)
	void Matrix4::setRotateZ(float radians)
	{
		// leave Z axis and elements unchanged 
		xAxis = { cosf(radians), sinf(radians), 0, 0 };
		yAxis = { -sinf(radians), cosf(radians), 0, 0 };
		zAxis = { 0, 0, 1, 0 };
		translation = { 0, 0, 0, 1 };
	}

	// Methods for rotating an existing matrix :
	// Matrix4 – rotateX(float radians)
	void Matrix4::rotateX(float radians)
	{
		Matrix4 m;
		m.setRotateX(radians);

		*this = *this * m;
	}

	// Matrix4 – rotateY(float radians)
	void Matrix4::rotateY(float radians)
	{
		Matrix4 m;
		m.setRotateY(radians);

		*this = *this * m;
	}

	// Matrix4 – rotateZ(float radians)
	void Matrix4::rotateZ(float radians)
	{
		Matrix4 m;
		m.setRotateZ(radians);

		*this = *this * m;
	}

	// Setting as a Euler rotation matrix : setRotated(float pitch, float yaw, float roll)
	void Matrix4::setEuler(float pitch, float yaw, float roll)
	{
		Matrix4 x, y, z;
		x.setRotateX(pitch);
		y.setRotateY(yaw);
		z.setRotateZ(roll); // combine rotations in a specific order 

		*this = z * y * x;
	}

	// Getting as a Euler rotation matrix
	void Matrix4::getEuler(float & pitch, float & yaw, float & roll) const
	{
		if (xAxis.x == 1.0f)
		{
			yaw = atan2f(xAxis.x, zAxis.w);
			pitch = 0;
			roll = 0;

		}
		else if (xAxis.x == -1.0f)
		{
			yaw = atan2f(xAxis.x, zAxis.w);
			pitch = 0;
			roll = 0;
		}
		else
		{

			yaw = atan2(-zAxis.x, xAxis.x);
			pitch = asin(yAxis.x);
			roll = atan2(-yAxis.z, yAxis.y);
		}
	}

	// Rotating by Euler angles : rotate(float pitch, float yaw, float roll)
	void Matrix4::rotate(float pitch, float yaw, float roll)
	{
		Matrix4 m;
		m.setEuler(pitch, yaw, roll);

		*this = *this * m;
	}

	// Methods for scaling existing matrices:
	// Matrix4 – setScaled(float x, float y, float z) 
	void Matrix4::setScaled(float x, float y, float z)
	{
		// set scale of each axis 
		xAxis = { x, 0, 0, 0 };
		yAxis = { 0, y, 0, 0 };
		zAxis = { 0, 0, z, 0 };
		translation = { 0, 0, 0, 1 };
	}

	// Matrix4 – setScaled(const Vector4& v)
	void Matrix4::setScaled(const Vector4 & v)
	{
		// set scale of each axis 
		xAxis = { v.x, 0, 0, 0 };
		yAxis = { 0, v.y, 0, 0 };
		zAxis = { 0, 0, v.z, 0 };
		translation = { 0, 0, 0, 1 };
	}
	
	// Methods for creating scale matrices:
	// scale(float x, float y, float z)
	void Matrix4::scale(float x, float y, float z)
	{
		Matrix4 m;
		m.setScaled(x, y, z);

		*this = *this * m;
	}

	// scale(const Vector3& v)
	void Matrix4::scale(const Vector4 & v)
	{
		Matrix4 m;
		m.setScaled(v.x, v.y, v.z);

		*this = *this * m;
	}

	// translate method
	void Matrix4::translate(float x, float y, float z)
	{
		translation += Vector4(x, y, z, 0);
	}

	// getScale() takes the length of each axis in the matrix using Pythagoras Theorem
	Vector3 Matrix4::getScale()
	{
		float sX = xAxis.magnitude();
		float sY = yAxis.magnitude();
		float sZ = zAxis.magnitude();

		return Vector3(sX, sY, sZ);
	}

	// Matrix4 - orientateToTargetZ(Vector4 target)
	void Matrix4::orientateToTargetZ(Vector4 target)
	{
		// (0,1,0) is genreally the world up vector
		Vector4 up = { 0, 1, 0, 0 };

		zAxis = (target - translation).normalised();

		// Make the xAxis perpendicular to both the zAxis and up vector, using the cross product
		xAxis = zAxis.cross(up);

		// Make the yAxis perpendicular to both the z and x axes
		yAxis = zAxis.cross(xAxis);

	}
}