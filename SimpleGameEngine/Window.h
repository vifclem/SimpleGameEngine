#pragma once
#include <SDL.h>

constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 450;

class Window
{


	SDL_Window* window{ nullptr };
	int width{ WINDOW_WIDTH };
	int height{ WINDOW_HEIGHT };

public:
	Window() = default;

};

