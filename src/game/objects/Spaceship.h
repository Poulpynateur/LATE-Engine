#pragma once

#include "../../models/DynamicEntity.h"

class Spaceship : public DynamicEntity {

	float speed = 10;
	float rotaSpeed = 10;

public:
	Spaceship(sf::Vector2f _pos);
	void update(const sf::Int32& _elapsedTime, const Inputs& _inputs) override;
};