#include "element.h"

Element::Element()
	: m_Direction(Left)
	, m_isHydrophob(false)
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

void Element::setHydrophob(bool state) 
{
	m_isHydrophob = state;
}

bool Element::isHydrophob(void) 
{
	return m_isHydrophob;
}