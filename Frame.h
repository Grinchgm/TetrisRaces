#pragma once

#include <vector>
#include "IUserInputCommand.h"
#include "IGameObj.h"

const int ROW = 25;
const int COLUMN = 26;
const int obsCount = 5;

struct GameObjPosition
{
	GameObjPosition()
		: x(0)
		, y(0)
	{

	}

	GameObjPosition(int x, int y)
		: x(x)
		, y(y)
	{

	}

	int x;
	int y;

};


class Car : public IGameObj
{
public:
	Car(GameObjPosition pos)
		: m_carPosition(pos)
	{

	}
	virtual void calcLeft() {}; // TODO:
	virtual void calcRight() {}; // TODO:
	virtual void calcDown() {};
	virtual void calcForward() {};
	virtual void calcBack() {};

	GameObjPosition getPosition() const {
		return m_carPosition;
	}
private:
	GameObjPosition m_carPosition;
};

class Obstacle : public IGameObj
{
public:
	Obstacle() {};
	Obstacle(GameObjPosition pos)
		: m_obstaclePosition(pos)
	{

	}
	virtual void calcLeft() {};
	virtual void calcRight() {};
	virtual void calcDown() {}; // TODO: move down for each frame
	virtual void calcForward() {};
	virtual void calcBack() {};

	GameObjPosition getPosition() const {
		return m_obstaclePosition;
	}
private:
	GameObjPosition m_obstaclePosition;
};

class Frame
{
public:
	Frame();
	void calculateLeft();	// move car left to 1 pos
	void calculateRight(); // move car right to 1 pos
	void buildObstacles();
	bool checkForCollision() {};
	char getScreenElement(int oX, int oY);
	
	void update(IUserInputCommand* command)
	{
		if (command)
		{
			command->proceed(m_car);
			for (auto obstacle : m_obstacles)
			{
				command->proceed(obstacle);
			}
		}
	}

private:
	char m_screen[ROW][COLUMN];
	/*int m_carTopX;
	int m_carTopY;*/

	/*struct obstuclesPosition
	{
		int x;
		int y;
	};*/
	Car m_car;
	std::vector<Obstacle> m_obstacles;
};