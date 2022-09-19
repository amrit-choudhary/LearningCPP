#include <iostream>
#include <string>
#include "GameManager.h"
#include "Job.h"

void GameManager::Init() {
	gameSettings = new GameSettings();
	gameState = new GameState();
	playerCount = 1000000;

	for (int i = 0; i < playerCount; i++) {
		WoodCutterJob* miner = new WoodCutterJob();
		miner->Init(this);
		jobs.push_back(miner);
	}

	for (int i = 0; i < playerCount; i++) {
		StoneMinerJob* miner = new StoneMinerJob();
		miner->Init(this);
		jobs.push_back(miner);
	}

	for (int i = 0; i < playerCount; i++) {
		GoldMinerJob* miner = new GoldMinerJob();
		miner->Init(this);
		jobs.push_back(miner);
	}

	for (int i = 0; i < playerCount; i++) {
		CarpenterJob* miner = new CarpenterJob();
		miner->Init(this);
		jobs.push_back(miner);
	}

	for (int i = 0; i < playerCount; i++) {
		BuilderJob* miner = new BuilderJob();
		miner->Init(this);
		jobs.push_back(miner);
	}

	for (int i = 0; i < playerCount; i++) {
		SmelterJob* miner = new SmelterJob();
		miner->Init(this);
		jobs.push_back(miner);
	}
}

void GameManager::Update(double time) {
	for (int i = 0; i < jobs.size(); i++) {
		jobs.at(i)->Work(time);
	}
}

std::string GameManager::Print() {
	std::cout << "Wo: ";
	std::cout << static_cast<int>(gameState->wood);
	std::cout << " St: ";
	std::cout << static_cast<int>(gameState->stone);
	std::cout << " Go: ";
	std::cout << static_cast<int>(gameState->goldOre);
	std::cout << " Pl: ";
	std::cout << static_cast<int>(gameState->planks);
	std::cout << " Ho: ";
	std::cout << static_cast<int>(gameState->houses);
	std::cout << " Co: ";
	std::cout << static_cast<int>(gameState->coins);
	std::cout << std::endl;

	return "";
}

