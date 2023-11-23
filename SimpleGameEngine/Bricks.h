#pragma once
#include "Actor.h"
#include "CircleCollisionComponent.h"

class Bricks : public Actor
{
public:
	Bricks();
	~Bricks();

	CircleCollisionComponent& getCollision() { return *collision; }

private:

	CircleCollisionComponent* collision;
	
};

