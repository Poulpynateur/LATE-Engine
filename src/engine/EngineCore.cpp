#include "EngineCore.h"

void EngineCore::handleInputs() {
	if (window.hasFocus()) {
		inputs.mouseDown = sf::Mouse::isButtonPressed(sf::Mouse::Left);
		inputs.mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
	}
}

void EngineCore::handleLogic(BaseEntity* world){
	world->update(clock.getElapsedTime().asMilliseconds(), inputs);
}

void EngineCore::handleRender(BaseEntity* world, float interpolation){
	window.clear();
	world->draw(window, interpolation);
	window.display();
}

void EngineCore::mainLoop(BaseEntity* world) {
	double next_update_time = clock.getElapsedTime().asMilliseconds();
	int update_number;
	float interpolation;

	float interpo_time_elapsed;

	while (window.isOpen()) {

		update_number = 0;
		while (clock.getElapsedTime().asMilliseconds() > next_update_time && update_number < MAX_UPDATES)
		{
			handleInputs();
			handleLogic(world);

			next_update_time += UPDATE_INTERVAL;
			update_number++;
		}

		interpo_time_elapsed = clock.getElapsedTime().asMilliseconds() + UPDATE_INTERVAL - next_update_time;
		interpolation = interpo_time_elapsed / UPDATE_INTERVAL;

		handleRender(world, interpolation);
	}
}