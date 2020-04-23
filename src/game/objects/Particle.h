#pragma once

#include "../../engine/BaseEntity.h"
#include "../../models/basic/EntityLifeTime.h"

class Particle : public BaseEntity, public EntityLifeTime {

	int size = 50;

	int previousSize = 50;
	int actualSize = 50;
	
	sf::CircleShape shape;

public:

	Particle(sf::Vector2f _pos, sf::Int32 _creationTime) : shape(sf::CircleShape(size)), EntityLifeTime(500, _creationTime) {
		shape.setPosition(_pos);
	}

	void update(const sf::Int32& _elapsedTime, const Inputs& _inputs) override;
	void draw(sf::RenderWindow& _render, float _interpolation) override;
};