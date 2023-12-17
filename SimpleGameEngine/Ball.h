#pragma once
#include "Actor.h"
#include "InputComponent.h"
#include <SDL_stdinc.h>
#include "Bricks.h"
#include "SpriteComponent.h"
#include "MoveBall.h"
#include "BoxCollisionComponent.h"

class Ball : public Actor
{	
public :
	Ball(float mSizeX, float mSizeY);
	void updateActor(float dt) override;


	
protected:
	
	BoxComponent* bc;
	MoveBall* mb;
	BoxCollisionComponent* bcc;
	
};

