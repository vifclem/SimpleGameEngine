#include "Ball.h"
#include "Random.h"
#include "Window.h"
#include "Math.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Assets.h"
#include "Game.h"



Ball::Ball(float mSizeX, float mSizeY) : Actor() {
	
	setSizeX(mSizeX);
	setSizeY(mSizeY);

	setPosition(Vector2{ 450, 400 });
	lastFramRegistered = this->getPosition();

	
	//bc = new BoxComponent(this, mSizeX, mSizeY);
	mb = new MoveBall(this);
	mb->setForwardSpeed(300.0f);
	mb->setUpwardSpeed(300.0f);
	mb->setAngularSpeed(0.0f);

	bcc = new BoxCollisionComponent(this);

	getPosition();

	getGame().setBall(this);
	
}

void Ball::updateActor(float dt)
{
	//player collision
	auto player = getGame().getPlayer();

	if (Intersect(*bcc, player->getCollision())) {

		if (lastFramRegistered.y + bcc->getSizeY()<= player->getPosition().y) {
			
			if (mb->getUpwardSpeed() < 0) {
				mb->setUpwardSpeed(-mb->getUpwardSpeed());
			}
			else
			{
				mb->setUpwardSpeed(mb->getUpwardSpeed());
			}
		}
	}

	//oponent collision
	auto oponent = getGame().getOponent();

	if (Intersect(*bcc, oponent->getCollision())) {
		if (lastFramRegistered.y <= oponent->getPosition().y + oponent->getSizeY()) {

			if (mb->getUpwardSpeed() > 0) {
				mb->setUpwardSpeed(-mb->getUpwardSpeed());
			}
			else
			{
				mb->setUpwardSpeed(mb->getUpwardSpeed());
			}
		}
	}

	 lastFramRegistered = bcc->getPosition();
}



//make an update actor that check if ball is colliding and act by it.














