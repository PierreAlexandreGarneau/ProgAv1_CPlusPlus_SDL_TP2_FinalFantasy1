#pragma once

#include "Sprite.h"
#include "MapSprite.h"
#include "CollisionDirection.h"

class CollisionSprite : public Sprite
{
public:
	CollisionSprite(MapSprite* ms, float x, float y, float w, float h, CollisionDirection direction);
	void Update();
	virtual void OnCollisionEnter(b2Fixture* fixture);
	virtual void OnCollisionLeave(b2Fixture* fixture);

private:
	MapSprite* mmapSprite;
	float mx;
	float my;
	float mw;
	float mh;
	CollisionDirection mdirection;
};

