#include "Ball.h"
#include "Random.h"
#include "Window.h"
#include "Math.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Assets.h"

Ball::Ball() :Actor() {
	
	setPosition(Vector2{ 500, 650 });
	setRotation(190);

	SpriteComponent* sc = new SpriteComponent(this, Assets::getTexture("Astroid"));
	MoveComponent* mc = new MoveComponent(this);
	mc->setForwardSpeed(170.0f);

}


