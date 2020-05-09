#include "World.h"

World::World() {
	this->addChildren(new Spaceship(sf::Vector2f(100,100)));
	this->addChildren(new Asteroid(sf::Vector2f(100,100), sf::Vector2f(2, 2)));
}