#pragma once
#include "Weapon.h"
class TwoHands : public virtual Weapon
{
    public:
        TwoHands();
        virtual ~TwoHands();
        float getTwoHandsDamageMultiplicator();

    protected :
        float m_twoHandsDamageMultiplicator = 1.8;
};

