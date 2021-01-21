#pragma once
#ifndef DEF_PLAYER_CHARACTER
#define DEF_PLAYER_CHARACTER

#include "Character.h"
class PlayerCharacter :
    public Character
{
    void move(Character::CharacterPosition* position);
};

#endif

