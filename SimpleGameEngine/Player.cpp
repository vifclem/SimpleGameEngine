#include "Player.h"
#include "Random.h"
#include "Window.h"
#include "Math.h"
#include "Assets.h"
#include "BoxComponent.h"


Player::Player() :Actor() {

	setPosition(Vector2{ 450, 700 });
	setRotation(0);

	BoxComponent* bc = new BoxComponent(this, 100, 20);

	
}

void Player::actorInput(const Uint8* keyState)
{
	if (keyState[SDL_SCANCODE_D])
	{
		//move right player actor 
	}
	if (keyState[SDL_SCANCODE_A])
	{
		//move left player actor 
	}
}