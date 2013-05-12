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

	void setHydrophob(bool state);
	bool isHydrophob(void);

private:
	Direction m_Direction;
	bool m_isHydrophob;		// hydrophob = "black"
};

#endif