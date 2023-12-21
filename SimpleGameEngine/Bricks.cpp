#include "Bricks.h"
#include "Window.h"
#include "Game.h"

Bricks::Bricks(float mSizeX, float mSizeY) :Actor() {

	setSizeX(mSizeX);
	setSizeY(mSizeY);

    setPosition(Vector2{ 200, 200 });
	

    bc = new BoxComponent(this, mSizeX, mSizeY);

	
	getGame().setBricks(this);
	
	

}

Bricks::~Bricks() {
	//remove bricks
}