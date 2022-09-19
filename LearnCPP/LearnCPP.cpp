#include <iostream>
#include <string>
#include "Player.h"
#include "GameManager.h"

int main()
{
	GameManager gameManager;
	gameManager.Init();

	for (int i = 0; i < 100; i++) {
		gameManager.Update(1);
	}

	std::cout << gameManager.gameState->stone;
}
