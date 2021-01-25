#pragma once

#include "GameObject.h"
#include "Class.h"

#include <vector>

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

	std::string m_characterName = "";
	UnitClass m_characterClass = UnitClass::WARRIOR;

	CharacterCreator(std::string name = "CharacterCreator");
};

