#include "Player.h"
#include "Math.h"
#include "Assets.h"
#include "BoxComponent.h"
#include "SpriteComponent.h"
#include "Assets.h"
#include "InputComponent.h"


Player::Player(float mSizeX, float mSizeY) :Actor() {

	setPosition(Vector2{ 450, 700 });
	setSizeX(mSizeX);
	setSizeY(mSizeY);

	//SpriteComponent* ff = new SpriteComponent(this, Assets::getTexture("Paddle"));
	BoxComponent* bc = new BoxComponent(this, mSizeX, mSizeY);
	InputComponent* ic = new InputComponent(this);
	
	ic->setMaxForwardSpeed(400.0f);
	ic->setForwardKey(SDL_SCANCODE_D);
	ic->setBackKey(SDL_SCANCODE_A);
	ic->setlunchBallKey(2);
	ic->setClockwiseKey(2);
	ic->setCounterClockwiseKey(2);
}


