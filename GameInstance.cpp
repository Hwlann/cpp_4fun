#include "GameInstance.h"

GameInstance* GameInstance::m_gameInstance = nullptr;

GameInstance::~GameInstance()
{

}

GameInstance* GameInstance::getInstance()
{
	if (m_gameInstance == nullptr) {
		m_gameInstance = new GameInstance();
	}
	return m_gameInstance;
}

void GameInstance::startGame()
{
	// TEST GAME
	m_char_1 = new AiCharacter();
	m_char_1->setName("Karl Franz");
	m_char_2 = new AiCharacter();
	m_char_2->setName("Morathi");

	m_char_1->setUnitClass(new Warrior(Class::UnitClass::WARRIOR));
	m_char_2->setUnitClass(new Warrior(Class::UnitClass::WARRIOR));

	m_char_1->setDualHandWeapon(new Sword(true));

	m_char_2->setRightHandWeapon(new Sword(false));
	m_char_2->setLeftHandWeapon(new Sword(false));

	m_char_1->attackTarget(m_char_1, m_char_2, m_char_1->getWeapon()->getMainSkill());

	m_char_2->attackTarget(m_char_2, m_char_1, m_char_2->getWeapon()->getMainSkill());
	m_char_2->attackTarget(m_char_2, m_char_1, dynamic_cast<OneHand*>(m_char_2->getWeapon())->getOffHandSkill());

	Chief<AiCharacter>* m_char_3 = new Chief<AiCharacter>;
	m_char_3->setUnitClass(new Warrior(Class::UnitClass::WARRIOR));

	addCharacters(std::vector<Character *>({ m_char_1, m_char_2, m_char_3 }));


	m_char_3->setName("Archaon the Everchosen");
	m_char_3->setDualHandWeapon(new Sword(true));
	m_char_3->attackTarget(m_char_3, m_char_1, m_char_3->getWeapon()->getMainSkill());
	m_char_3->setDesignHordeTarget(m_char_2);

	m_char_3->setHordeList(getAllCharacterOfClass(m_char_3->getUnitEnumClass()));

	std::this_thread::sleep_for(std::chrono::milliseconds((int)(10 * 1e3)));

	/*
	std::cout << "WORK IN PROGRESS IHIHIHIHIHIH" << std::endl;
	exit(EXIT_SUCCESS);
	*/
}

GameInstance::GameInstance()
{
}

void GameInstance::addCharacters(std::vector<Character*> characters)
{
	if (characters.size() > 0) {
		for (int i = characters.size(); i--;) {
			m_characterList.insert(std::pair<std::string, Character*>(characters.at(i)->getName(), characters.at(i)));
		}
	}
}

std::vector<AiCharacter*> GameInstance::getAllCharacterOfClass(Class::UnitClass unitClass)
{
	std::vector<AiCharacter*> m_charByClass;
	std::map<std::string, Character*>::iterator it;
	for (it = m_characterList.begin(); it != m_characterList.end(); it++) {
		if (it->second->getUnitEnumClass() == unitClass) m_charByClass.push_back(dynamic_cast<AiCharacter *>(it->second));
	}
	return m_charByClass;
}

std::vector<AiCharacter*> GameInstance::getAllCharacterOfRace(Race::UnitRace unitRace)
{
	std::vector<AiCharacter*> m_charByRace;
	return m_charByRace;
}

