#pragma once

#include "SpriteAnimation.h"
#include "ResourceIDs.h"
#include "CollisionCategory.h"

class NewMagicien :
	public SpriteAnimation
{
public:
	void Update();
	float prevFrameTime;
	bool flip;
	int currFrame;
	int numFrames;

	NewMagicien(SDL_Rect* rect);
	virtual void OnCollisionEnter(b2Fixture* fixture);
	virtual void OnCollisionLeave(b2Fixture* fixture);
};

