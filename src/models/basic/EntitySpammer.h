#pragma once

#include <SFML\Window\Mouse.hpp>
#include "EntityGroup.h"

class EntitySpammer : public EntityGroup {
	sf::Int32 interval = 100;
	sf::Int32 lastCreated = 0;
public:
	virtual void update(const sf::Int32& _elapsedTime, const Inputs& _inputs) override;
};