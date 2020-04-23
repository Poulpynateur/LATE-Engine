#pragma once

#include "Particle.h"
#include "../../models/basic/EntitySpammer.h"

class ParticleManager : public EntitySpammer<Particle> {
public:

	ParticleManager()
	: EntitySpammer<Particle>(100) {}

	bool trigger(const sf::Int32& _elapsedTime, const Inputs& _inputs) override;
	void spawnChildren(const sf::Int32& _elapsedTime, const Inputs& _inputs) override;
};