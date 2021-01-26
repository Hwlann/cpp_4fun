#include "GameMenu.h"
#include "CharacterCreator.h"

GameMenu *GameMenu::m_gameMenu = nullptr;

GameMenu::GameMenu() {
	m_currIndex = 1;
	m_numberOfPlayers = DEF_MIN_PLAYERS_COUNT;
	m_gameDifficulty = 3;

	myWonderfullMap.insert(std::pair<std::string, int*>("m_numberOfPlayers", &m_numberOfPlayers));
	myWonderfullMap.insert(std::pair<std::string, int*>("m_gameDifficulty", &m_gameDifficulty));

	loadingScreen();
}

GameMenu::~GameMenu() {
	if(m_gameMenu != nullptr) delete m_gameMenu;
}

void GameMenu::loadingScreen() {
	system("cls");

	std::ifstream loading;
	loading.open("ui/loading.ui", std::ios::in);
	if (loading.is_open())
		std::cout << loading.rdbuf() << std::endl;

	for (int i = 100; i < 300; i += 10) {
		Beep(i, 100);
	}
	drawMenu(DEF_MAIN_MENU);
}

GameMenu *GameMenu::getInstance() {
	if (m_gameMenu == nullptr) {
		m_gameMenu = new GameMenu;
	}
	return m_gameMenu;
}

void GameMenu::init()
{
	drawMenu(DEF_MAIN_MENU);
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
		(i == m_currIndex) ? std::cout << DEF_SELECT_CHAR << " " : std::cout << "  ";
		std::cout << Utility::printT(m_menus.at(menuIndex).at(i), myWonderfullMap) << std::endl;
	}
	title.close();
	menu.close();
	selectAction(menuIndex);
}

void GameMenu::startNewGame(int nbrOfPlayers) {
	//GameManager::getInstance()->initNewGame(m_numberOfPlayers);

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

		if (menuIndex == DEF_OPTIONS)
		{
			if (ascii_value == 75 && m_currIndex == 1)
			{
				Beep(433 + 80 * m_gameDifficulty, 80);
				m_gameDifficulty--;
				Utility::clamp(&m_gameDifficulty, DEF_MIN_DIFFICULTY, DEF_MAX_DIFFICULTY);
				drawMenu(menuIndex);
				break;
			}
			if (ascii_value == 77 && m_currIndex == 1)
			{
				Beep(433 + 80 * m_gameDifficulty, 80);
				m_gameDifficulty++;
				Utility::clamp(&m_gameDifficulty, DEF_MIN_DIFFICULTY, DEF_MAX_DIFFICULTY);
				drawMenu(menuIndex);
				break;
			}
		}
		if (ascii_value == 80) 
		{
			m_currIndex++;
			if (m_currIndex > maxIndex) {
				m_currIndex = 1;
			}

			Beep(523, 80);
			drawMenu(menuIndex);
			break;
		}
		else if (ascii_value == 72) 
		{
			m_currIndex--;
			if (m_currIndex < 1) {
				m_currIndex = maxIndex;
			}

			Beep(523, 80);
			drawMenu(menuIndex);
			break;
		}
		else if (ascii_value == 13) {

			Beep(523, 40);
			Beep(750, 120);
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
			switch (m_index)
			{
			case 1:
				m_currIndex = 1;
				drawMenu(DEF_HOW_MANY);
				break;
			case 2:
				m_currIndex = 1;
				drawMenu(DEF_OPTIONS);
				break;
			case 3:
				m_currIndex = 1;
				drawMenu(DEF_EXIT_CONFIRM);
				break;
			}
			break;
		case DEF_EXIT_CONFIRM:
			(m_index == 1) ? exit(EXIT_SUCCESS) : drawMenu(DEF_MAIN_MENU);
			break;
		case DEF_HOW_MANY:
			switch (m_index)
			{
			case 1:
				CharacterCreator::Instance()->drawMenu(0);
				break;
			case 2:
				GameManager::getInstance()->initGame();
			case 3:
				drawMenu(DEF_MAIN_MENU);
				break;
			}
			break;
		case DEF_OPTIONS:
			switch (m_index)
			{
			case 1:
				m_currIndex++;
				drawMenu(DEF_OPTIONS);
				break;
			case 2:
				m_currIndex = 1;
				applyOptions();
				drawMenu(DEF_MAIN_MENU);
				break;
			case 3:
				m_currIndex = 1;
				drawMenu(DEF_MAIN_MENU);
				break;
			}
			break;
		}
	}
	else {
		std::cout << "Unkonwn Menu, returning to Main Menu.\n";
		drawMenu(DEF_MAIN_MENU);
	}
}

void GameMenu::applyOptions() 
{
	std::fstream optionsFile;
	optionsFile.open("game.settings");
}
