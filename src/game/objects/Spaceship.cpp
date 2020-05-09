#include "Spaceship.h"

Spaceship::Spaceship(sf::Vector2f _pos) : DynamicEntity(_pos, 10)
{
	shape.setPointCount(3);
}

void Spaceship::update(const sf::Int32& _elapsedTime, const Inputs& _inputs) {

	DynamicEntity::initLogicalUpdate();

	if (_inputs.isTriggered[InputsList::ARROW_UP]) {
		mov.y = -speed;
	}
	if (_inputs.isTriggered[InputsList::ARROW_DOWN]) {
		mov.y = speed;
	}
	if (_inputs.isTriggered[InputsList::ARROW_LEFT]) {
		rotation = -rotaSpeed;
	}
	if (_inputs.isTriggered[InputsList::ARROW_RIGHT]) {
		rotation = rotaSpeed;
	}

	DynamicEntity::update(_elapsedTime, _inputs);
}
