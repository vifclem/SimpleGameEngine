#include "Asteroid.h"
#include "Random.h"
#include "Window.h"
#include "Maths.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Assets.h"
#include "Game.h"

Asteroid::Asteroid() : Actor(), collision(nullptr)
{
	Vector2 randPos = Random::getVector(Vector2::zero, Vector2(WINDOW_WIDTH, WINDOW_HEIGHT));
	setPosition(randPos);
	setRotation(Random::getFloatRange(0.0f, Maths::twoPi));

	SpriteComponent* sc = new SpriteComponent(this, Assets::getTexture("Astroid"));
	MoveComponent* mc = new MoveComponent(this);
	mc->setForwardSpeed(150.0f);

	collision = new CircleCollisionComponent(this);
	collision->setRadius(40.0f);

	getGame().addAstroid(this);
}

Asteroid::~Asteroid()
{
	getGame().removeAstroid(this);
}