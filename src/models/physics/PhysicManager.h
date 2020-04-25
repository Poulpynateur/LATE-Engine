#pragma once

#include "../basic/EntityGroup.h"
#include "PhysicEntity.h"

class PhysicManager : public EntityGroup<PhysicEntity> {
public:

	virtual void updateChildren(PhysicEntity* _children, const sf::Int32& _elapsedTime, const Inputs& _inputs);
};