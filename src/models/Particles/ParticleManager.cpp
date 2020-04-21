#include "ParticleManager.h"
#include <iostream>

ParticleManager::ParticleManager(sf::Vector2f _pixelPosition, sf::Int32 _creationTime) {
	texture.create(SIZE, SIZE);
	sprite = sf::Sprite(texture);

	sprite.setPosition(sf::Vector2f(_pixelPosition.x - SIZE/2, _pixelPosition.y - SIZE / 2));

	srand(time(NULL));
	for (unsigned int i = 0; i < PARTICLES_NBR; i++) {
		particles.push_back(Particle(sf::Vector2i(SIZE / 2, SIZE / 2), _creationTime, PARTICLES_TTL));
	}

	// Init pixel as black transparent
	for (unsigned int i = 0; i < PIXEL_ARRAY_SIZE; i++) {
		pixels[i] = 0;
	}
}

void ParticleManager::update(const sf::Int32& _elapsedTime, const Inputs& _inputs) {
	std::cout << particles.size() << '\n';
	for (unsigned int i = 0; i < particles.size(); i++) {
		particles[i].update(_elapsedTime);
		int index = (particles[i].position.x + particles[i].position.y * SIZE) * 4;

		pixels[index] = particles[i].color.r;
		pixels[index + 1] = particles[i].color.g;
		pixels[index + 2] = particles[i].color.b;
		pixels[index + 3] = particles[i].color.a;
	}
	texture.update(pixels);

	removeDeadParticles();
}

void ParticleManager::draw(sf::RenderWindow& _render, float _interpolation) {
	for (unsigned int i = 0; i < particles.size(); i++) {
		int index = particles[i].calculateIndexFromInterpolation(_interpolation, SIZE);

		pixels[index] = particles[i].color.r;
		pixels[index + 1] = particles[i].color.g;
		pixels[index + 2] = particles[i].color.b;
		pixels[index + 3] = particles[i].color.a;
	}
	_render.draw(sprite);
}

void ParticleManager::removeDeadParticles() {
	particles.erase(
		std::remove_if(
			particles.begin(),
			particles.end(),
			[](Particle p) { return p.TTL <= 0; }
		),
		particles.end()
	);
}
