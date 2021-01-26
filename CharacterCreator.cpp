#include "CharacterCreator.h"

CharacterCreator* CharacterCreator::m_instance = nullptr;

CharacterCreator::CharacterCreator(std::string name) : GameObject(name)
{
	myWonderfullMap.insert(std::pair<std::string, std::string*>("m_characterName", &m_characterName));

	myMarvelousMap.insert(std::pair<std::string, int*>("m_currSkillsAmount", &m_currSkillsAmount));
	myMarvelousMap.insert(std::pair<std::string, int*>("m_currStrength", &m_currStrength));
	myMarvelousMap.insert(std::pair<std::string, int*>("m_currDexterity", &m_currDexterity));
	myMarvelousMap.insert(std::pair<std::string, int*>("m_currIntelligence", &m_currIntelligence));
}

CharacterCreator* CharacterCreator::Instance()
{
	if (m_instance == nullptr)
	{
		m_instance = new CharacterCreator("CharacterCreator");
	}

	return m_instance;
}

void CharacterCreator::drawCharacterSetup()
{
	std::ifstream title;
	title.open("ui/character-creator.ui", std::ios::in);
	if (title.is_open())
		std::cout << title.rdbuf() << std::endl;

	std::cout << "\n\n";

	std::cout << "\t\t Select your name :" << std::endl << std::endl;
	std::cout << "\t\t" << ((m_vIndex == 1) ? "> " : "  ") << Utility::printT(m_creatorMenus.at(m_menuIndex).at(1), myWonderfullMap) << std::endl << std::endl;


	std::cout << "\t\t Select your class :" << std::endl << std::endl;
	std::cout << "\t\t" << ((m_vIndex == 2) ? "> " : "  ") << "<    " << getClassNameFromEnum() << "    >" << std::endl << std::endl;

	std::cout << "\t\t" << ((m_vIndex == 3) ? "> " : "  ") << Utility::printT(m_creatorMenus.at(m_menuIndex).at(3), myWonderfullMap) << std::endl;
	std::cout << "\t\t" << ((m_vIndex == 4) ? "> " : "  ") << Utility::printT(m_creatorMenus.at(m_menuIndex).at(4), myWonderfullMap) << std::endl << std::endl;

	selectAction(m_menuIndex);
}

void CharacterCreator::drawCharacterRace()
{
	std::ifstream title;
	title.open("ui/character-creator.ui", std::ios::in);
	if (title.is_open())
		std::cout << title.rdbuf() << std::endl;

	std::cout << "\n\n";

	std::cout << "\t\t Select your face :" << std::endl << std::endl;
	std::cout << "\t\t" << ((m_vIndex == 1) ? "> " : "  ") << "<    " << getRaceNameFromEnum() << "    >" << std::endl << std::endl;

	std::cout << "\t\t" << ((m_vIndex == 2) ? "> " : "  ") << Utility::printT(m_creatorMenus.at(m_menuIndex).at(2), myWonderfullMap) << std::endl;
	std::cout << "\t\t" << ((m_vIndex == 3) ? "> " : "  ") << Utility::printT(m_creatorMenus.at(m_menuIndex).at(3), myWonderfullMap) << std::endl << std::endl;

	std::ifstream portrait;
	portrait.open("portraits/" + getRaceNameFromEnum() + ".race", std::ios::in);
	if (portrait.is_open())
		std::cout << portrait.rdbuf() << std::endl;
	else std::cout << "portraits/" + getRaceNameFromEnum() + ".race";

	selectAction(m_menuIndex);
}

void CharacterCreator::drawCharacterSkills()
{
	std::ifstream title;
	title.open("ui/character-creator.ui", std::ios::in);
	if (title.is_open())
		std::cout << title.rdbuf() << std::endl;

	for (int i = 1; i < m_creatorMenus.at(m_menuIndex).size(); i++) {
		std::cout << "\t\t\t";
		(i == m_vIndex) ? std::cout << DEF_SELECT_CHAR << " " : std::cout << "  ";
		std::cout << Utility::printT(m_creatorMenus.at(m_menuIndex).at(i), myMarvelousMap) << std::endl;
	}
	selectAction(m_menuIndex);
}

std::string CharacterCreator::getClassNameFromEnum()
{
	switch (m_characterClass)
	{
		case UnitClass::WARRIOR:
			return "Warrior";
		case UnitClass::RANGER:
			return "Ranger"; 
		case UnitClass::WIZARD:
			return "Wizard";
		default:
			return std::string();
	}
}

std::string CharacterCreator::getRaceNameFromEnum()
{
	switch (m_characterRace)
	{
	case UnitRace::HUMAN:
		return "Human";
	case UnitRace::ORC:
		return "Orc";
	case UnitRace::ELVEN:
		return "Elven";
	default:
		return std::string();
	}
}

CharacterCreator::~CharacterCreator()
{
}

