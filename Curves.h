#pragma once
#include "GameObject.h"
#include "Curve.h"
#include <map>
class Curves : public GameObject
{
	public:
		virtual ~Curves();
		static Curves* getInstance();
		Curve* getCurve(std::string curveName);

	private:
		Curves();
		std::map<std::string, Curve*> m_curveList;
		static Curves* m_curves;
};

