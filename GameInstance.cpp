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
	std::cout << __func__ << std::endl;
	addCharacter("Gork", new Warrior(), new Ork(), new Chief<AiCharacter>(), new PlateArmour(), new Sword(true), nullptr,  1);
	addCharacter("Ironjaws", new Warrior(), new Ork(), new AiCharacter(), new PlateArmour(), new Sword(false), new Sword(false), 1 );
	addCharacter("Bonejaws", new Warrior(), new Ork(), new AiCharacter(), new PlateArmour(), new Sword(false), new Sword(false), 1);

	addCharacter("Michel", new Warrior(), new Human(), new AiCharacter(), new ChainmailArmour(), new Sword(true), nullptr, 2);
	addCharacter("Berger", new Warrior(), new Human(), new AiCharacter(), new PlateArmour(), new Sword(false), new Sword(false), 2);

	dynamic_cast<Chief<AiCharacter>*>(m_characterList.at("Gork"))->setHordeList(getAllCharacterOfClass(Class::UnitClass::WARRIOR, m_characterList.at("Gork")->getUnitEnumRace()));
	dynamic_cast<Chief<AiCharacter>*>(m_characterList.at("Gork"))->getHordeList();
	dynamic_cast<Chief<AiCharacter>*>(m_characterList.at("Gork"))->setDesignHordeTarget(m_characterList.at("Michel"));

	std::this_thread::sleep_for(std::chrono::milliseconds((int)(10 * 1e3)));

	//std::cout << "WORK IN PROGRESS IHIHIHIHIHIH" << std::endl;
	//exit(EXIT_SUCCESS);
}

GameInstance::GameInstance()
{

}

void GameInstance::addCharacter(std::string name, Class* unitClass, Race* unitRace, Character* character,
								Armour *armour, Weapon *leftHand, Weapon *rightHand, int team)
{
	character->setName(name);
	character->setUnitClass(unitClass);
	character->setUnitRace(unitRace);
	character->setTeamNumber(team);
	character->setArmour(armour);
	if (*leftHand->getWeaponSize() == Weapon::WeaponSize::ONE_HAND && *rightHand->getWeaponSize() == Weapon::WeaponSize::ONE_HAND) {
		character->setLeftHandWeapon(leftHand);
		character->setRightHandWeapon(rightHand);
	}
	else if (*leftHand->getWeaponSize() == Weapon::WeaponSize::TWO_HANDS || *rightHand->getWeaponSize() == Weapon::WeaponSize::TWO_HANDS) {
		if (leftHand != nullptr) character->setDualHandWeapon(leftHand);
		else character->setDualHandWeapon(rightHand);
	}
	m_characterList.insert(std::pair<std::string, Character *>(character->getName(), character));
}

std::vector<AiCharacter*> GameInstance::getAllCharacterOfRace(Race::UnitRace unitRace)
{
	std::vector<AiCharacter*> m_charByRace;
	std::map<std::string, Character*>::iterator it;
	for (it = m_characterList.begin(); it != m_characterList.end(); it++) {
		if (it->second->getUnitEnumRace() == unitRace) m_charByRace.push_back(dynamic_cast<AiCharacter*>(it->second));
	}
	return m_charByRace;
}

std::vector<AiCharacter*> GameInstance::getAllCharacterOfClass(Class::UnitClass unitClass, Race::UnitRace unitRace)
{
	std::vector<AiCharacter*> m_charByClass;
	std::map<std::string, Character*>::iterator it;
	for (it = m_characterList.begin(); it != m_characterList.end(); it++) {
		if (it->second->getUnitEnumClass() == unitClass && it->second->getUnitEnumRace() == unitRace) m_charByClass.push_back(dynamic_cast<AiCharacter*>(it->second));
	}
	return m_charByClass;
}

