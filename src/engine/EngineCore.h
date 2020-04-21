#pragma once

#include <SFML/Graphics.hpp>
#include "BaseEntity.h"
#include "Config.h"
#include "Inputs.h"

constexpr int UPDATE_PER_SECOND = 25;
constexpr int UPDATE_INTERVAL = 1000 / UPDATE_PER_SECOND;
constexpr int MAX_UPDATES = 5;

class EngineCore {
private:
	
	Inputs inputs;

	sf::RenderWindow window;
	sf::Clock clock;

	void handleInputs();
	void handleLogic(BaseEntity* world);
	void handleRender(BaseEntity* world, float interpolation);

public:
	EngineCore(const Config& config)
		: window(sf::VideoMode(config.resolution.x, config.resolution.y), config.name)
	{}

	void mainLoop(BaseEntity* world);
};