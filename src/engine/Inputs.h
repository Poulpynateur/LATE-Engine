#pragma once

#include <SFML\Graphics.hpp>

enum InputsList {
	MOUSE_DOWN,
	ARROW_UP,
	ARROW_DOWN,
	ARROW_LEFT,
	ARROW_RIGHT,
	LAST_ENTRY
};

struct Inputs {
	sf::Vector2f mousePos;

	bool isTriggered[InputsList::LAST_ENTRY] = {false};
};

