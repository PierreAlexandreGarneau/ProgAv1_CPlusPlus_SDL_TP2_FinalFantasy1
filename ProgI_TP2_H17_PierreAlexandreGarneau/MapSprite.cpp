#include "MapSprite.h"
#include "CollisionCategory.h"

MapSprite::MapSprite(Texture::ID textureId, int moveSpeed) : Sprite(textureId)
	, moveSpeed(moveSpeed), collisions(CollisionDirection::None)
{
}

void MapSprite::Update()
{
	if (gInput->IsKeyHeld(SDL_SCANCODE_W) && !CheckIfCollide(CollisionDirection::Top))
	{
		transform.position = transform.position + b2Vec2(0, moveSpeed * deltaTime);
		//body->SetTransform(body->GetPosition() + b2Vec2(0, moveSpeed * deltaTime), body->GetAngle());
	}
	if (gInput->IsKeyHeld(SDL_SCANCODE_A) && !CheckIfCollide(CollisionDirection::Left))
	{
		transform.position = transform.position + b2Vec2(moveSpeed * deltaTime, 0);
		//body->SetTransform(body->GetPosition() + (b2Vec2(moveSpeed * deltaTime, 0)), body->GetAngle());
	}
	if (gInput->IsKeyHeld(SDL_SCANCODE_S) && !CheckIfCollide(CollisionDirection::Down))
	{
		transform.position = transform.position + b2Vec2(0, -moveSpeed * deltaTime);
		//body->SetTransform(body->GetPosition() + (b2Vec2(0, -moveSpeed * deltaTime)), body->GetAngle());
	}
	if (gInput->IsKeyHeld(SDL_SCANCODE_D) && !CheckIfCollide(CollisionDirection::Right))
	{
		transform.position = transform.position + b2Vec2(-moveSpeed * deltaTime, 0);
		//body->SetTransform(body->GetPosition() + (b2Vec2(-moveSpeed * deltaTime, 0)), body->GetAngle());
	}

	Sprite::Update();
}

bool MapSprite::CheckIfCollide(CollisionDirection direction)
{
	return (collisions & (int)direction) != CollisionDirection::None;
}

b2Vec2 MapSprite::GetPosition()
{
	return transform.position;
}

void MapSprite::AddCollision(CollisionDirection collisionDirection)
{
	collisions = collisions | collisionDirection;
}

void MapSprite::RemoveCollision(CollisionDirection collisionDirection)
{
	collisions = collisions ^ collisionDirection;
}
