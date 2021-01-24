#include "Effect.h"



Effect::Effect(EffectType effectType, EffectTarget effectTarget, int amount, int turns) :
	m_effectType(effectType),
	m_effectTarget(effectTarget),
	m_amount(amount), m_turns(turns)
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

Effect::EffectType* Effect::getEffectType()
{
	return &m_effectType;
}

Effect::EffectTarget* Effect::getEffectTarget()
{
	return &m_effectTarget;
}
