#include "element.h"

Element::Element()
	: m_Direction(Left), 
	m_isHydrophob(false),
	m_ViewingDirection(East),
	m_Index(0)
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

void Element::setPosition(Vector2i position) 
{
	m_Position = position;
}

Vector2i& Element::getPosition(void) 
{
	return m_Position;
}

void Element::setViewingDirection(ViewingDirection viewingDirection) 
{
	m_ViewingDirection = viewingDirection;
}

ViewingDirection& Element::getViewingDirection(void) 
{
	return m_ViewingDirection;
}

void Element::setIndex(int indexValue) 
{
	m_Index = indexValue;
}

int Element::getIndex(void) 
{
	return m_Index;
}