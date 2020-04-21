#include "Game.h"
#include "../models/basic/EntitySpammer.h"

void Game::start()
{
	world->addChildren(new EntitySpammer());
	engine->mainLoop(world);
}
