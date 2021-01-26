#include "CharacterCreator.h"

CharacterCreator* CharacterCreator::m_instance = nullptr;

CharacterCreator::CharacterCreator(std::string name) : GameObject(name)
{

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
	system("cls");
	std::vector<std::string> menuChoises = {"character-creation", "{{ &m_characterName }}", "<  {{ &getClassNameFromEnum }}  >", "Accept", "Back"};
	myWonderfullMap.insert(std::pair<std::string, std::string*>("m_characterName", &m_characterName));
	myWonderfullMap.insert(std::pair<std::string, std::string*>("getClassNameFromEnum", &getClassNameFromEnum()));

	std::cout << Utility::printT(menuChoises.at(1), myWonderfullMap) << std::endl;
	std::cout << Utility::printT(menuChoises.at(2), myWonderfullMap) << std::endl;
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
