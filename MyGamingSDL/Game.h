#pragma once
#include<iostream>
#include"SDL2/sdl.h"

class Game {
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void update();
	void render();
	void clean();
	

	bool running() {return isRunning;};

	void handleEvents();

private:
	bool isRunning;

	SDL_Window* window;

	SDL_Renderer* renderer;

	unsigned int cnt;

};

