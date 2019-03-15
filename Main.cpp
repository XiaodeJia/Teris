#include <SFML/Graphics.hpp>
#include <time.h>
#include "GameWindow.h"
#include "Tile.h"
#include "Background.h"
#include "Game.h"

int main()
{
	//srand(time(0));
	Game game;
	game.Run();

	return 0;
}