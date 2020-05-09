#pragma once

#include "../../models/DynamicEntity.h"

class Asteroid : public DynamicEntity {
public:
	Asteroid(sf::Vector2f _pos, sf::Vector2f _mov);
};