#include "CharacterCreator.h"

CharacterCreator* CharacterCreator::m_instance = nullptr;

CharacterCreator::CharacterCreator(std::string name) : GameObject(name)
{
	myWonderfullMap.insert(std::pair<std::string, std::string*>("m_characterName", &m_characterName));
	myWonderfullMap.insert(std::pair<std::string, std::string*>("getClassNameFromEnum", &getCharClass));
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
	m_menuIndex = DEF_SETUPMENU;
	system("cls");

	std::ifstream title;
	title.open("ui/character-creator.ui", std::ios::in);
	if (title.is_open())
		std::cout << title.rdbuf() << std::endl;

	std::cout << "\n\n";

	std::cout << "\t\t Select your name :" << std::endl << std::endl;
	std::cout << "\t\t" << ((m_currIndex == 1) ? "> " : "  ") << Utility::printT(m_setupMenu.at(1), myWonderfullMap) << std::endl << std::endl;


	std::cout << "\t\t Select your class :" << std::endl << std::endl;
	std::cout << "\t\t" << ((m_currIndex == 2) ? "> " : "  ") << "<    " << getClassNameFromEnum() << "    >" << std::endl << std::endl;

	std::cout << "\t\t" << ((m_currIndex == 3) ? "> " : "  ") << Utility::printT(m_setupMenu.at(3), myWonderfullMap) << std::endl;
	std::cout << "\t\t" << ((m_currIndex == 4) ? "> " : "  ") << Utility::printT(m_setupMenu.at(4), myWonderfullMap) << std::endl << std::endl;

	selectAction(m_menuIndex);
}

void CharacterCreator::drawCharacterRace()
{
	m_menuIndex = DEF_RACEMENU;

	system("cls");

	std::cout << "race" << std::endl;
}

void CharacterCreator::drawCharacterSkills()
{
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

		int maxIndex = m_setupMenu.size() - 1;

		if (menuIndex == DEF_SETUPMENU)
		{
			if (m_currIndex == 1 && ascii_value > 47 && ascii_value < 58 || ascii_value > 96 && ascii_value < 123 || ascii_value == 32) {
				m_characterName += ascii_value;
				drawMenu(menuIndex);
			}
			if (ascii_value == 8 && m_currIndex == 1)
			{
				if(m_characterName.size() > 0) m_characterName = m_characterName.substr(0, m_characterName.size() - 1);
				drawMenu(menuIndex);
			}
			if (ascii_value == 75 && m_currIndex == 2)
			{
				if (m_characterClass == UnitClass::WARRIOR) m_characterClass = UnitClass::RANGER;
				else if (m_characterClass == UnitClass::RANGER) m_characterClass = UnitClass::WIZARD;
				else if (m_characterClass == UnitClass::WIZARD) m_characterClass = UnitClass::WARRIOR;

				drawMenu(menuIndex);
				break;
			}
			if (ascii_value == 77 && m_currIndex == 2)
			{
				if (m_characterClass == UnitClass::WARRIOR) m_characterClass = UnitClass::WIZARD;
				else if (m_characterClass == UnitClass::RANGER) m_characterClass = UnitClass::WARRIOR;
				else if (m_characterClass == UnitClass::WIZARD) m_characterClass = UnitClass::RANGER;

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

			drawMenu(menuIndex);
			break;
		}
		else if (ascii_value == 72)
		{
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

void CharacterCreator::drawMenu(int menuIndex)
{
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

	if (m_vIndex < m_setupMenu.at(menuIndex).size() && m_vIndex > 0) {
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
				m_currIndex = 1;
				Utility::writeToFile("player.cnf", 0, std::string("Name : " + m_characterName + "\n"));
				Utility::writeToFile("player.cnf", 1, std::string("Class : " + getClassNameFromEnum() + "\n"));
				drawMenu(DEF_RACEMENU);
				break;

			case 4:
				m_currIndex = 1;
				break;
			}
			break;
		case DEF_RACEMENU:
				
			break;
		}
	}
}