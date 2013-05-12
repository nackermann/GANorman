#ifndef ELEMENT_H
#define ELEMENT_H

enum Direction
{
	Left,
	Right,
	Straight
};

class Element
{
public:
	Element();
	~Element();

	void setDirection(Direction direction);
	Direction& getDirection(void);

private:
	Direction m_Direction;
};

#endif