void CharacterCreator::selectAction(int menuIndex)
{
	char key_press;
	int ascii_value;
	while (1)
	{
		key_press = _getch();
		ascii_value = key_press;

		int maxIndex = m_creatorMenus.at(m_menuIndex).size() - 1;

		if (menuIndex == DEF_SETUPMENU)
		{
			if (m_vIndex == 1 && ascii_value > 47 && ascii_value < 58 || ascii_value > 96 && ascii_value < 123 || ascii_value == 32) {
				m_characterName += ascii_value;
				drawMenu(menuIndex);
			}
			if (ascii_value == 8 && m_vIndex == 1)
			{
				if(m_characterName.size() > 0) m_characterName = m_characterName.substr(0, m_characterName.size() - 1);
				drawMenu(menuIndex);
			}
			if (ascii_value == 75 && m_vIndex == 2)
			{
				if (m_characterClass == UnitClass::WARRIOR) m_characterClass = UnitClass::RANGER;
				else if (m_characterClass == UnitClass::RANGER) m_characterClass = UnitClass::WIZARD;
				else if (m_characterClass == UnitClass::WIZARD) m_characterClass = UnitClass::WARRIOR;

				drawMenu(menuIndex);
				break;
			}
			if (ascii_value == 77 && m_vIndex == 2)
			{
				if (m_characterClass == UnitClass::WARRIOR) m_characterClass = UnitClass::WIZARD;
				else if (m_characterClass == UnitClass::RANGER) m_characterClass = UnitClass::WARRIOR;
				else if (m_characterClass == UnitClass::WIZARD) m_characterClass = UnitClass::RANGER;

				drawMenu(menuIndex);
				break;
			}
		}

		if (menuIndex == DEF_RACEMENU)
		{
			if (ascii_value == 75 && m_vIndex == 1)
			{
				if (m_characterRace == UnitRace::HUMAN) m_characterRace = UnitRace::ORC;
				else if (m_characterRace == UnitRace::ORC) m_characterRace = UnitRace::ELVEN;
				else if (m_characterRace == UnitRace::ELVEN) m_characterRace = UnitRace::HUMAN;

				drawMenu(menuIndex);
				break;
			}
			if (ascii_value == 77 && m_vIndex == 1)
			{
				if (m_characterRace == UnitRace::HUMAN) m_characterRace = UnitRace::ORC;
				else if (m_characterRace == UnitRace::ELVEN) m_characterRace = UnitRace::HUMAN;
				else if (m_characterRace == UnitRace::ORC) m_characterRace = UnitRace::ELVEN;

				drawMenu(menuIndex);
				break;
			}
		}

		if (ascii_value == 80)
		{
			m_vIndex++;
			if (m_vIndex > maxIndex) {
				m_vIndex = 1;
			}

			drawMenu(menuIndex);
			break;
		}
		else if (ascii_value == 72)
		{
			m_vIndex--;
			if (m_vIndex < 1) {
				m_vIndex = maxIndex;
			}

			drawMenu(menuIndex);
			break;
		}
		else if (ascii_value == 13) {

			menuSelected(menuIndex, m_vIndex);
			break;
		}
	}
}

void CharacterCreator::drawMenu(int menuIndex)
{

	system("cls");
	m_menuIndex = menuIndex;
	switch (menuIndex)
	{
		case DEF_SETUPMENU:
				drawCharacterSetup();
			break;
		case DEF_RACEMENU:
				drawCharacterRace();
			break;
		case DEF_SKILLSMENU:
				drawCharacterSkills();
			break;
	}
}

void CharacterCreator::generatePlayer()
{
	std::string myText;

	characterFile.open("player.cnf");

	while (std::getline(characterFile, myText)) {
		std::cout << myText;
	}
}

void CharacterCreator::menuSelected(int menuIndex, int index)
{
	m_vIndex = index;

	if (m_vIndex < m_creatorMenus.at(m_menuIndex).at(menuIndex).size() && m_vIndex > 0) {
		switch (menuIndex) {
			case DEF_SETUPMENU:
				switch (m_vIndex)
				{
				case 1:
					drawCharacterSetup();
					break;

				case 2:
					drawCharacterSetup();
					break;

				case 3:
					m_vIndex = 1;
					Utility::writeToFile("player.cnf", 0, std::string("Name : " + m_characterName + "\n"));
					Utility::writeToFile("player.cnf", 1, std::string("Class : " + getClassNameFromEnum() + "\n"));
					drawMenu(DEF_RACEMENU);
					return;
					break;

				case 4:
					m_vIndex = 1;
					GameManager::getInstance()->goToMainMenu();
					break;
				}
				break;
			case DEF_RACEMENU:
				switch (m_vIndex)
				{
				case 1:
					m_vIndex++;
					break;
				case 2:
					m_vIndex = 1;
					Utility::writeToFile("player.cnf", 2, std::string("Race : " + getRaceNameFromEnum() + "\n"));
					drawMenu(DEF_SKILLSMENU);
					return;
					break;
				case 3:
					drawMenu(DEF_SETUPMENU);
					break;
				}
				break;
			case DEF_SKILLSMENU:
				switch (m_vIndex)
				{
				case 1:
					break;
				case 2:
					
					break;
				case 3:
					break;
				}
				break;
			}
	}
}