#include "World.h"

World::World() {
	this->addChildren(new ParticleManager());
}
