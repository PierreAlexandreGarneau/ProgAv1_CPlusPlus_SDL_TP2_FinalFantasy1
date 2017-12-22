#include "NewMagicien.h"

NewMagicien::NewMagicien(SDL_Rect* rect)
	: SpriteAnimation(Texture::ID::SpriteSheetReal, rect, 1)
{
	flip = false;
	currFrame = 0;
	SetPosition(b2Vec2(500, 100));
	b2Filter filter;
	filter.categoryBits = PLATFORM_CATEGORY;
	CreateCollider(ColliderType::SQUARE_COLLIDER, dstRect->w, dstRect->h, 1.0f);
	GetBody()->GetFixtureList()[0].SetFilterData(filter);
}

void NewMagicien::Update()
{

	if (gInput->IsKeyHeld(SDL_SCANCODE_W))
	{
		srcRect->h = 14;
		srcRect->w = 14;
		srcRect->x = 22;
		srcRect->y = 276;
		if (!flip)
			SetFlip(SDL_FLIP_NONE);
		else
			SetFlip(SDL_FLIP_HORIZONTAL);
		if (gTimer->GetGameTime() > prevFrameTime + (1.0 / 8))
		{
			flip = !flip;
			prevFrameTime = gTimer->GetGameTime();
		}
		
	}
	if (gInput->IsKeyHeld(SDL_SCANCODE_A))
	{
		SetFlip(SDL_FLIP_NONE);
		numFrames = 2;
		if (currFrame >= numFrames)
		{
			srcRect->h = 16;
			srcRect->w = 15;
			srcRect->x = 38;
			srcRect->y = 274;
			currFrame = 0;
		}

		if (gTimer->GetGameTime() > prevFrameTime + (1.0 / 8))
		{
			srcRect->x += srcRect->w;
			currFrame++;
			prevFrameTime = gTimer->GetGameTime();
		}

	}
	if (gInput->IsKeyHeld(SDL_SCANCODE_S))
	{
		srcRect->h = 14;
		srcRect->w = 14;
		srcRect->x = 6;
		srcRect->y = 276;
		if (!flip)
			SetFlip(SDL_FLIP_NONE);
		else
			SetFlip(SDL_FLIP_HORIZONTAL);
		if (gTimer->GetGameTime() > prevFrameTime + (1.0 / 8))
		{
			flip = !flip;
			prevFrameTime = gTimer->GetGameTime();
		}

	}
	if (gInput->IsKeyHeld(SDL_SCANCODE_D))
	{
		SetFlip(SDL_FLIP_HORIZONTAL);
		numFrames = 2;
		if (currFrame >= numFrames)
		{
			srcRect->h = 16;
			srcRect->w = 15;
			srcRect->x = 38;
			srcRect->y = 274;
			currFrame = 0;
		}

		if (gTimer->GetGameTime() > prevFrameTime + (1.0 / 8))
		{
			srcRect->x += srcRect->w;
			currFrame++;
			prevFrameTime = gTimer->GetGameTime();
		}
	}

	Sprite::Update();
}

void NewMagicien::OnCollisionEnter(b2Fixture * fixture)
{
}

void NewMagicien::OnCollisionLeave(b2Fixture * fixture)
{
	//std::cout < "Collision" << std::endl;
	//if (GetBody()->GetFixtureList()[0].GetFilterData().categoryBits !=
	//	fixture->GetFilterData().categoryBits)
	//{
	//	switch (fixture->GetFilterData().categoryBits)
	//	{
	//	case PLATFORM_CATEGORY: {
	//		
	//	} break;

	//	case BALL_CATEGORY: {
	//		std::cout << "BALL_CATEGORY" << std::endl;
	//	} break;

	//	default:
	//	{
	//	} break;
	//	}
	//}
}
