#pragma once
#include "Actor.h"
#include <SDL_stdinc.h>
#include "BoxCollisionComponent.h"
#include "BoxComponent.h"
#include "InputComponent.h"

class Player : public Actor
{
public:
	Player(float mSizeX, float mSizeY);
	

	BoxCollisionComponent& getCollision() { return *bcc; }

protected:
	BoxCollisionComponent* bc;
	InputComponent* ic;
	BoxCollisionComponent* bcc;
};

