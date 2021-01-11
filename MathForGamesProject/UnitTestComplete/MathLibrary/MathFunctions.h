#pragma once  
#include <math.h>
#include <cmath>
#ifdef MATHLIBRARY_STATICLIB  
#define MATHLIBRARY_API
#else
#ifdef MATHLIBRARY_EXPORTS  
#define MATHLIBRARY_API __declspec(dllexport)   
#else  
#define MATHLIBRARY_API __declspec(dllimport)   
#endif  
#endif

namespace MathLibrary
{
	const double EPSILON = 2.980232E-08;

	// This class is exported from the MathLibrary.dll  
	namespace Functions
	{
		// absolute(float value) method sets the value passed in to its absolute value
		MATHLIBRARY_API float absolute(float value);

		// IsEqual(float a, float b) method that use a tolerance to compare if the elements of the Vectors are within the tolerance difference
		MATHLIBRARY_API bool IsEqual(float a, float b);

		// NotEqual(float a, float b) method that use a tolerance to compare if the elements of the Vectors are within the tolerance difference
		MATHLIBRARY_API bool NotEqual(float a, float b);
	};
}