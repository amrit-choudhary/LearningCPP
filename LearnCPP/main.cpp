#include <iostream>
#include <string>
#include "Player.h"
#include "GameManager.h"
#include <Windows.h>
#include <chrono>

void clear_screen(char fill = ' ') {
    COORD tl = { 0,0 };
    CONSOLE_SCREEN_BUFFER_INFO s;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(console, &s);
    DWORD written, cells = s.dwSize.X * s.dwSize.Y;
    FillConsoleOutputCharacter(console, fill, cells, tl, &written);
    FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
    SetConsoleCursorPosition(console, tl);
}

int main()
{
	GameManager gameManager;
	gameManager.Init();

	/*for (int i = 0; i < 10000; i++) {
        clear_screen();
		gameManager.Update(0.5);
		std::cout << gameManager.Print();
		SleepEx(500, false);
	}*/

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 100; i++) {
        gameManager.Update(1.0);
    }

    auto stop = std::chrono::high_resolution_clock::now();

    gameManager.Print();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << duration.count() / 100;
}
