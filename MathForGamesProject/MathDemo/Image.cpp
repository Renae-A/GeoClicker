#include "Image.h"
#include "Transform.h"
#include "GameObject.h"
#include <Vector2.h>

// Constructor that takes a GameObject pointer to assign it the Image
Image::Image(GameObject * newOwner)
{
	owner = newOwner;
}

// A constructor that takes a Texture pointer and a GameObject pointer to set the texture as the Image and sets that Image component to a GameObject
Image::Image(aie::Texture * image, GameObject * newOwner)
{
	texture = image;
	owner = newOwner;
}

// A constructor that takes a float width, float height.Texture pointer and a GameObject pointer to set the texture as the Image and set the size of that image then sets that Image component to a GameObject
Image::Image(float newWidth, float newHeight, aie::Texture * image, GameObject * newOwner)
{
	width = newWidth;
	height = newHeight;
	texture = image;
	owner = newOwner;
}

// Destructor
Image::~Image()
{
}

// An update function that updates the Image taking deltatime
void Image::update(float deltatime)
{
}

// An update function that draws the Image if necessary
void Image::draw(aie::Renderer2D * renderer)
{
	Vector2 imgSize(width * owner->getComponent<Transform>()->getGlobalTransform()[0][0], height * owner->getComponent<Transform>()->getGlobalTransform()[1][1]);

	if (enabled && texture != nullptr)
	{
		renderer->drawSpriteTransformed3x3(texture, (float*)owner->getComponent<Transform>()->getGlobalTransform(), width, height);
	}
}
