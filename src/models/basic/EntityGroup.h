#pragma once

#include "../../engine/BaseEntity.h"

template<class Children = BaseEntity>
class EntityGroup : public BaseEntity {
protected:
	std::vector<Children*> childrens;

public:
	~EntityGroup() {
		for (auto children : childrens) {
			delete children;
		}
		childrens.clear();
	}

	virtual void update(const sf::Int32& _elapsedTime, const Inputs& _inputs) override {
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

	virtual void draw(sf::RenderWindow& _render, float _interpolation) override {
		for (unsigned int i = 0; i < childrens.size(); i++) {
			childrens[i]->draw(_render, _interpolation);
		}
	}

	void addChildren(Children* children) {
		childrens.push_back(children);
	}
};