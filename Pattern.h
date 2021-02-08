#pragma once
#include "GameObject.h"
#include "Utility.h"
#include <vector>

class Pattern :
    public GameObject
{
    public:
        enum class PatternType
        {
            LINE,
            CROSS,
            CIRCLE // ?
        };
        Pattern(PatternType pattern = PatternType::LINE, int32_t rangeMin = 0, int32_t rangeMax = 0);
        bool isInPattern(std::pair<int32_t, int32_t> origin, std::pair<int32_t, int32_t> destination);
        void generatePatternHitableTiles();

    private:
        PatternType m_pattern;
        int32_t m_rangeMin;
        int32_t m_rangeMax;
        std::vector<std::pair<int32_t, int32_t>> m_patternHitableTiles;

};

