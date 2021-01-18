#include "GameMenu.h"

GameMenu *GameMenu::m_gameMenu = nullptr;

GameMenu::GameMenu() {
	drawMenu(DEF_MAIN_MENU);
}

GameMenu::~GameMenu() {
	if(m_gameMenu != nullptr) delete m_gameMenu;
}

GameMenu *GameMenu::getInstance() {
	if (m_gameMenu == nullptr) {
		m_gameMenu = new GameMenu;
	}
	return m_gameMenu;
}

void GameMenu::drawMenu(int menuIndex) {
	system("cls");
	for (int i = 0; i < m_menus.at(menuIndex).size(); i++) {
		i == 0 ? std::cout << " > " : std::cout << i << " - ";
		std::cout << m_menus.at(menuIndex).at(i) << std::endl;
	}

	std::cout << "Action : ";
	std::cin >> m_choice;
	m_index = std::stoi(m_choice);

	if (m_index < m_menus.at(menuIndex).size() && m_index > 0) {
		switch (menuIndex) {
		case DEF_MAIN_MENU:
			m_index == 1 ? startNewGame() : drawMenu(DEF_EXIT_CONFIRM);
			break;
		case DEF_EXIT_CONFIRM:
			m_index == 1 ? exit(EXIT_SUCCESS) : drawMenu(DEF_MAIN_MENU);
			break;
		}
	}
	else {
		std::cout << "Unkonwn Menu, returning to Main Menu.\n";
		drawMenu(DEF_MAIN_MENU);
	}
}

void GameMenu::startNewGame() {
	std::cout << std::endl << "Enter the number of players : ";
	std::cin >> m_numberOfPlayers;
	if (m_numberOfPlayers < 2) {
		std::cout << "\nAt least 2 players are needed !\n";
		startNewGame();
	}
	GameManager::getInstance()->initNewGame(m_numberOfPlayers);

}

