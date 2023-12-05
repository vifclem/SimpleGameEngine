#include "MoveBall.h"
#include "Maths.h"
#include "Actor.h"
#include "Window.h"
#include "BoxComponent.h"
#include <SDL_scancode.h>

MoveBall::MoveBall(Actor* ownerP) :
	MoveComponent(ownerP), playerScore(0.0f), ennemieScore(0.0f)
{
}

void MoveBall::update(float dt)
{
	//MoveComponent::update(dt);

	if (!Maths::nearZero(angularSpeed))
	{
		float newRotation = owner.getRotation() + angularSpeed * dt;
		owner.setRotation(newRotation);
	}

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
	}

	if (ennemieScore >= 5) {
		//close window
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