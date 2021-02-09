#pragma once

#define DEF_SETUPMENU 0
#define DEF_RACEMENU 1
#define DEF_SKILLSMENU 2

#define DEF_SELECT_CHAR ">"

#include "GameObject.h"
#include "Class.h"
#include "Race.h"
#include "Utility.h"
#include "GameManager.h"

#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include <map>

enum class UnitRace {
	HUMAN,
	ORC,
	ELVEN
};

enum class UnitClass {
	WARRIOR,
	RANGER,
	WIZARD
};


class CharacterCreator : public GameObject
{
public:
	static CharacterCreator *Instance();
	void drawCharacterSetup();
	void drawCharacterRace();
	void drawCharacterSkills();
	void drawMenu(int menuIndex);

	void generatePlayer();

	std::string getClassNameFromEnum();
	std::string getRaceNameFromEnum();

private:
	static CharacterCreator  *m_instance;
	std::fstream characterFile;
	
	CharacterCreator();
	virtual ~CharacterCreator();

	void selectAction(int menuIndex);
	void menuSelected(int menuIndex, int index);

	int m_menuIndex = 0;
	int m_vIndex = 1;

	int m_currSkillsAmount = 15;

	int m_currStrength = 0;
	int m_currDexterity = 0;
	int m_currIntelligence = 0;

	int m_selectedRace;

	std::string m_characterName = "";
	UnitClass m_characterClass = UnitClass::WARRIOR;
	UnitRace m_characterRace = UnitRace::HUMAN;
	std::string(getCharClass) = getClassNameFromEnum();

	std::map<std::string, int*> myMarvelousMap;
	std::map<std::string, std::string*> myWonderfullMap;

	std::vector<std::vector<std::string>> m_creatorMenus = {
																{ 
																	"character-creation", 
																	"{{ &m_characterName }}", 
																	"<  {{ &getClassNameFromEnum }}  >", 
																	"Accept", 
																	"Back" 
																},
																{ 
																	"character-creation", 
																	"<     Select your race     >", 
																	"Accept", 
																	"Back" 
																},
																{ 
																	"character-creation", 
																	"<    {{ $m_currStrength }}    >", 
																	"<    {{ $m_currDexterity }}    >",
																	"<    {{ $m_currIntelligence }}    >", 
																	"Accept", 
																	"Back" 
																}
															};

	CharacterCreator(std::string name = "CharacterCreator");
};