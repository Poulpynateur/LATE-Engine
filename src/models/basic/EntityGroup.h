#pragma once

#include "../../engine/BaseEntity.h"

class EntityGroup : public BaseEntity {
protected:
	std::vector<BaseEntity*> childrens;

public:
	~EntityGroup();

	virtual void update(const sf::Int32& _elapsedTime, const Inputs& _inputs) override;
	virtual void draw(sf::RenderWindow& _render, float _interpolation) override;

	void addChildren(BaseEntity* children);
};