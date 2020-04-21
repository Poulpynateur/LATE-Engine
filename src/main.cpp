#include <SFML/Graphics.hpp>

#include "game/Game.h"

int main()
{
    Game* game = new Game();
    game->start();
    delete game;
}