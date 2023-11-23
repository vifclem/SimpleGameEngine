#include "Bricks.h"
#include "Random.h"
#include "Window.h"
#include "Math.h"
#include "Assets.h"
#include "BoxComponent.h"

Bricks::Bricks() :Actor(), collision(nullptr) {



	Vector2 randPos = Random::getVector(Vector2::zero, Vector2(WINDOW_WIDTH - 90, WINDOW_HEIGHT/2));

	Vector2 brickPos = Vector2{ 20, 200 };

    setPosition(brickPos);
	
	
	setRotation(0);

	BoxComponent* bc = new BoxComponent(this, 50, 20);

	collision = new CircleCollisionComponent(this);
	collision->setRadius(40);

	
	

}

Bricks::~Bricks() {
	//remove bricks
}