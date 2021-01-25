#pragma once
#ifndef DEF_GAMEMANAGER
#define DEF_GAMEMANAGER

#include "Character.h"
#include "GameObject.h"

class GameManager : public GameObject
{
	public:
		static GameManager *getInstance();
		~GameManager();

		void initGame();

	private:
		static GameManager *m_gameManager;
		GameManager();
};
#endif