#include "TextFF.h"

TextFF::TextFF()
	: Sprite(Texture::ID::TextFF, true, true)
	, speed(100)
{
	b2Filter filter;
	filter.categoryBits = PLATFORM_CATEGORY;

	CreateCollider(ColliderType::SQUARE_COLLIDER, dstRect->w, dstRect->h, 0.0f);
	GetBody()->GetFixtureList()[0].SetFilterData(filter);
}

TextFF::TextFF(float mass)
	: Sprite(Texture::ID::TextFF, true, true)
{ 
}

TextFF::~TextFF()
{
}

void TextFF::Start()
{
}

void TextFF::Update()
{
	Sprite::Update();
}

void TextFF::OnCollisionEnter(b2Fixture * fixture)
{
	//std::cout << "Collision" << std::endl;
	//if (GetBody()->GetFixtureList()[0].GetFilterData().categoryBits !=
	//	fixture->GetFilterData().categoryBits)
	//{
	//	switch (fixture->GetFilterData().categoryBits)
	//	{
	//	case PLATFORM_CATEGORY: {
	//		std::cout << "PLATFORM_CATEGORY" << std::endl;
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

void TextFF::OnCollisionLeave(b2Fixture * fixture)
{

}
