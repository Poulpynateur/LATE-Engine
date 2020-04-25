#pragma once

#include <SFML\Window\Mouse.hpp>
#include "EntityGroup.h"

class EntitySpammer {

	sf::Int32 lastCreated = 0;
	sf::Int32 frequence;

public:

	EntitySpammer(sf::Int32 _frequence)
		: frequence(_frequence)
	{}

	virtual bool trigger(const sf::Int32& _elapsedTime, const Inputs& _inputs) = 0;
	virtual void spawnChildren(const sf::Int32& _elapsedTime, const Inputs& _inputs) = 0;

	void checkTrigger(const sf::Int32& _elapsedTime, const Inputs& _inputs) {
		if (lastCreated + frequence < _elapsedTime && trigger(_elapsedTime, _inputs)) {
			spawnChildren(_elapsedTime, _inputs);
			lastCreated = _elapsedTime;
		}
	}
};