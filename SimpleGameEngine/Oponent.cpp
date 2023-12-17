#include "Oponent.h"
#include "Math.h"
#include "Assets.h"
#include "InputComponent.h"
#include "Game.h"


Oponent::Oponent(float mSizeX, float mSizeY) :Actor() {

	setPosition(Vector2{ 450, 50 });
	setSizeX(mSizeX);
	setSizeY(mSizeY);
	

	//SpriteComponent* ff = new SpriteComponent(this, Assets::getTexture("Paddle"));
	bc = new BoxComponent(this, mSizeX, mSizeY);

	InputComponent* ic = new InputComponent(this);


	ic->setMaxForwardSpeed(400.0f);
	ic->setForwardKey(SDL_SCANCODE_RIGHT);
	ic->setBackKey(SDL_SCANCODE_LEFT);
	ic->setlunchBallKey(2);
	ic->setClockwiseKey(2);
	ic->setCounterClockwiseKey(2);

	getGame().setOponent(this);

	bcc = new BoxCollisionComponent(this);
}
