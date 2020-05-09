#include "DynamicEntity.h"
#include <iostream>

void DynamicEntity::initShape(float _size) {
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineColor(sf::Color::White);
	shape.setOutlineThickness(1);
	shape.setOrigin(_size, _size);
}


/**** region CONSTRUCTOR ****/
DynamicEntity::DynamicEntity(sf::Vector2f _pos, float _size)
	: pos(_pos), shape(_size) {
	initShape(_size);
}

DynamicEntity::DynamicEntity(sf::Vector2f _pos, sf::Vector2f _mov, float _size)
	: pos(_pos), mov(_mov), shape(_size) {
	initShape(_size);
}
/**** region end ****/

/**** region BaseEntity ****/
void DynamicEntity::update(const sf::Int32& _elapsedTime, const Inputs& _inputs) {
	// Adapt movement vector to local rotation
	mov = transform.rotate(angle).transformPoint(mov);
	// Make logical pos match pos on screen
	pos = renderPos;
	angle = renderAngle;
}

void DynamicEntity::draw(sf::RenderWindow& _render, float _interpolation) {
	renderPos = pos + mov * _interpolation;
	renderAngle = angle + rotation * _interpolation;
	shape.setPosition(renderPos);
	shape.setRotation(renderAngle);
	_render.draw(shape);
}
/**** region end ****/

// reset values at the beginning of logical update 
void DynamicEntity::initLogicalUpdate() {
	// Reset values
	rotation = 0;
	mov.x = 0;
	mov.y = 0;
	transform = sf::Transform();
}