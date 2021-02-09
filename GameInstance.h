#pragma once
#ifndef DEF_GAMEINSTANCE
#define DEF_GAMEINSTANCE

#include "GameObject.h"
#include "Map.h"

// SPAWNALES
#include "AiCharacter.h"
#include "Chief.h"

// CLASSES
#include "Warrior.h"

// RACES
#include "Ork.h"
#include "Human.h"

// WEAPONS
#include "Sword.h"

// ARMOURS
#include "PlateArmour.h";
#include "ChainmailArmour.h"

// TIME MANAGEMENT
#include <thread>
#include <chrono>


#define PLAYER_CHARACTER_KEY "player"

class GameInstance : public GameObject
{
    public:
        static GameInstance* getInstance();
        virtual ~GameInstance();
        void startGame(Character *playerCharacter, int difficulty);
        GameInstance();
        inline void addCharacter(std::string name, Class* unitClass, Race* unitRace, Character* character,
                                 Armour* armour, Weapon* leftHand, Weapon* rightHand, int team);
        std::vector<AiCharacter*> getAllCharacterOfRace(Race::UnitRace unitRace);
        std::vector<AiCharacter*> getAllCharacterOfClass(Class::UnitClass unitClass, Race::UnitRace unitRace);

    private:
        static GameInstance* m_gameInstance;
        std::map<std::string, Character *> m_characterList;
};
#endif

