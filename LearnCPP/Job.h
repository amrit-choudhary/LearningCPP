#pragma once
#include "GameSettings.h"
#include "GameState.h"

enum JobType {
	None = 0,
	WoodCutter = 1,
	StoneMiner = 2,
	GoldMiner = 3,
	Carpenter = 4,
	Builder = 5,
	Smelter = 6,
};

class GameManager;

class Job {
private:
	int i;
public:
	void Init(GameManager *managerPtr);
	GameSettings* gameSettings;
	GameState* gameState;
	virtual void Work(double time);
};

class WoodCutterJob : public Job {
public:
	void Work(double time);
};

class StoneMinerJob : public Job {
public:
	void Work(double time);
};

class GoldMinerJob : public Job {
public:
	void Work(double time);
};

class CarpenterJob : public Job {
public:
	void Work(double time);
};

class BuilderJob : public Job {
public:
	void Work(double time);
};

class SmelterJob : public Job {
public:
	void Work(double time);
};


