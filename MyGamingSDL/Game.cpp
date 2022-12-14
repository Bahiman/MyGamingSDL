#include"Game.h"
#include <SDL2/SDL_image.h>

SDL_Texture* playerTex;
SDL_Rect srcR, destR;


Game::Game()
{
	puts("Constructor invoked!");
}

Game::~Game()
{
	puts("Destructor invoked!");
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen) flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems INITIALIZED!..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window)
		{
			puts("Window created successfully!");

		}

		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

			puts("Renderer Created successfully");
		} 

		isRunning = true;
	}
	else {
		isRunning = false;
	}

	SDL_Surface* tmpsSurface = IMG_Load("C:\\Users\\bahge\\source\\repos\\MyGamingSDL\\MyGamingSDL\\Untitled.png");

	playerTex = SDL_CreateTextureFromSurface(renderer, tmpsSurface);



}

void Game::update()
{
	cnt++;

	destR.h = 64;

	destR.w = 64;

	destR.x = cnt;

}

void Game::render()
{
	SDL_RenderClear(renderer);

	// Add things to render

	SDL_RenderCopy(renderer, playerTex, NULL, &destR);

	SDL_RenderPresent(renderer);

}

void Game::clean()
{
	SDL_DestroyWindow(window);

	SDL_DestroyRenderer(renderer);

	SDL_Quit();

	puts("Game cleaned!");


}

void Game::handleEvents()
{
	SDL_Event event;

	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;



	default:
		break;
	}
}
