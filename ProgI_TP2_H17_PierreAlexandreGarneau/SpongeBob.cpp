#include "SpongeBob.h"

SpongeBob::SpongeBob()
	: Sprite(Texture::ID::Patrick, true, true)
	, speed(100)
{
	b2Filter filter;
	filter.categoryBits = PLATFORM_CATEGORY;

	CreateCollider(ColliderType::SQUARE_COLLIDER, dstRect->w, dstRect->h, 0.0f);
	GetBody()->GetFixtureList()[0].SetFilterData(filter);
}

SpongeBob::SpongeBob(float mass)
	: Sprite(Texture::ID::Patrick, true, true)
	, speed(100)
{
	b2Filter filter;
	filter.categoryBits = BALL_CATEGORY;

	CreateCollider(ColliderType::SQUARE_COLLIDER, dstRect->w, dstRect->h, mass);
	GetBody()->GetFixtureList()[0].SetFilterData(filter);
}

SpongeBob::~SpongeBob()
{
}

void SpongeBob::Start()
{
}

void SpongeBob::Update()
{
	Sprite::Update();

	if (gInput->IsKeyHeld(SDL_SCANCODE_W))
	{
		body->SetTransform(
			body->GetPosition() + (b2Vec2(0, -speed * deltaTime)),
			body->GetAngle());
	}
	if (gInput->IsKeyHeld(SDL_SCANCODE_A))
	{
		body->SetTransform(
			body->GetPosition() + (b2Vec2(-speed * deltaTime, 0)),
			body->GetAngle());
	}
	if (gInput->IsKeyHeld(SDL_SCANCODE_S))
	{
		body->SetTransform(
			body->GetPosition() + (b2Vec2(0, speed * deltaTime)),
			body->GetAngle());
	}
	if (gInput->IsKeyHeld(SDL_SCANCODE_D))
	{
		body->SetTransform(
			body->GetPosition() + (b2Vec2(speed * deltaTime, 0)),
			body->GetAngle());
	}
}

void SpongeBob::OnCollisionEnter(b2Fixture * fixture)
{
	std::cout << "Collision" << std::endl;
	if (GetBody()->GetFixtureList()[0].GetFilterData().categoryBits !=
		fixture->GetFilterData().categoryBits)
	{
		switch (fixture->GetFilterData().categoryBits)
		{
		case PLATFORM_CATEGORY: {
			std::cout << "PLATFORM_CATEGORY" << std::endl;
		} break;

		case BALL_CATEGORY: {
			std::cout << "BALL_CATEGORY" << std::endl;
		} break;

		default:
		{
		} break;
		}
	}
}

void SpongeBob::OnCollisionLeave(b2Fixture * fixture)
{

}
