#pragma once
#include "GameSettings.h"
#include "GameState.h"
#include <vector>
#include <string>
#include "Job.h"

class GameManager
{
private:
	int playerCount{};
	std::vector<Job *> jobs;
public:
	GameSettings *gameSettings;
	GameState *gameState;
	void Init();
	void Update(double time);
	std::string Print();
};

