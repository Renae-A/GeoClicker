#include "stdafx.h"
#include "Matrix2.h"

namespace MathLibrary
{
	// create a static const identity matrix
	const Matrix2 Matrix2::identity = Matrix2(1, 0, 0, 1);

	// Default constructor
	Matrix2::Matrix2()
	{

	}

	// Constructor taking Vector2s
	Matrix2::Matrix2(Vector2 x, Vector2 y)
	{
		xAxis = x;
		yAxis = y;
	}

	// Constructor taking floats
	Matrix2::Matrix2(float Xx, float Xy, float Yx, float Yy)
	{
		xAxis = { Xx, Xy };
		yAxis = { Yx, Yy };
	}

	// Copy constructor
	Matrix2::Matrix2(const Matrix2 & other)
	{
		xAxis = other.xAxis;
		yAxis = other.yAxis;
	}

	// Sub - script operator [] access for each axis
	// reference access so it can be modified
	Vector2 & Matrix2::operator[](int index)
	{
		return axis[index];
	}

	// const access for read-only
	const Vector2 & Matrix2::operator[](int index) const
	{
		return axis[index];
	}

	// Assignment operator
	Matrix2 Matrix2::operator=(const Matrix2 & other)
	{
		xAxis = other.xAxis;
		yAxis = other.yAxis;

		return *this;
	}

	Matrix2 Matrix2::transposed() const
	{
		Matrix2 result;

		// flip row and column
		for (int r = 0; r < 2; ++r)
			for (int c = 0; c < 2; ++c)
				result.data[r][c] = data[c][r];

		return result;

	}

	// binary * operator
	Matrix2 Matrix2::operator*(const Matrix2 & other) const
	{
		Matrix2 result;

		for (int r = 0; r < 2; ++r) {
			for (int c = 0; c < 2; ++c) {
				result.data[c][r] = data[0][r] * other.data[c][0] +
					data[1][r] * other.data[c][1];
			}
		}
		return result;
	}

	// Matrix by Vector multiplication operator * overload(i.e.Matrix * Vector)
	// binary * operator
	Vector2 Matrix2::operator*(const Vector2 & v) const 
	{
		Vector2 result;

		for (int r = 0; r < 2; ++r) 
		{
			result[r] = data[0][r] * v[0] +
				data[1][r] * v[1];
		}
		return result;
	}

	// Float* casting
	Matrix2::operator const float*() const
	{
		return &data[0][0];
	}

	// Float* casting
	Matrix2::operator float*()
	{
		return &data[0][0];
	}

	// Matrix addition operator + overload(i.e.Matrix + Matrix)
	Matrix2 Matrix2::operator+(const Matrix2 & other) const
	{
		Matrix2 result;

		for (int r = 0; r < 2; ++r) {
			for (int c = 0; c < 2; ++c) {
				result.data[c][r] = data[0][r] + other.data[c][0] +
					data[1][r] + other.data[c][1];
			}
		}
		return result;
	}

	// Matrix subtraction operator – overload(i.e.Matrix – Matrix)
	Matrix2 Matrix2::operator-(const Matrix2 & other) const
	{
		Matrix2 result;

		for (int r = 0; r < 2; ++r) {
			for (int c = 0; c < 2; ++c) {
				result.data[c][r] = data[0][r] - other.data[c][0] +
					data[1][r] - other.data[c][1];
			}
		}
		return result;
	}

	// Method for setting up the matrices as rotation matrices :
	// Matrix2 – setRotate(float radians)
	void Matrix2::setRotate(float radians)
	{
		xAxis = { cosf(radians), sinf(radians) };
		yAxis = { -sinf(radians), cosf(radians) };
	}

	// Methods for rotating an existing matrix :
	// Matrix2 – rotate(float radians)
	void Matrix2::rotate(float radians)
	{
		Matrix2 m; 
		m.setRotate(radians); 
		
		*this = *this * m;
	}

	// Methods for scaling existing matrices:
	// Matrix2 - setScaled(float x, float y) 
	void Matrix2::setScaled(float x, float y)
	{
		// set scale of each axis 
		xAxis = { x, 0 };
		yAxis = { 0, y };
	}

	// Matrix2 – setScaled(const Vector2& v) 
	void Matrix2::setScaled(const Vector2 & v)
	{
		// set scale of each axis 
		xAxis = { v.x, 0 };
		yAxis = { 0, v.y };
	}

	// Methods for creating scale matrices:
	// scale(float x, float y)
	void Matrix2::scale(float x, float y)
	{
		Matrix2 m;
		m.setScaled(x, y);

		*this = *this * m;
	}

	// scale(const Vector2& v)
	void Matrix2::scale(const Vector2 & v)
	{
		Matrix2 m;
		m.setScaled(v.x, v.y);

		*this = *this * m;
	}

	Vector2 Matrix2::getScale()
	{
		float sX = xAxis.magnitude();
		float sY = yAxis.magnitude();

		return Vector2(sX, sY);
	}

	// Matrix2 - orientateToTargetY(Vector2 target)
	void Matrix2::orientateToTargetY(Vector2 target)
	{
		yAxis = target.normalised();

		xAxis = { yAxis.y, -yAxis.x };
	}


	// Matrix2 - getEuler returns float
	float Matrix2::getEuler()
	{
		return atan2(xAxis.x, xAxis.y);
	}
}