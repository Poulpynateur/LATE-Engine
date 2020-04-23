#include "ParticleManager.h"

bool ParticleManager::trigger(const sf::Int32& _elapsedTime, const Inputs& _inputs) {
	if (_inputs.mouseDown) {
		return true;
	}
	return false;
}

void ParticleManager::spawnChildren(const sf::Int32& _elapsedTime, const Inputs& _inputs) {
	this->addChildren(new Particle(_inputs.mousePos, _elapsedTime));
}
