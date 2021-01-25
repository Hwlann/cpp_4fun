#include "Effect.h"



Effect::Effect(EffectType effectType, EffectTarget effectTarget, SkillType bonusDamageStat, int amount, int turns, bool applyEachTurn) :
	m_effectType(effectType),
	m_effectTarget(effectTarget),
	m_bonusDamageStat(bonusDamageStat),
	m_amount(amount), m_turns(turns),
	m_applyEachTurn(applyEachTurn)
{

}

Effect::~Effect()
{
}

int Effect::getAmount()
{
	return m_amount;
}

int Effect::getNbTurns()
{
	return m_turns;
}

bool Effect::getApplyEachTurn()
{
	return m_applyEachTurn;
}

Effect::EffectType* Effect::getEffectType()
{
	return &m_effectType;
}

Effect::EffectTarget* Effect::getEffectTarget()
{
	return &m_effectTarget;
}
