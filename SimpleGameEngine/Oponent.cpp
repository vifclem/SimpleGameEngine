#include "Oponent.h"
#include "Math.h"
#include "Assets.h"
#include "BoxComponent.h"
#include "InputComponent.h"


Oponent::Oponent() :Actor() {

	setPosition(Vector2{ 450, 50 });
	setRotation(0);

	//SpriteComponent* ff = new SpriteComponent(this, Assets::getTexture("Paddle"));
	BoxComponent* bc = new BoxComponent(this, 100, 20);
	InputComponent* ic = new InputComponent(this);

	ic->setMaxForwardSpeed(400.0f);
	ic->setForwardKey(SDL_SCANCODE_LEFT);
	ic->setBackKey(SDL_SCANCODE_RIGHT);
	ic->setlunchBallKey(2);
	ic->setClockwiseKey(2);
	ic->setCounterClockwiseKey(2);

}
