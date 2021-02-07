#pragma once
#ifndef DEF_GAMEMANAGER
#define DEF_GAMEMANAGER

#include "GameInstance.h"
#include "GameMenu.h"

#include <chrono>
#include <thread>

class GameManager : public GameObject
{
	public:
		static GameManager *getInstance();
		virtual ~GameManager();

		void initGame();
		void goToMainMenu();

	private:
		static GameManager *m_gameManager;
		GameManager();
};
#endif