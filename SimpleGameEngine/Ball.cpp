#include "Ball.h"
#include "Random.h"
#include "Window.h"
#include "Math.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Assets.h"



Ball::Ball() : Actor() {
	
	
	setPosition(Vector2{ 450, 400 });
	setRotation(190);

	SpriteComponent* sc = new SpriteComponent(this, Assets::getTexture("Astroid"));
	MoveComponent* mc = new MoveComponent(this);
	InputComponent* ic = new InputComponent(this);
	ic->setClockwiseKey(SDL_SCANCODE_RIGHT);
	ic->setCounterClockwiseKey(SDL_SCANCODE_LEFT);
	ic->setMaxForwardSpeed(300.0f);
	mc->setForwardSpeed(300.0f);
	ic->setForwardKey(2);
	ic->setBackKey(2);
	
}











