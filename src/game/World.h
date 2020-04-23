#pragma once

#include "../engine/BaseEntity.h"
#include "../models/basic/EntityGroup.h"
#include "objects/ParticleManager.h"

class World : public EntityGroup<BaseEntity> {
public:
	World();
};