#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../engine/BaseEntity.h"

// For now let just use round hitbox (simple radius)

class PhysicEntity : public BaseEntity {
protected:

	bool collision = false;

	// Pixel
	float hitbox;

	// For the day I will use world coordinates
	sf::Vector2f position;
	sf::Vector2f screenPosition;

	sf::Vector2f movement;

public:

	PhysicEntity(sf::Vector2f _position, float _radius)
		: position(_position), hitbox(_radius){}

	
	unsigned int getHitbox() {
		return hitbox;}
	sf::Vector2f getPos() {
		return position;}
	
	bool isColliding(PhysicEntity& target) {
		collision = ((target.getPos().x - position.x) * (target.getPos().x - position.x) + (target.getPos().y - position.y) * (target.getPos().y - position.y))
			<= ((target.getHitbox() + hitbox) * (target.getHitbox() + hitbox));
		return collision;
	}

	virtual void onCollision() = 0;
	virtual void noCollision() = 0;

	virtual void update(const sf::Int32& _elapsedTime, const Inputs& _inputs) override {
		if (collision)
			onCollision();
		else
			noCollision();
	}
	virtual void draw(sf::RenderWindow& _render, float _interpolation) override {
		if (!collision)
			screenPosition = position + movement * _interpolation;
	}
};