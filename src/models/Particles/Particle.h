#pragma once

#include <SFML\Graphics.hpp>

struct Particle {
	sf::Color color;
	sf::Vector2i position;
	sf::Vector2i velocity;

	sf::Int32 creation_time;
	sf::Int32 TTL;

	Particle(sf::Vector2i _position, sf::Int32 creation_time, sf::Int32 _TTL);
	void update(const sf::Int32& _elapsedTime);
	int calculateIndexFromInterpolation(float _interpolation, int size);
};