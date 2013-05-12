#include "element.h"

Element::Element()
{
}

Element::~Element()
{
}

void Element::setDirection(Direction direction) 
{
	m_Direction = direction;
}

Direction& Element::getDirection(void) 
{
	return m_Direction;
}