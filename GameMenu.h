#pragma once
#ifndef DEF_GAMEMENU
#define DEF_GAMEMENU

#define DEF_MAIN_MENU		0
#define DEF_EXIT_CONFIRM	1
#define DEF_NEW_GAME		2

#include "GameManager.h"


class GameMenu
{
	public:
		~GameMenu();
		static GameMenu* getInstance();
		void drawMenu(int menuIndex);
		std::string m_choice;
		int m_index;
		int m_numberOfPlayers;

	private:
		GameMenu();
		void startNewGame();
		static GameMenu* m_gameMenu;
		std::vector<std::vector<std::string>> m_menus = { {"Main Menu", "New Game", "Exit"},
														{"Sure ?", "Yes", "No"}};
};

#endif