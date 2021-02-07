#pragma once
#ifndef DEF_GAMEINSTANCE
#define DEF_GAMEINSTANCE

#include "GameObject.h"
#include "Map.h"

#include "AiCharacter.h"
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
        GameInstance();
        void addCharacters(std::vector<Character*>characters);

    private:
        static GameInstance* m_gameInstance;

        std::map<std::string, Character *> m_characterList;

        Character* m_char_1 = nullptr;
        Character* m_char_2 = nullptr;

};
#endif

