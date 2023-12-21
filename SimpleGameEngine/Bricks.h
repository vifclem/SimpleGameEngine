#pragma once
#include "Actor.h"
#include "BoxComponent.h"
class Bricks : public Actor
{
public:
	Bricks(float mSizeX, float mSizeY);
	~Bricks();

	

protected:

	BoxComponent* bc;
	
};

