#pragma once
#include <SFML\System\String.hpp>
#include <SFML\System\Vector2.hpp>

struct Config {
	sf::String name = "Game";
	sf::Vector2u resolution = sf::Vector2u(800, 800);
};