#include "Ball.h"
#include "Random.h"
#include "Window.h"
#include "Math.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Assets.h"



Ball::Ball(float mSizeX, float mSizeY) : Actor() {
	
	setSizeX(mSizeX);
	setSizeY(mSizeY);

	setPosition(Vector2{ 450, 400 });

	//SpriteComponent* sc = new SpriteComponent(this, Assets::getTexture("Astroid"));
	bc = new BoxComponent(this, mSizeX, mSizeY);
	mb = new MoveBall(this);
	mb->setForwardSpeed(300.0f);
	mb->setUpwardSpeed(300.0f);
	mb->setAngularSpeed(0.0f);
	getPosition();
	
}

//make an update actor that check if ball is colliding and act by it.














