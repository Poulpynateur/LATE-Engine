#pragma once
#include <SFML\Graphics\RenderWindow.hpp>
#include "Inputs.h"

class BaseEntity {
protected:
	bool dismised = false;
public:
	virtual void update(const sf::Int32& _elapsedTime, const Inputs& _inputs) = 0;
	virtual void draw(sf::RenderWindow& _render, float _interpolation) = 0;

	bool isDismised() {
		return dismised;
	}
};