#include "EntityGroup.h"

EntityGroup::~EntityGroup() {
	for (auto element : childrens) {
		delete element;
	}
	childrens.clear();
}

void EntityGroup::update(const sf::Int32& _elapsedTime, const Inputs& _inputs) {
	for (unsigned int i = 0; i < childrens.size(); i++) {
		childrens[i]->update(_elapsedTime, _inputs);
	}

	childrens.erase(
		std::remove_if(
			childrens.begin(),
			childrens.end(),
			[](BaseEntity* p) { return p->isDismised(); }
			),
		childrens.end()
		);
}

void EntityGroup::draw(sf::RenderWindow& _render, float _interpolation) {
	for (unsigned int i = 0; i < childrens.size(); i++) {
		childrens[i]->draw(_render, _interpolation);
	}
}

void EntityGroup::addChildren(BaseEntity* children) {
	childrens.push_back(children);
}
