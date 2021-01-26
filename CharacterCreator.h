#pragma once

#include "GameObject.h"
#include "Class.h"
#include "Utility.h"

#include <vector>
#include <map>

class CharacterCreator : public GameObject
{
public:
	static CharacterCreator *Instance();
	void drawCharacterSetup();
	void drawCharacterFaces();
	void drawCharacterSkills();

	std::string getClassNameFromEnum();

private:
	static CharacterCreator  *m_instance;
	
	CharacterCreator();
	virtual ~CharacterCreator();

	std::string m_characterName = "Toto";
	UnitClass m_characterClass = UnitClass::WARRIOR;

	std::map<std::string, std::string*> myWonderfullMap;

	CharacterCreator(std::string name = "CharacterCreator");
};

