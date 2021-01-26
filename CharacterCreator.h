#pragma once

#define DEF_SETUPMENU 0
#define DEF_RACEMENU 1
#define DEF_SKILLSMENU 2

#include "GameObject.h"
#include "Class.h"
#include "Utility.h"

#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include <map>

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

private:
	static CharacterCreator  *m_instance;
	std::fstream characterFile;
	
	CharacterCreator();
	virtual ~CharacterCreator();

	void selectAction(int menuIndex);
	void menuSelected(int menuIndex, int index);

	int m_currIndex = 1;
	int m_menuIndex;
	int m_vIndex;

	std::string m_characterName = "";
	UnitClass m_characterClass = UnitClass::WARRIOR;
	std::string(getCharClass) = getClassNameFromEnum();

	std::map<std::string, std::string*> myWonderfullMap;

	std::vector<std::string> m_setupMenu = { "character-creation", "{{ &m_characterName }}", "<  {{ &getClassNameFromEnum }}  >", "Accept", "Back" };

	CharacterCreator(std::string name = "CharacterCreator");
};

