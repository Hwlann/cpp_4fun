#include "GameManager.h"
GameManager *GameManager::m_gameManager = nullptr;

GameManager::GameManager() {

}

GameManager::~GameManager() {

}

void GameManager::initGame()
{
	std::cout << "WORK IN PROGRESS AHAHAHAH" << std::endl;
	exit(EXIT_SUCCESS);
}

GameManager *GameManager::getInstance() {
	if (m_gameManager == nullptr) {
		m_gameManager = new GameManager();
	}
	return m_gameManager;
}