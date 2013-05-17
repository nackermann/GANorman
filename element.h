#ifndef ELEMENT_H
#define ELEMENT_H

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#pragma region structs
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

struct Vector2f
{
	float x;
	float y;

	Vector2f(float a = 0, float b = 0) : x(a), y(b)
	{

	}
};

struct Vector3f
{

	float x;
	float y;
	float z;

	Vector3f(float a = 0, float b = 0, float c = 0) : x(a), y(b), z(c) 
	{

	}

	bool operator==(Vector3f &rhs) const
	{
		return (x == rhs.x && y == rhs.y && z == rhs.z);
	}
};


enum ViewingDirection
{
	North,
	East,
	South,
	West
};
#pragma endregion


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

	void setIndex(int indexValue);
	int getIndex(void);

private:
	Direction m_Direction;
	bool m_isHydrophob;		// hydrophob = "black"
	Vector2i m_Position;
	ViewingDirection m_ViewingDirection;
	int m_Index;

};

#endif