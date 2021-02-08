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
	m_char_1 = new Warrior();
	m_char_1->setName("Archaon The Everchosen");

	m_char_2 = new Warrior();
	m_char_2->setName("Bloodthirster");

	m_char_3 = new Chief<Warrior>(std::vector<Warrior*>({ dynamic_cast<Warrior*>(m_char_1), dynamic_cast<Warrior*>(m_char_2)}));
	m_char_3->setName("Khorne");
	m_char_3->setUnitRace(new Ork());


	dynamic_cast<Chief<Warrior>*>(m_char_3)->getHordeList();
	addCharacters(std::vector<Character*>({ m_char_1, m_char_2 }));

	dynamic_cast<Chief<Warrior>*>(m_char_3)->setDesignHordeTarget(m_char_2);

	std::this_thread::sleep_for(std::chrono::milliseconds((int)(10 * 1e3)));


	//std::cout << "WORK IN PROGRESS IHIHIHIHIHIH" << std::endl;
	//exit(EXIT_SUCCESS);

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

std::vector<AiCharacter*> GameInstance::getAllCharacterOfRace(Race::UnitRace unitRace)
{
	std::vector<AiCharacter*> m_charByRace;
	std::map<std::string, Character*>::iterator it;
	for (it = m_characterList.begin(); it != m_characterList.end(); it++) {
		if (it->second->getUnitEnumRace() == unitRace) m_charByRace.push_back(dynamic_cast<AiCharacter*>(it->second));
	}
	return m_charByRace;
}

