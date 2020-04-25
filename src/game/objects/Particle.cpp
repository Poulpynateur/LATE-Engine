#include "Particle.h"

void Particle::update(const sf::Int32& _elapsedTime, const Inputs& _inputs){
	dismised = !isAlive(_elapsedTime);
	if (!dismised) {

		PhysicEntity::update(_elapsedTime, _inputs);

		previousSize = actualSize;
		actualSize = size * (1 - getLifePercent());
	}
}

void Particle::draw(sf::RenderWindow& _render, float _interpolation) {
	shape.setRadius(actualSize - (previousSize - actualSize) * _interpolation);
	_render.draw(shape);
}

void Particle::onCollision() {
	shape.setFillColor(sf::Color::Red);
}

void Particle::noCollision() {
	shape.setFillColor(sf::Color::White);
}
