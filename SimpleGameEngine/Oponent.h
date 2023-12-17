#pragma once
#include "Actor.h"
#include <SDL_stdinc.h>
#include "BoxCollisionComponent.h"
#include "BoxComponent.h"
class Oponent : public Actor
{
public:
	Oponent(float mSizeX, float mSizeY);

	BoxCollisionComponent& getCollision() { return *bcc; }
protected:

	BoxCollisionComponent* bcc;
	BoxComponent* bc;
};

