#pragma once
#ifndef DEF_GAMEINSTANCE
#define DEF_GAMEINSTANCE

#include "GameObject.h"
#include "Map.h"

#include "Character.h"
#include "Sword.h"
#include "Chief.h"
#include "Warrior.h"

#include <thread>
#include <chrono>

class GameInstance : public GameObject
{
    public:
        static GameInstance* getInstance();
        virtual ~GameInstance();
        void startGame();

        void addCharacters(std::pair<Class::UnitClass, std::vector<Character*>> characterByClass, std::pair<Race::CharacterRace, std::vector<Character*>> characterByRace);

    private:
        GameInstance();
        static GameInstance* m_gameInstance;

        std::map<Class::UnitClass, std::vector<Character*>> m_listByClass;
        std::map<Race::CharacterRace, std::vector<Character*>> m_listByRace;

        Character* m_char_1 = nullptr;
        Character* m_char_2 = nullptr;

};
#endif

