#include "Class.h"

Class::UnitClass Class::getClass()
{
	return m_classType;
}

Class::Class(UnitClass classType) :
	m_classType(classType)
{

}
