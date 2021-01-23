#include "Curve.h"

Curve::Curve(std::vector<float> polynominal) :
	m_polynominal(polynominal)
{

}

Curve::~Curve()
{
}

float Curve::getImageOfX(float x)
{
	float image = NULL;
	for (int i = 0; i < m_polynominal.size() ; i++) {
		image += pow(-1, i) * m_polynominal.at(i) * pow(x, i);
	}
	return image;
}
