#include "Particle.h"

Particle::Particle(sf::Vector2i _position, sf::Int32 _creation_time, sf::Int32 _TTL)
	: position(_position), creation_time(_creation_time), TTL(rand() % _TTL + 1)
{
	velocity = sf::Vector2i( (rand()% 20) - 10, (rand() % 20) - 10) ;
	color = sf::Color(255, 255, 255, 255);
}

void Particle::update(const sf::Int32& _elapsedTime) {
	sf::Int32 remaining_TTL = creation_time + TTL - _elapsedTime;

	position += velocity;
	color.a = remaining_TTL * 256/TTL;

	if (remaining_TTL < 0) {
		TTL = remaining_TTL;
	}
}

int Particle::calculateIndexFromInterpolation(float _interpolation, int size) {
	return ((position.x + velocity.x * _interpolation) + (position.y + velocity.y * _interpolation) * size) * 4;
}
