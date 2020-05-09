#pragma once

#include "../engine/BaseEntity.h"
#include "../models/basic/EntityGroup.h"

#include "objects/Spaceship.h"
#include "objects/Asteroid.h"

class World : public EntityGroup<BaseEntity> {
public:
	World();
};