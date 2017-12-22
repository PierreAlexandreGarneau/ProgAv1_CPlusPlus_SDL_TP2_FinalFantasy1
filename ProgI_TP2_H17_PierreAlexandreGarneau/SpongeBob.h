#pragma once

#include "Sprite.h"
#include "ResourceIDs.h"
#include "CollisionCategory.h"

class SpongeBob :
	public Sprite
{
public:
	void Start();
	void Update();

	SpongeBob();
	SpongeBob(float mass);
	~SpongeBob();

	virtual void OnCollisionEnter(b2Fixture* fixture);
	virtual void OnCollisionLeave(b2Fixture* fixture);

private:
	float speed;
};

