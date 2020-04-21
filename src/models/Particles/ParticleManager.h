#pragma once

#include <SFML\Graphics.hpp>
#include "../../engine/BaseEntity.h"

#include "Particle.h"

class ParticleManager : public BaseEntity {
private:

	const unsigned int SIZE = 512;
	const unsigned int PIXEL_ARRAY_SIZE = SIZE * SIZE * 4;

	const unsigned int PARTICLES_TTL = 500;
	const unsigned int PARTICLES_NBR = 1;
	
	sf::Uint8* pixels = new sf::Uint8[PIXEL_ARRAY_SIZE];
	sf::Texture texture;
	sf::Sprite sprite;

	std::vector<Particle> particles;

public:
	ParticleManager(sf::Vector2f _pixelPosition, sf::Int32 _creationTime);

	void update(const sf::Int32& _elapsedTime, const Inputs& _inputs) override;
	void draw(sf::RenderWindow& _render, float _interpolation) override;

	void removeDeadParticles();
};