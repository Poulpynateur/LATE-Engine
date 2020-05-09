#pragma once

#include "../engine/BaseEntity.h"

class DynamicEntity: public BaseEntity {
protected:
	sf::CircleShape shape;
	sf::Transform transform;

	// Between logical updates pos/angle can vary
	sf::Vector2f renderPos = sf::Vector2f();
	float renderAngle = 0;

	sf::Vector2f pos = sf::Vector2f();
	sf::Vector2f mov = sf::Vector2f();

	float angle = 0;
	float rotation = 0;

	void initShape(float _size);

	void initLogicalUpdate();
public:

	DynamicEntity(sf::Vector2f _pos, float _size);
	DynamicEntity(sf::Vector2f _pos, sf::Vector2f _mov, float _size);

	virtual void update(const sf::Int32& _elapsedTime, const Inputs& _inputs) override;
	virtual void draw(sf::RenderWindow& _render, float _interpolation) override;
};