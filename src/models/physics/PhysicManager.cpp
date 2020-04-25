#include "PhysicManager.h"

void PhysicManager::updateChildren(PhysicEntity* _children, const sf::Int32& _elapsedTime, const Inputs& _inputs) {
	for (unsigned int i = 0; i < childrens.size(); i++) {
		if (_children != childrens[i] && _children->isColliding(*childrens[i])) {
			break;
		}
	}
	EntityGroup<PhysicEntity>::template updateChildren(_children, _elapsedTime, _inputs);
}
