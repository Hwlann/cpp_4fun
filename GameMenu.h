#pragma once
#ifndef DEF_GAMEMENU
#define DEF_GAMEMENU

#define DEF_MAIN_MENU		0
#define DEF_EXIT_CONFIRM	1
#define DEF_HOW_MANY		2
#define DEF_OPTIONS			3

#define DEF_MIN_PLAYERS_COUNT 2
#define DEF_MAX_PLAYERS_COUNT 10

#define DEF_SELECT_CHAR		">"

#include "GameManager.h"
#include "Utility.h"

#include <iostream>
#include <fstream>
#include <conio.h>

enum class GameDifficulty {
	EASY,
	MEDIUM,
	HARD
};

class GameMenu
{
	public:
		~GameMenu();
		static GameMenu* getInstance();
		void drawMenu(int menuIndex);
		void menuSelected(int menuIndex, int index);
		void selectAction(int menuIndex);
		void startNewGame(int nbrOfPlayers);
		void applyOptions();

	private:
		std::string m_choice;
		int m_index;
		int m_numberOfPlayers;
		int m_currIndex;
		static GameMenu* m_gameMenu;
		std::vector<std::vector<std::string>> m_menus = { 
															{ "mainmenu", "New Game", "Options", "Exit" },
															{ "sure", "Yes", "No" },
															{ "selectplayers", "{ nbPlayers } players", "Back" },
															{ "options", "Difficuly : { difficulty }", "Apply", "Back" }
														};
		GameMenu();
};

#endif