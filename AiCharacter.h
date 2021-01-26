#pragma once
#ifndef DEF_AI_CHARACTER
#define DEF_AI_CHARACTER

#include "Character.h"
#include "Curve.h"
#include "Behaviour.h"


class AiCharacter : public Character
{
    public:
        AiCharacter();
        virtual ~AiCharacter();

        // DIFFICULTY ADJUSTMENT
        void applyDifficulty();

        // MOVEMENT
        void moveToClosestLocationFromTarget(Character* target);
        void moveToSafeLocation();
        void moveToClosestLocationFromTargetWithSafestPath();

    private :
        Curve* m_difficultyCurve = nullptr;
        Behaviour* m_behaviour = nullptr;
};

#endif


