#include"SDL.h"
#include"Game.h"

Game* game = nullptr;

int main(int argc, char*argv[]) {

	game = new Game();

	game->init("BahramGamesCo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, true);



	while (game->running()) {
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();


	return 0;
}