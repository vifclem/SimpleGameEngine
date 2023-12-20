#include "Game.h"
#include "Actor.h"
#include "SpriteComponent.h"
#include "AnimSpriteComponent.h"
#include "Timer.h"
#include "Assets.h"
#include "BackgroundSpriteComponent.h"
#include "BoxComponent.h"
#include "Bricks.h"
#include "MoveBall.h"


bool Game::initialize()
{
	bool isWindowInit = window.initialize();
	bool isRendererInit = renderer.initialize(window);
	return isWindowInit && isRendererInit; // Return bool && bool && bool ...to detect error
}

void Game::load()
{
	// Load textures
	Assets::loadTexture(renderer, "Res\\Ship01.png", "Ship01");
	Assets::loadTexture(renderer, "Res\\Ship02.png", "Ship02");
	Assets::loadTexture(renderer, "Res\\Ship03.png", "Ship03");
	Assets::loadTexture(renderer, "Res\\Ship04.png", "Ship04");
	Assets::loadTexture(renderer, "Res\\Farback01.png", "Farback01");
	Assets::loadTexture(renderer, "Res\\Farback02.png", "Farback02");
	Assets::loadTexture(renderer, "Res\\Stars.png", "Stars");
	Assets::loadTexture(renderer, "Res\\Astroid.png", "Astroid");
	Assets::loadTexture(renderer, "Res\\Ship.png", "Ship");
	Assets::loadTexture(renderer, "Res\\Laser.png", "Laser");
	Assets::loadTexture(renderer, "Res\\Ball.png", "Ball");
	Assets::loadTexture(renderer, "Res\\Wall.png", "Wall");
	Assets::loadTexture(renderer, "Res\\Player.png", "Player");
	Assets::loadTexture(renderer, "Res\\Win.png", "Win");
	Assets::loadTexture(renderer, "Res\\Lost.png", "Lost");




	new Player((int)Assets::getTexture("Player").getWidth(), (int)Assets::getTexture("Player").getHeight());
	SpriteComponent* wallSprite = new SpriteComponent(player, Assets::getTexture("Player"));

	new Oponent((int)Assets::getTexture("Wall").getWidth(), (int)Assets::getTexture("Wall").getHeight());
	SpriteComponent* wallSprite2 = new SpriteComponent(oponent, Assets::getTexture("Wall"));

	new Ball((int)Assets::getTexture("Ball").getWidth(), (int)Assets::getTexture("Ball").getHeight());
	SpriteComponent* ballSprite = new SpriteComponent(ball, Assets::getTexture("Ball"));

	// Animated sprite
	/*
	vector<Texture*> animTextures {
		&Assets::getTexture("Ship01"),
		&Assets::getTexture("Ship02"),
		&Assets::getTexture("Ship03"),
		&Assets::getTexture("Ship04"),
	};
	Actor* ship = new Actor();
	AnimSpriteComponent* animatedSprite = new AnimSpriteComponent(ship, animTextures);
	ship->setPosition(Vector2{ 100, 300 });
	*/

	//// Controlled ship
	//Ship* ship = new Ship();
	//ship->setPosition(Vector2{ 100, 300 });

	// Background
	// Create the "far back" background
	vector<Texture*> bgTexsFar {
		&Assets::getTexture("Farback01"),
			& Assets::getTexture("Farback02")
	};
	Actor* bgFar = new Actor();
	BackgroundSpriteComponent* bgSpritesFar = new BackgroundSpriteComponent(bgFar, bgTexsFar);
	bgSpritesFar->setScrollSpeed(-100.0f);

	// Create the closer background
	/*Actor* bgClose = new Actor();
	std::vector<Texture*> bgTexsClose {
		&Assets::getTexture("Stars"),
			& Assets::getTexture("Stars")
	};
	BackgroundSpriteComponent* bgSpritesClose = new BackgroundSpriteComponent(bgClose, bgTexsClose, 50);
	bgSpritesClose->setScrollSpeed(-200.0f);*/
	
	

}

Player* Game::getPlayer() {

	return player;
}

void Game::setPlayer(Player* playerP) {

	player = playerP;
}



Oponent* Game::getOponent() {
	return oponent;
}

void Game::setOponent(Oponent* oponentP) {
	oponent = oponentP;
}



Ball* Game::getBall() {
	return ball;
}

void Game::setBall(Ball* ballP) {
	ball = ballP;
}

void Game::Win()
{
	
	new Ball((int)Assets::getTexture("Win").getWidth(), (int)Assets::getTexture("Win").getHeight());
	SpriteComponent* winSprite = new SpriteComponent(ball, Assets::getTexture("Win"));
}

void Game::Lost()
{
	new Ball((int)Assets::getTexture("Lost").getWidth(), (int)Assets::getTexture("Lost").getHeight());
	SpriteComponent* lostSprite = new SpriteComponent(ball, Assets::getTexture("Lost"));


}

void Game::EndGame()
{
	isRunning = false;
	close();
}



void Game::processInput()
{
	// SDL Event
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;
		}
	}

	// Keyboard state
	const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
	// Escape: quit game
	if (keyboardState[SDL_SCANCODE_ESCAPE])
	{
		isRunning = false;
	}
	// Actor input
	isUpdatingActors = true;
	for (auto actor : actors)
	{
		actor->processInput(keyboardState);
	}
	isUpdatingActors = false;
}

void Game::update(float dt)
{
	// Update actors 
	isUpdatingActors = true;
	for (auto actor : actors)
	{
		actor->update(dt);
	}
	isUpdatingActors = false;

	// Move pending actors to actors
	for (auto pendingActor : pendingActors)
	{
		actors.emplace_back(pendingActor);
	}
	pendingActors.clear();

	// Delete dead actors
	vector<Actor*> deadActors;
	for (auto actor : actors)
	{
		if (actor->getState() == Actor::ActorState::Dead)
		{
			deadActors.emplace_back(actor);
		}
	}
	for (auto deadActor : deadActors)
	{
		delete deadActor;
	}
}

void Game::render()
{
	renderer.beginDraw();
	renderer.draw();
	renderer.endDraw();
}


void Game::loop()
{
	Timer timer;
	float dt = 0;
	while (isRunning)
	{
		float dt = timer.computeDeltaTime() / 1000.0f;
		processInput();
		update(dt);
		render();
		timer.delayTime();
	}
}

void Game::unload()
{
	// Delete actors
	// Because ~Actor calls RemoveActor, have to use a different style loop
	while (!actors.empty())
	{
		delete actors.back();
	}

	// Resources
	Assets::clear();
}

void Game::close()
{
	renderer.close();
	window.close();
	SDL_Quit();
}

void Game::addActor(Actor* actor)
{
	if (isUpdatingActors)
	{
		pendingActors.emplace_back(actor);
	}
	else
	{
		actors.emplace_back(actor);
	}
}

void Game::removeActor(Actor* actor)
{
	// Erase actor from the two vectors
	auto iter = std::find(begin(pendingActors), end(pendingActors), actor);
	if (iter != end(pendingActors))
	{
		// Swap to end of vector and pop off (avoid erase copies)
		std::iter_swap(iter, end(pendingActors) - 1);
		pendingActors.pop_back();
	}
	iter = std::find(begin(actors), end(actors), actor);
	if (iter != end(actors))
	{
		std::iter_swap(iter, end(actors) - 1);
		actors.pop_back();
	}
}