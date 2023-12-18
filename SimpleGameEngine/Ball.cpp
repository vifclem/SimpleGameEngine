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

	SpriteComponent* sc = new SpriteComponent(this, Assets::getTexture("Astroid"));
	bc = new BoxComponent(this, mSizeX, mSizeY);
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
	auto player = getGame().getPlayer();

	if (Intersect(*bcc, player->getCollision())) {

		if (bcc->getPosition().y + bcc->getSizeY() - 4 < player->getPosition().y) {
			
			if (mb->getUpwardSpeed() < 0) {
				mb->setUpwardSpeed(-mb->getUpwardSpeed());
			}
			else
			{
				mb->setUpwardSpeed(mb->getUpwardSpeed());
			}
		}
	}

	auto oponent = getGame().getOponent();

	if (Intersect(*bcc, oponent->getCollision())) {
		if (bcc->getPosition().y + bcc->getSizeY() - 30 < oponent->getPosition().y) {

			if (mb->getUpwardSpeed() > 0) {
				mb->setUpwardSpeed(-mb->getUpwardSpeed());
			}
			else
			{
				mb->setUpwardSpeed(mb->getUpwardSpeed());
			}
		}
	}
}



//make an update actor that check if ball is colliding and act by it.














