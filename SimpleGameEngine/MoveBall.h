#pragma once
#include "MoveComponent.h"
#include <SDL_stdinc.h>
#include "Window.h"

class MoveBall : public MoveComponent
{
public:
	MoveBall(Actor* ownerP);
	MoveBall() = delete;
	MoveBall(const MoveBall&) = delete;
	MoveBall& operator=(const MoveBall&) = delete;

	void update(float dt) override;

	float getForwardSpeed();
	float getUpwardSpeed();

private:
	float playerScore;
	float ennemieScore;
	Actor* ennemie;
	Actor* player;
	Window window;
};