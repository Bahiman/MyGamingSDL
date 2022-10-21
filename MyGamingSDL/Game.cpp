#include"Game.h"

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
}

void Game::update()
{
	cnt++;
	printf("%d", cnt);

}

void Game::render()
{
	SDL_RenderClear(renderer);

	// Add things to render

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
