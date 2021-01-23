#pragma once
#ifndef DEF_GAMEMENU
#define DEF_GAMEMENU

#define DEF_MAIN_MENU		0
#define DEF_EXIT_CONFIRM	1
#define DEF_HOW_MANY		2
#define DEF_OPTIONS			3

#define DEF_MIN_PLAYERS_COUNT 2
#define DEF_MAX_PLAYERS_COUNT 10

#define DEF_MIN_DIFFICULTY 0
#define DEF_MAX_DIFFICULTY 5

#define DEF_SELECT_CHAR		">"

#define NOTE_E 578
#define NOTE_Ds 542
#define NOTE_B 493
#define NOTE_D 294
#define NOTE_C 262
#define NOTE_A 440

#define B3 245 // SI
#define C4 262 // DO
#define Cs4 277 // DO#
#define Db4 277 // REb
#define D4 294 // RE
#define Ds4 311 // RE#
#define Eb4 311 // MIb
#define E4 330 // MI
#define F4 349 // FA
#define Fs4 370 // FA#
#define Gb4 370 // SOLb
#define G4 392 // SOL
#define Gs4 415 // SOL#
#define Ab4 415 // LAb
#define A4 440 // LA
#define As4 466 // LA#
#define Bb4 466 // SIb
#define B4 493 // SI
#define C5 523 // DO

#include "GameManager.h"
#include "GameObject.h"
#include "Utility"

#include <iostream>
#include <fstream>
#include <conio.h>
#include <map>
#include <windows.h>

enum class GameDifficulty {
	EASY,
	MEDIUM,
	HARD
};

class GameMenu : public GameObject
{
	public:
		~GameMenu();
		static GameMenu* getInstance();
		void drawMenu(int menuIndex);
		void menuSelected(int menuIndex, int index);
		void selectAction(int menuIndex);
		void startNewGame(int nbrOfPlayers);
		void applyOptions();
		void loadingScreen();

	private:
		std::string m_choice;
		int m_index;
		int m_numberOfPlayers;
		int m_currIndex;

		std::map<std::string, int*> myWonderfullMap;

		int m_gameDifficulty;

		static GameMenu* m_gameMenu;

		std::vector<std::vector<std::string>> m_menus = { 
															{ "mainmenu", "New Game", "Options", "Exit" },
															{ "sure", "Yes", "Back" },
															{ "selectplayers", "<    {{ $m_numberOfPlayers }} players     >", "Back" },
															{ "options", "<    Difficuly : {{ $m_gameDifficulty }}     >", "Apply", "Back" }
														};
		GameMenu();
};

#endif

