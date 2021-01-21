#pragma once
#ifndef DEF_AI_CHARACTER
#define DEF_AI_CHARACTER

#include "Character.h"
class AiCharacter :
    public Character
{
    public:
        void moveToClosestLocationFromTarget(Character* target);
        void moveToSafeLocation();
        void moveToClosestLocationFromTargetWithSafestPath();
};

#endif


