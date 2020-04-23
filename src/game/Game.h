#pragma once

#include "../engine/EngineCore.h"
#include "../engine/Config.h"
#include "World.h"

class Game {
private:

	EngineCore* engine = new EngineCore(Config());
	World* world = new World();

public:
	~Game() { delete engine; delete world; }
	void start();
};