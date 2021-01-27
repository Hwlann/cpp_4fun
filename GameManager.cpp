#include "GameManager.h"
GameManager *GameManager::m_gameManager = nullptr;

GameManager::GameManager() {

}

GameManager::~GameManager() {

}

void GameManager::initGame()
{
	m_char_1 = new Character();
	m_char_1->setName("Jacquie");
	m_char_2 = new Character();
	m_char_2->setName("Michou");

	m_char_1->setClass(new Warrior);
	m_char_2->setClass(new Warrior);

	m_char_1->setDualHandWeapon(new Sword(true));

	m_char_2->setRightHandWeapon(new Sword(false));
	m_char_2->setLeftHandWeapon(new Sword(false));

	m_char_1->attackTarget(m_char_1, m_char_2, m_char_1->getWeapon()->getMainSkill());

	m_char_2->attackTarget(m_char_2, m_char_1, m_char_2->getWeapon()->getMainSkill());
	m_char_2->attackTarget(m_char_2, m_char_1, dynamic_cast<OneHand *>(m_char_2->getWeapon())->getOffHandSkill());
	
	//Chief<Warrior> m_char_3(std::vector<Warrior>(m_char_1, m_char_2));
	Chief<Warrior> *m_char_3 = new Chief<Warrior>();
	m_char_3->setName("Chuck");
	m_char_3->setDualHandWeapon(new Sword(true));
	m_char_3->attackTarget(m_char_3, m_char_1 , m_char_3->getWeapon()->getMainSkill());

	std::this_thread::sleep_for(std::chrono::milliseconds((int)(10 * 1e3)));

	/*
	std::cout << "WORK IN PROGRESS IHIHIHIHIHIH" << std::endl;
	exit(EXIT_SUCCESS);
	*/
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