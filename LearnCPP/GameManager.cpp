#include <string>
#include "GameManager.h"
#include "Job.h"

void GameManager::Init() {
	GameSettings settings;
	gameSettings = &settings;
	GameState state;
	gameState = &state;
	playerCount = 10;

	for (int i = 0; i < playerCount; i++) {
		StoneMinerJob miner;
		miner.Init(this);
		jobs.push_back(&miner);
		//jobs.at(0)->Work(1);
	}
}

void GameManager::Update(double time) {
	for (int i = 0; i < playerCount; i++) {
		jobs.at(i)->Work(time);
		//jobs[i]->Work(time);
	}
}

