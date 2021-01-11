#pragma once
#include "Component.h"
#include <Renderer2D.h>

class Image : public Component
{
public:
	Image(GameObject* newOwner = nullptr);															// Constructor that takes a GameObject pointer to assign it the Image
	Image(aie::Texture* image, GameObject* newOwner = nullptr);										// A constructor that takes a Texture pointer and a GameObject pointer to set the texture as the Image
																									// and sets that Image component to a GameObject
	Image(float newWidth, float newHeight, aie::Texture* image, GameObject* newOwner = nullptr);	// A constructor that takes a float width, float height.Texture pointer and a GameObject pointer to set 
																									// the texture as the Image and set the size of that image then sets that Image component to a GameObject
	~Image();																						// Destructor

	aie::Texture* texture;																			
	float width;
	float height;

protected:
	void update(float deltatime);																	// An update function that updates the Image taking deltatime
	void draw(aie::Renderer2D* renderer);															// An update function that draws the Image if necessary
};

