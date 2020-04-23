#pragma once
#include <SFML\Config.hpp>
#include <iostream>

class EntityLifeTime {
	sf::Int32 TTL;
	sf::Int32 creationTime;
	sf::Int32 elapsedTime = 0;
public:

	EntityLifeTime(sf::Int32 _TTL, sf::Int32 _creationTime)
		: TTL(_TTL), creationTime(_creationTime) {}

	bool isAlive(sf::Int32 _elapsedTime) {
		elapsedTime = _elapsedTime - creationTime;
		return elapsedTime < TTL;
	}

	float getLifePercent() {
		return elapsedTime / (float)TTL;
	}
};