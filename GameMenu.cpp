#include "GameMenu.h"

GameMenu *GameMenu::m_gameMenu = nullptr;

GameMenu::GameMenu() {
	m_currIndex = 1;
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
	std::ifstream title;
	title.open("ui/title.ui", std::ios::in);
	if (title.is_open())
		std::cout << title.rdbuf() << std::endl;
	
	std::ifstream menu;
	std::string menuUrl = "ui/" + m_menus.at(menuIndex).at(0) + ".ui";
	menu.open(menuUrl, std::ios::in);
	if (menu.is_open())
		std::cout << menu.rdbuf() << std::endl;
	std::cout << "\n";

	for (int i = 1; i < m_menus.at(menuIndex).size(); i++) {
		std::cout << "\t\t\t";
		i == m_currIndex ? std::cout << DEF_SELECT_CHAR << " " : std::cout << "  ";
		std::cout << m_menus.at(menuIndex).at(i) << std::endl;
	}
	title.close();
	menu.close();
	selectAction(menuIndex);
}

void GameMenu::startNewGame(int nbrOfPlayers) {
	GameManager::getInstance()->initNewGame(m_numberOfPlayers);

}

void GameMenu::selectAction(int menuIndex)
{
	char key_press;
	int ascii_value;
	while (1)
	{
		key_press = _getch();
		ascii_value = key_press;
		int maxIndex = m_menus.at(menuIndex).size() - 1;
		if (ascii_value == 80) {
			m_currIndex++;
			if (m_currIndex > maxIndex) {
				m_currIndex = 1;
			}
			drawMenu(menuIndex);
			break;
		}
		else if (ascii_value == 72) {
			m_currIndex--;
			if (m_currIndex < 1) {
				m_currIndex = maxIndex;
			}
			drawMenu(menuIndex);
			break;
		}
		else if (ascii_value == 13) {
			menuSelected(menuIndex, m_currIndex);
			break;
		}
	}
}

void GameMenu::menuSelected(int menuIndex, int index) {

	m_index = index;

	if (m_index < m_menus.at(menuIndex).size() && m_index > 0) {
		switch (menuIndex) {
		case DEF_MAIN_MENU:
			m_index == 1 ? drawMenu(DEF_HOW_MANY) : drawMenu(DEF_EXIT_CONFIRM);
			break;
		case DEF_EXIT_CONFIRM:
			m_index == 1 ? exit(EXIT_SUCCESS) : drawMenu(DEF_MAIN_MENU);
			break;
		case DEF_HOW_MANY:
			switch (m_index)
			{
			case 1:
				startNewGame(2);
				break;
			case 2:
				startNewGame(3);
				break;
			case 3:
				startNewGame(4);
				break;
			case 4:
				drawMenu(DEF_MAIN_MENU);
				break;
			}
		}
	}
	else {
		std::cout << "Unkonwn Menu, returning to Main Menu.\n";
		drawMenu(DEF_MAIN_MENU);
	}
}

