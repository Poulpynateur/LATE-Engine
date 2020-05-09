#include "EngineCore.h"

void EngineCore::handleInputs() {
	if (window.hasFocus()) {
		inputs.mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
		inputs.isTriggered[InputsList::MOUSE_DOWN] = sf::Mouse::isButtonPressed(sf::Mouse::Left);
		inputs.isTriggered[InputsList::ARROW_UP] = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
		inputs.isTriggered[InputsList::ARROW_DOWN] = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
		inputs.isTriggered[InputsList::ARROW_LEFT] = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
		inputs.isTriggered[InputsList::ARROW_RIGHT] = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
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
	sf::Int32 next_update_time = clock.getElapsedTime().asMilliseconds();
	int update_number;
	float interpolation;

	while (window.isOpen()) {

		update_number = 0;
		while (clock.getElapsedTime().asMilliseconds() > next_update_time && update_number < MAX_UPDATES)
		{
			handleInputs();
			handleLogic(world);

			next_update_time += UPDATE_INTERVAL;
			update_number++;
		}

		interpolation = (clock.getElapsedTime().asMilliseconds() + UPDATE_INTERVAL - next_update_time) / (float)UPDATE_INTERVAL;

		handleRender(world, interpolation);
	}
}