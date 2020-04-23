#include "Game.h"
#include "../models/basic/EntitySpammer.h"

void Game::start()
{
	engine->mainLoop(world);
}
