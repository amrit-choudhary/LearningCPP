#include <iostream>
#include "Job.h"
#include "GameManager.h"

void Job::Init(GameManager *managerOut) {
	gameSettings = managerOut->gameSettings;
	gameState = managerOut->gameState;
}

void Job::Work(double time) {
	std::cout << "Work done";
}

void WoodCutterJob::Work(double time) {
	gameState->wood += gameSettings->woodRate * time;
}

void StoneMinerJob::Work(double time) {
	gameState->stone += gameSettings->stoneRate * time;
}

void GoldMinerJob::Work(double time) {
	gameState->goldOre += gameSettings->goldRate * time;
}

void CarpenterJob::Work(double time) {
	if (gameState->wood > gameSettings->plankInRate * time) {
		gameState->wood -= gameSettings->plankInRate * time;
		gameState->planks += gameSettings->plankOutRate * time;
	}
}

void BuilderJob::Work(double time) {
	if (gameState->wood > gameSettings->houseInWoodRate * time
		&& gameState->stone > gameSettings->houseInStoneRate * time) {
		gameState->wood -= gameSettings->houseInWoodRate * time;
		gameState->stone -= gameSettings->houseInStoneRate * time;
		gameState->houses += gameSettings->houseOutRate * time;
	}
}

void SmelterJob::Work(double time) {
	if (gameState->wood > gameSettings->coinsInWoodRate * time
		&& gameState->stone > gameSettings->coinsInGoldOreRate * time) {
		gameState->wood -= gameSettings->coinsInWoodRate * time;
		gameState->goldOre -= gameSettings->coinsInGoldOreRate * time;
		gameState->coins += gameSettings->coinsOutRate * time;
	}
}
