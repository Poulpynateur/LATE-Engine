#pragma once

#include "Particle.h"
#include "../../models/basic/EntitySpammer.h"
#include "../../models/physics/PhysicManager.h"

class ParticleManager : public EntitySpammer, public PhysicManager {
public:

	ParticleManager()
	: EntitySpammer(100) {}

	bool trigger(const sf::Int32& _elapsedTime, const Inputs& _inputs) override;
	void spawnChildren(const sf::Int32& _elapsedTime, const Inputs& _inputs) override;

	void update(const sf::Int32& _elapsedTime, const Inputs& _inputs);
};