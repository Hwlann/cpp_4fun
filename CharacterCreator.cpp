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
	m_menuIndex = 0;
	system("cls");

	std::ifstream title;
	title.open("ui/character-creator.ui", std::ios::in);
	if (title.is_open())
		std::cout << title.rdbuf() << std::endl;

	std::cout << "\n\n";

	std::cout << "\t\t Select your name :" << std::endl << std::endl;
	std::cout << "\t\t" << ((m_currIndex == 0) ? "> " : "  ") << Utility::printT(m_setupMenu.at(1), myWonderfullMap) << std::endl << std::endl;


	std::cout << "\t\t Select your class :" << std::endl << std::endl;
	std::cout << "\t\t" << ((m_currIndex == 1) ? "> " : "  ") << Utility::printT(m_setupMenu.at(2), myWonderfullMap) << std::endl << std::endl;

	std::cout << "\t\t" << ((m_currIndex == 2) ? "> " : "  ") << Utility::printT(m_setupMenu.at(3), myWonderfullMap) << std::endl;
	std::cout << "\t\t" << ((m_currIndex == 3) ? "> " : "  ") << Utility::printT(m_setupMenu.at(4), myWonderfullMap) << std::endl << std::endl;

	selectAction(m_menuIndex);
}

void CharacterCreator::drawCharacterFaces()
{
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
		case 0:
				drawCharacterSetup();
			break;
		case 1:
				drawCharacterFaces();
			break;
		case 2:
				drawCharacterSkills();
			break;
		default:
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
				break;
			case 4:
				m_currIndex = 1;
				break;
			}
			break;
		}
	}
}
