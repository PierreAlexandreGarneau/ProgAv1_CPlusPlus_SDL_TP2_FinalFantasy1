#pragma once

#include "Sprite.h"
#include "ResourceIDs.h"
#include "CollisionCategory.h"

class TextFF :
	public Sprite
{
public:
	void Start();
	void Update();

	TextFF();
	TextFF(float mass);
	~TextFF();

	virtual void OnCollisionEnter(b2Fixture* fixture);
	virtual void OnCollisionLeave(b2Fixture* fixture);

private:
	float speed;
};

