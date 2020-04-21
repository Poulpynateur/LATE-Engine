#pragma once

#include "../engine/EngineCore.h"
#include "../engine/Config.h"
#include "../models/basic/EntityGroup.h"

class Game {
private:

	EngineCore* engine = new EngineCore(Config());
	EntityGroup* world = new EntityGroup();

public:
	~Game() { delete engine; delete world; }
	void start();
};