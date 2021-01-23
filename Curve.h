#pragma once
#ifndef DEF_CURVE
#define DEF_CURVE

#include "GameObject.h"
#include <vector>
class Curve : public GameObject
{
public:
    Curve(std::vector<float> polynominal);
    virtual ~Curve();
    float getImageOfX(float x);

private:
    std::vector<float> m_polynominal;

};
#endif // !DEF_CURVE




