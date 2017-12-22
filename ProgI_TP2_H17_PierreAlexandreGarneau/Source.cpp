
#include "Scene.h"
#include "SpriteAnimation.h"
#include "NewMagicien.h"
#include "SpongeBob.h"
#include "Text.h"
#include "TextFF.h"
#include "CollisionSprite.h"
#include "MapSprite.h"

int main(int argc, char* args[])
{
	gEngine->Init();
	gEngine->SetNativeResolution(800, 600);
	gPhysics->GetWorld()->SetGravity(b2Vec2(.0f, .0f));
	// Load les textures
	Textures->LoadTexture(Texture::ID::TextFF, "TextFF.png");
	Textures->LoadTexture(Texture::ID::SpriteSheetReal, "animationReal.png");
	Textures->LoadTexture(Texture::ID::LeifenMap, "LeifenMap.png");

	//Textures->LoadTexture(Texture::ID::Patrick, "Patrick.bmp");
	//Textures->LoadTexture(Texture::ID::SpriteSheet, "animationTest.png");
	
	// Création des objets
	Scene* scene = new Scene("Main");
	gEngine->AddScene(scene);

	// Trouve la destination exacte du frame souhaité
	//SDL_Rect frame;
	//frame.x = 96;
	//frame.y = 19;
	//frame.w = 25;
	//frame.h = 25;

	// Trouve la destination exacte du frame souhaité
	//SDL_Rect frameReal;
	//frameReal.x = 180;
	//frameReal.y = 35;
	//frameReal.w = 19;
	//frameReal.h = 25;

	//scene->SetCameraShake(true);

	//SpriteAnimation* test = new SpriteAnimation(Texture::SpriteSheet, &frame, 3);
	//scene->AddComponent(test);

	//b2Vec2 bob1pos = b2Vec2(50, 50);
	//float bob1rot = 45;
	
	//SpongeBob* bob1 = new SpongeBob(1.0f);
	//bob1->GetBody()->SetTransform(b2Vec2(200, 0), 0.0f);
	//bob1->SetPosition(bob1pos);
	//bob1->SetRotation(bob1rot);
	//bob1->SetFlip(SDL_FLIP_HORIZONTAL);
	
	//SpongeBob* bob2 = new SpongeBob();
	//bob2->GetBody()->SetTransform(b2Vec2(200, 400), 0.0f);
	//bob2->SetPosition(b2Vec2(500, 0));

	//************************************
	//Vector2D Leifenpos = Vector2D(1000, 50);
	//float Leifenrot = 45;

	//Leifen* Leifen1 = new Leifen();
	//Leifen1->SetPosition(Leifenpos);
	//Leifen1->SetRotation(Leifenrot);

	//Leifen* Leifen2 = new Leifen();
	//Leifen2->SetPosition(Vector2D(500, 0));

	//************************************
	//mag1->GetBody()->SetTransform(b2Vec2(200, 0), 0.0f);

	//Magicien* mag2 = new Magicien();
	//mag2->GetBody()->SetTransform(b2Vec2(200, 400), 0.0f);

	MapSprite* map = new MapSprite(Texture::ID::LeifenMap, 100);
	scene->AddComponent(map);

	CollisionSprite* top = new CollisionSprite(map, 0, 0, 2050, 10, CollisionDirection::Top);
	scene->AddComponent(top);

	CollisionSprite* down = new CollisionSprite(map, 0, 1550, 2050, 10, CollisionDirection::Down);
	scene->AddComponent(down);

	CollisionSprite* left = new CollisionSprite(map, 0, 0, 10, 1550, CollisionDirection::Left);
	scene->AddComponent(left);

	CollisionSprite* right = new CollisionSprite(map, 2050, 0, 10, 1550, CollisionDirection::Right);
	scene->AddComponent(right);

	SDL_Rect srcRect;
	srcRect.h = 14;
	srcRect.w = 14;
	srcRect.x = 6;
	srcRect.y = 276;

	SpriteAnimation* mage = new NewMagicien(&srcRect);
	scene->AddComponent(mage);

	TextFF* Text1 = new TextFF();
	TextFF* T1 = new TextFF(1.0f);
	scene->AddComponent(Text1);

	//SpriteAnimation* walkLeft = new SpriteAnimation(Texture::SpriteSheetReal, &frameReal, 3);
	//Real->SetFlip(SDL_FLIP_HORIZONTAL);
	//Real->SetNumFrame(2);
	//frameReal.x = 237;
	//Real->SetVisible(false);

	//SpriteAnimation* walkDown = new SpriteAnimation(Texture::SpriteSheetReal, &frameReal, 1);;
	
	//scene->AddComponent(Real2);
	
	//scene->AddComponent(bob1);
	//scene->AddComponent(bob2);

	//scene->AddComponent(mag1);
	//scene->AddComponent(mag2);

	//scene->AddComponent(Leifen1);


	Text* text = new Text();
	scene->AddComponent(text);

	gEngine->LoadScene("Main");

	gEngine->Run();

	return 0;
}