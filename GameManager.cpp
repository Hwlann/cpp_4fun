#include "GameManager.h"
GameManager *GameManager::m_gameManager = nullptr;

GameManager::GameManager() {

}

GameManager::~GameManager() {

}

void GameManager::initGame()
{
	GameInstance::getInstance();
}

void GameManager::goToMainMenu()
{
	GameMenu::getInstance()->init();
}

GameManager *GameManager::getInstance() {
	if (m_gameManager == nullptr) {
		m_gameManager = new GameManager();
	}
	return m_gameManager;
}