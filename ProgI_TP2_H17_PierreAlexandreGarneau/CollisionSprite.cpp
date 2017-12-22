#include "CollisionSprite.h"
#include "CollisionCategory.h"

CollisionSprite::CollisionSprite(MapSprite* mapSprite, float x, float y, float w, float h, CollisionDirection direction) : Sprite((Texture::ID)9, x, y, w, h)
	, mx(x), my(y), mw(w), mh(h), mdirection(direction), mmapSprite(mapSprite)
{
	SetPosition(b2Vec2(x, y));
	b2Filter filter;
	filter.categoryBits = PLATFORM_CATEGORY;
	CreateCollider(ColliderType::SQUARE_COLLIDER, dstRect->w, dstRect->h, 0.0f);
	GetBody()->GetFixtureList()[0].SetFilterData(filter);
}

void CollisionSprite::Update()
{
	if (gInput->IsKeyHeld(SDL_SCANCODE_W) && !mmapSprite->CheckIfCollide(CollisionDirection::Top))
	{
		//transform.position = transform.position + b2Vec2(0, 50 * deltaTime);
		body->SetTransform(body->GetPosition() + b2Vec2(0, 100 * deltaTime), body->GetAngle());
	}
	if (gInput->IsKeyHeld(SDL_SCANCODE_A) && !mmapSprite->CheckIfCollide(CollisionDirection::Left))
	{
		//transform.position = transform.position + b2Vec2(50 * deltaTime, 0);
		body->SetTransform(body->GetPosition() + (b2Vec2(100 * deltaTime, 0)), body->GetAngle());
	}
	if (gInput->IsKeyHeld(SDL_SCANCODE_S) && !mmapSprite->CheckIfCollide(CollisionDirection::Down))
	{
		//transform.position = transform.position + b2Vec2(0, -50 * deltaTime);
		body->SetTransform(body->GetPosition() + (b2Vec2(0, -100 * deltaTime)), body->GetAngle());
	}
	if (gInput->IsKeyHeld(SDL_SCANCODE_D) && !mmapSprite->CheckIfCollide(CollisionDirection::Right))
	{
		//transform.position = transform.position + b2Vec2(-50 * deltaTime, 0);
		body->SetTransform(body->GetPosition() + (b2Vec2(-100 * deltaTime, 0)), body->GetAngle());
	}
	Sprite::Update();
}

void CollisionSprite::OnCollisionEnter(b2Fixture * fixture)
{
	mmapSprite->AddCollision(mdirection);
}

void CollisionSprite::OnCollisionLeave(b2Fixture * fixture)
{
	mmapSprite->RemoveCollision(mdirection);
}