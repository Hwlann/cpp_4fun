#pragma once
#include "GameObject.h"
#include "Curve.h"
#include <map>
class Curves : public GameObject
{
	public:
		enum class CurveType
		{
			CHARACTERISTIC_TO_DAMAGE,
			MUSIC
		};

		virtual ~Curves();
		static Curves* getInstance();
		Curve* getCurve(CurveType curveName);

	private:
		Curves();
		std::map<CurveType, Curve*> m_curveList;
		static Curves* m_curves;
};

