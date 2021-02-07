#include "Curves.h"

Curves* Curves::m_curves = nullptr;

Curves::~Curves()
{

}

Curves* Curves::getInstance()
{
    if (m_curves == nullptr) {
        m_curves = new Curves();
    }
    return m_curves;
}

Curve* Curves::getCurve(CurveType curveName)
{
    return m_curveList.at(curveName) != nullptr ? m_curveList.at(curveName) : nullptr;
}

Curves::Curves() {
    m_curveList.insert(std::pair<CurveType, Curve*>());
}