#include "stdafx.h"
#include "MathFunctions.h"

namespace MathLibrary
{
	// absolute(float value) method sets the value passed in to its absolute value
	float Functions::absolute(float value)
	{
		return value < 0 ? -value : value;
	}

	// equal(float a, float b) method that use a tolerance to compare if the elements of the Vectors are within the tolerance difference
	bool Functions::IsEqual(float a, float b)
	{
		float difference = a - b;
		return absolute(difference) < EPSILON;
	}

	bool Functions::NotEqual(float a, float b)
	{
		float difference = a - b;
		return absolute(difference) > EPSILON;
	}
}