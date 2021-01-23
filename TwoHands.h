#pragma once
#include "Weapon.h"
class TwoHands : public virtual Weapon
{
protected :
    Skill* m_secondSkill = nullptr;
};

