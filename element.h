#ifndef ELEMENT_H
#define ELEMENT_H

enum Direction
{
	Left,
	Right,
	Straight
};

struct Vector2i
{
	int x;
	int y;

	Vector2i(int a = 0, int b = 0) : x(a), y(b)
	{

	}
};

enum ViewingDirection
{
	North,
	East,
	South,
	West
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

	void setPosition(Vector2i position);
	Vector2i& getPosition(void);

	void setViewingDirection(ViewingDirection viewingDirection);
	ViewingDirection& getViewingDirection(void);

private:
	Direction m_Direction;
	bool m_isHydrophob;		// hydrophob = "black"
	Vector2i m_Position;
	ViewingDirection m_ViewingDirection;

};

#endif