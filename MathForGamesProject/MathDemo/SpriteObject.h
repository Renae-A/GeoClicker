#pragma once
#include <iostream>
#include <vector>
#include <assert.h>
#include <font.h>
#include <Texture.h>
#include <Renderer2D.h>
#include "MathLibrary.h"
#include "SceneObject.h"

using namespace aie;

class SpriteObject : public SceneObject { 
public: 
	
	SpriteObject();
	SpriteObject(const char* filename);
	virtual ~SpriteObject();
	
	bool load(const char* filename);

	virtual void onDraw(aie::Renderer2D * renderer);

	float collisionWidth = 0.0f;

protected: 
	aie::Texture* m_texture = nullptr; 
};

