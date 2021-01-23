#include "GameManager.h"
GameManager *GameManager::m_gameManager = nullptr;

GameManager::GameManager() {

}

GameManager::~GameManager() {

}

GameManager *GameManager::getInstance() {
	if (m_gameManager == nullptr) {
		m_gameManager = new GameManager();
	}
	return m_gameManager;
}