#pragma once
#ifndef DEF_RACE
#define DEF_RACE
#include "GameObject.h"
#include "Skill.h"

class Race : public GameObject
{
public:
	Race();
	virtual ~Race();

private:
	Skill* m_passiveSkill = nullptr;


};
#endif // !DEF_RACE




