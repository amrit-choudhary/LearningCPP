#pragma once
class GameSettings
{
public:
	double woodRate{};
	double stoneRate{};
	double goldRate{};
	double plankInRate{};
	double plankOutRate{};
	double houseInWoodRate{};
	double houseInStoneRate{};
	double houseOutRate{};
	double coinsInWoodRate{};
	double coinsInGoldOreRate{};
	double coinsOutRate{};

	GameSettings();
};
