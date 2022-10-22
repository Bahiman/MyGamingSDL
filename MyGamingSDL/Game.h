#pragma once
#include<iostream>
#include"SDL.h"

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
	bool isRunning = true;

	SDL_Window* window = nullptr;

	SDL_Renderer* renderer = nullptr;

	unsigned int cnt = 0;

};

