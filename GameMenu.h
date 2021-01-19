#pragma once
#ifndef DEF_GAMEMENU
#define DEF_GAMEMENU

#define DEF_MAIN_MENU		0
#define DEF_EXIT_CONFIRM	1
#define DEF_HOW_MANY		2

#define DEF_SELECT_CHAR		"»"

#include "GameManager.h"
#include <iostream>
#include <fstream>
#include<conio.h>


class GameMenu
{
	public:
		~GameMenu();
		static GameMenu* getInstance();
		void drawMenu(int menuIndex);
		void menuSelected(int menuIndex, int index);
		void selectAction(int menuIndex);
		void startNewGame(int nbrOfPlayers);

	private:
		std::string m_choice;
		int m_index;
		int m_numberOfPlayers;
		int m_currIndex;
		static GameMenu* m_gameMenu;
		std::vector<std::vector<std::string>> m_menus = { 
															{ "mainmenu", "New Game", "Exit" },
															{ "sure", "Yes", "No" },
															{ "selectplayers", "2 players", "3 players", "4 players", "Back" }
														};
		GameMenu();
};

#endif