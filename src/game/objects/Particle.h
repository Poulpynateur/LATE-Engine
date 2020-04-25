#pragma once

#include "../../models/physics/PhysicEntity.h"
#include "../../models/basic/EntityLifeTime.h"

class Particle : public PhysicEntity, public EntityLifeTime {

	float size = 50;

	int previousSize = 50;
	int actualSize = 50;
	
	sf::CircleShape shape;

public:
	// Why is it fine to use 'size' to inti 'shape' but not 'PhysicEntity'
	Particle(sf::Vector2f _pos, sf::Int32 _creationTime) : shape(sf::CircleShape(size)), EntityLifeTime(500, _creationTime), PhysicEntity(_pos, 50) {
		shape.setPosition(_pos);
	}

	void update(const sf::Int32& _elapsedTime, const Inputs& _inputs) override;
	void draw(sf::RenderWindow& _render, float _interpolation) override;

	virtual void onCollision() override;
	virtual void noCollision() override;
};