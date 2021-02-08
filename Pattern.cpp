#include "Pattern.h"

Pattern::Pattern(PatternType pattern, int32_t rangeMin, int32_t rangeMax) :
	m_pattern(pattern),
	m_rangeMin(rangeMin), m_rangeMax(rangeMax)
{
	Utility::clamp(&m_rangeMax, m_rangeMin, m_rangeMax);
}

bool Pattern::isInPattern(std::pair<int32_t, int32_t> origin, std::pair<int32_t, int32_t> destination)
{
	generatePatternHitableTiles();
	if (m_patternHitableTiles.size() > 0) {
		for (int i = m_patternHitableTiles.size(); i--; ) {
			if (m_patternHitableTiles.at(i) == destination) return true;
		}
	}
	return false;
}

void Pattern::generatePatternHitableTiles()
{
	switch (m_pattern) {
	case PatternType::LINE :
		break;

	case PatternType::CROSS:
		break;

	case PatternType::CIRCLE:
		break;
	}
}
