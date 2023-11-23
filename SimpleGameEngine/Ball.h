#pragma once
#include "Actor.h"
#include "InputComponent.h"
#include <SDL_stdinc.h>
#include "CircleCollisionComponent.h"
#include "Bricks.h"

class Ball : public Actor
{	
public :
	Ball();

	//void updateActor(float dt) override;

private:
	//CircleCollisionComponent* collision;

};

