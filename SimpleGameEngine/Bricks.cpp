#include "Bricks.h"
#include "Random.h"
#include "Window.h"
#include "Math.h"
#include "Assets.h"
#include "BoxComponent.h"

Bricks::Bricks() :Actor() {

	Vector2 randPos = Random::getVector(Vector2::zero, Vector2(WINDOW_WIDTH - 90, WINDOW_HEIGHT/2));
	setPosition(randPos);
	setRotation(0);

	BoxComponent* bc = new BoxComponent(this, 50, 20);
	

}