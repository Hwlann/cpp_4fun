#pragma once
#ifndef DEF_GAMEMANAGER
#define DEF_GAMEMANAGER

#include "Character.h"
#include <time.h>

class GameManager
{
	public:
		static GameManager *getInstance();
		void initNewGame(int numberOfPlayers);
		void StartGame();
		void gameEnds(std::string winnerName);
		void addNewPlayerCharacter(std::string characterName, int classIndex);
		void drawGrid();
		void newTurn();
		void characterTurn(Character* Character);
		void checkGameState();
		Character::CharacterPosition* findPosition();
		~GameManager();

	private:
		static GameManager *m_gameManager;
		GameManager();
		void chooseClassAndWeapon(std::string playerName);
		std::map<std::string, Character *> m_characterList;
		std::vector<std::string> m_playersNames;
		std::string m_playersName;
		bool keepPlaying = true;
		int currentPlayer;
		std::vector<std::string> m_classNames = { "Warrior", "Wizard", "Ranger" };
		int classIndex = 0;
		int m_numberOfTurn = 0;
		int m_turnChoise;
		int gridSize = 10;
		std::vector<std::vector<int>> m_grid = {{0,0,0,0,0,0,0,0,0,0},
												{0,0,0,0,0,0,0,0,0,0}, 
												{0,0,0,0,0,0,0,0,0,0}, 
												{0,0,0,0,0,0,0,0,0,0},
												{0,0,0,0,0,0,0,0,0,0},
												{0,0,0,0,0,0,0,0,0,0}, 
												{0,0,0,0,0,0,0,0,0,0},
												{0,0,0,0,0,0,0,0,0,0},
												{0,0,0,0,0,0,0,0,0,0},
												{0,0,0,0,0,0,0,0,0,0}};
};
#endif