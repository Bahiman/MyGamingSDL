#include"Game.h"

Game* game = nullptr;

int main(int argc, char*argv[]) {

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart = 0;
	int frame_time = 0;

	game = new Game();

	game->init("BahramGamesCo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 560, false);


	while (game->running()) {

		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frame_time = SDL_GetTicks() - frameStart;
		
		if (frameDelay > frame_time) {
			SDL_Delay(frameDelay - frame_time);
		}
	}

	game->clean();


	return 0;
}