#pragma once

#include <vector>
#include "ResourceIDs.h"
#include "Sprite.h"
#include "CollisionDirection.h"

class MapSprite : public Sprite
{
public:
	MapSprite(Texture::ID texture, int moveSpeed);
	b2Vec2 GetPosition();
	void Update();
	bool CheckIfCollide(CollisionDirection direction);
	void AddCollision(CollisionDirection collisionDirection);
	void RemoveCollision(CollisionDirection collisionDirection);

private:
	vector<Sprite*> colliders;
	float moveSpeed;
	int collisions;
};

