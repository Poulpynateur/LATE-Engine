#include "EntitySpammer.h"

#include "../Particles/ParticleManager.h"
#include <iostream>

void EntitySpammer::update(const sf::Int32& _elapsedTime, const Inputs& _inputs) {

	if (_inputs.mouseDown && lastCreated + interval < _elapsedTime) {
		addChildren(new ParticleManager(_inputs.mousePos, _elapsedTime));
		lastCreated = _elapsedTime;
	}

	EntityGroup::update(_elapsedTime, _inputs);
}