#pragma once
#ifndef DEF_GAMEMANAGER
#define DEF_GAMEMANAGER

#include "Character.h"
#include "GameObject.h"
#include "Sword.h"
#include "Chief.h"
#include "Warrior.h"
#include "GameMenu.h"

#include <chrono>
#include <thread>

class GameManager : public GameObject
{
	public:
		static GameManager *getInstance();
		~GameManager();

		void initGame();
		void goToMainMenu();

	private:
		static GameManager *m_gameManager;
		GameManager();
		Character* m_char_1 = nullptr;
		Character* m_char_2 = nullptr;
};
#endif