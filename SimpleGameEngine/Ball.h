#pragma once
#include "Actor.h"
#include "InputComponent.h"
#include <SDL_stdinc.h>
#include "CircleCollisionComponent.h"
#include "Bricks.h"
#include "SpriteComponent.h"
#include "MoveBall.h"

class Ball : public Actor
{	
public :
	Ball(float mSizeX, float mSizeY);

	
private:
	

	BoxComponent* bc;
	MoveBall* mb;
};

