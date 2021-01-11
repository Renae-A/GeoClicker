#include "stdafx.h"
#include "Matrix3.h"

namespace MathLibrary
{
	// create a static const identity matrix
	const Matrix3 Matrix3::identity = Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);

	// Default constructor
	Matrix3::Matrix3()
	{

	}

	// Constructor taking Vector3s
	Matrix3::Matrix3(Vector3 x, Vector3 y, Vector3 z)
	{
		xAxis = x;
		yAxis = y;
		zAxis = z;
	}

	// Constructor taking floats
	Matrix3::Matrix3(float Xx, float Xy, float Xz, float Yx, float Yy, float Yz, float Zx, float Zy, float Zz)
	{
		xAxis = { Xx, Xy, Xz };
		yAxis = { Yx, Yy, Yz };
		zAxis = { Zx, Zy, Zz };
	}

	// Copy constructor
	Matrix3::Matrix3(const Matrix3 & other)
	{
		xAxis = other.xAxis;
		yAxis = other.yAxis;
		zAxis = other.zAxis;
	}

	// Sub - script operator [] access for each axis
	// reference access so it can be modified
	Vector3 & Matrix3::operator[](int index)
	{
		return axis[index];
	}

	// const access for read-only
	const Vector3 & Matrix3::operator[](int index) const
	{
		return axis[index];
	}

	// Assignment operator
	Matrix3 Matrix3::operator=(const Matrix3 & other)
	{
		xAxis = other.xAxis;
		yAxis = other.yAxis;
		zAxis = other.zAxis;

		return *this;
	}

	Matrix3 Matrix3::transposed() const
	{
		Matrix3 result;

		// flip row and column
		for (int r = 0; r < 3; ++r)
			for (int c = 0; c < 3; ++c)
				result.data[r][c] = data[c][r];

		return result;

	}

	// binary * operator
	Matrix3 Matrix3::operator*(const Matrix3 & other) const
	{
		Matrix3 result;

		for (int r = 0; r < 3; ++r) {
			for (int c = 0; c < 3; ++c) {
				result.data[c][r] = data[0][r] * other.data[c][0] +
					data[1][r] * other.data[c][1] +
					data[2][r] * other.data[c][2];
			}
		}
		return result;
	}

	// binary * operator
	Vector3 Matrix3::operator * (const Vector3& v) const {

		Vector3 result;

		for (int r = 0; r < 3; ++r) {
			result[r] = data[0][r] * v[0] +
				data[1][r] * v[1] +
				data[2][r] * v[2];
		}

		return result;
	}

	// Float* casting
	Matrix3::operator const float*() const
	{
		return &data[0][0];
	}

	// Float* casting
	Matrix3::operator float*()
	{
		return &data[0][0];
	}

	// Matrix addition operator + overload(i.e.Matrix + Matrix)
	Matrix3 Matrix3::operator+(const Matrix3 & other) const
	{
		Matrix3 result;

		for (int r = 0; r < 3; ++r) {
			for (int c = 0; c < 3; ++c) {
				result.data[c][r] = data[0][r] + other.data[c][0] +
					data[1][r] + other.data[c][1] +
					data[2][r] + other.data[c][2];
			}
		}
		return result;
	}

	// Matrix subtraction operator – overload(i.e.Matrix – Matrix)
	Matrix3 Matrix3::operator-(const Matrix3 & other) const
	{
		Matrix3 result;

		for (int r = 0; r < 3; ++r) {
			for (int c = 0; c < 3; ++c) {
				result.data[c][r] = data[0][r] - other.data[c][0] +
					data[1][r] - other.data[c][1] +
					data[2][r] - other.data[c][2];
			}
		}
		return result;
	}

	// Methods for setting up the matrices as rotation matrices :
	// Matrix3 – setRotateX(float radians)
	void Matrix3::setRotateX(float radians)
	{ 
		// leave X axis and elements unchanged 
		xAxis = { 1, 0, 0 }; 
		yAxis = { 0, cosf(radians), sinf(radians) }; 
		zAxis = { 0, -sinf(radians), cosf(radians) }; 
	}

	// Matrix3 – setRotateY(float radians)
	void Matrix3::setRotateY(float radians)
	{
		// leave Y axis and elements unchanged 
		xAxis = { cosf(radians), 0, -sinf(radians) };
		yAxis = { 0, 1, 0 };
		zAxis = { sinf(radians), 0, cosf(radians) };
	}

	// Matrix3 – setRotateZ(float radians)
	void Matrix3::setRotateZ(float radians)
	{
		// leave Z axis and elements unchanged 
		xAxis = { cosf(radians), sinf(radians), 0 };
		yAxis = { -sinf(radians), cosf(radians), 0 };
		zAxis = { 0, 0, 1 };
	}

	// Methods for rotating an existing matrix :
	// Matrix3 – rotateX(float radians)
	void Matrix3::rotateX(float radians)
	{
		Matrix3 m; 
		m.setRotateX(radians); 

		*this = *this * m;
	}

	// Matrix3 – rotateY(float radians)
	void Matrix3::rotateY(float radians)
	{
		Matrix3 m;
		m.setRotateY(radians);

		*this = *this * m;
	}

	// Matrix3 – rotateZ(float radians)
	void Matrix3::rotateZ(float radians)
	{
		Matrix3 m;
		m.setRotateZ(radians);

		*this = *this * m;
	}

	// Setting as a Euler rotation matrix : setRotated(float pitch, float yaw, float roll)
	void Matrix3::setEuler(float pitch, float yaw, float roll)
	{
		Matrix3 x, y, z;
		x.setRotateX(pitch);
		y.setRotateY(yaw);
		z.setRotateZ(roll); // combine rotations in a specific order 
		
		*this = z * y * x;
	}

	// Rotating by Euler angles : rotate(float pitch, float yaw, float roll)
	void Matrix3::rotate(float pitch, float yaw, float roll)
	{
		Matrix3 m;
		m.setEuler(pitch, yaw, roll);

		*this = *this * m;
	}

	// Methods for scaling existing matrices:
	// Matrix3 – setScaled(float x, float y, float z) 
	void Matrix3::setScaled(float x, float y, float z)
	{ 
		// set scale of each axis 
		xAxis = { x, 0, 0 }; 
		yAxis = { 0, y, 0 }; 
		zAxis = { 0, 0, z }; 
	}

	// Matrix3 – setScaled(const Vector3& v) 
	void Matrix3::setScaled(const Vector3 & v)
	{
		// set scale of each axis 
		xAxis = { v.x, 0, 0 }; 
		yAxis = { 0, v.y, 0 }; 
		zAxis = { 0, 0, v.z };
	}

	// Methods for creating scale matrices:
	// scale(float x, float y, float z)
	void Matrix3::scale(float x, float y, float z)
	{
		Matrix3 m;
		m.setScaled(x, y, z); 

		*this = *this * m;
	}

	// scale(const Vector3& v)
	void Matrix3::scale(const Vector3 & v)
	{
		Matrix3 m; 
		m.setScaled(v.x, v.y, v.z); 
		
		*this = *this * m;
	}

	// translate method
	void Matrix3::translate(float x, float y, float z)
	{
		translation += Vector3(x, y, z);
	}

	// translate method
	void Matrix3::translate(float x, float y)
	{
		translation += Vector3(x, y, 0);
	}

	// getScale() takes the length of each axis in the matrix using Pythagoras Theorem
	Vector3 Matrix3::getScale()
	{
		float sX = xAxis.magnitude();
		float sY = yAxis.magnitude();
		float sZ = zAxis.magnitude();

		return Vector3(sX, sY, sZ);
	}

	// Matrix3 - orientateHomogenousToTargetY(Vector3 target)
	void Matrix3::orientateHomogenousToTargetY(Vector3 target)
	{
		yAxis = target.normalised();

		xAxis = { yAxis.y, -yAxis.x, 0 };
	}

	// Matrix3 - getEuler returns float for 2D
	float Matrix3::getEuler()
	{
		return atan2(xAxis.x, xAxis.y);
	}
}