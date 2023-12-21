#include "MoveBall.h"
#include "Maths.h"
#include "Actor.h"
#include "BoxComponent.h"
#include <SDL_scancode.h>
#include "Game.h"
#include <iostream>

using namespace std;

MoveBall::MoveBall(Actor* ownerP) :
	MoveComponent(ownerP), playerScore(0.0f), ennemieScore(0.0f), player(), ennemie(), game(Game::instance())
{
}

void MoveBall::update(float dt)
{

	if (!Maths::nearZero(angularSpeed))
	{
		float newRotation = owner.getRotation() + angularSpeed * dt;
		owner.setRotation(newRotation);
	}

	// Collision with the window
	if (!Maths::nearZero(forwardSpeed) && !Maths::nearZero(upwardSpeed))
	{

		if (owner.getPosition().x < 0) {
			setForwardSpeed(abs(getForwardSpeed()));
		}
		else if (owner.getPosition().x + owner.getSizeX() > WINDOW_WIDTH) {
			setForwardSpeed(-abs(getForwardSpeed()));
		}

		if (owner.getPosition().y < 0) {
			setUpwardSpeed(-abs(getUpwardSpeed()));
			
			playerScore += 1;
			owner.setPosition(Vector2{ 400,400 });
		}
		else if (owner.getPosition().y + owner.getSizeY() > WINDOW_HEIGHT) {
			setUpwardSpeed(abs(getUpwardSpeed()));
			ennemieScore += 1;
			owner.setPosition(Vector2{ 400,400 });
		}

		Vector2 newPosition = owner.getPosition() + owner.getForward() * forwardSpeed * dt + owner.getUpward() * upwardSpeed * dt;
		owner.setPosition(newPosition);
	}

	if (playerScore >= 5) {
		//close window
		getGame().Win();
		if (playerScore >= 6) {
			getGame().EndGame();
			cout << "You WON !!" << endl;
		}
	}
	

	if (ennemieScore >= 5) {
		//close window
		getGame().Lost();
		if (ennemieScore >= 6) {
			getGame().EndGame();
			cout << "You LOST !!" << endl;
		}
	}
}

float MoveBall::getForwardSpeed()
{
	return forwardSpeed;
}

float MoveBall::getUpwardSpeed()
{
	return forwardSpeed;
}

