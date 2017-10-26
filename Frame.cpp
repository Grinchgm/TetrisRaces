#include "Frame.h"
#include<iostream>



Frame::Frame()
	: m_car(GameObjPosition(ROW, COLUMN / 2)) // todo: initial position
	, m_obstacles()
{
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COLUMN; j++)
			m_screen[i][j] = ' ';

	// прорисовка дороги
	for (int i = 1; i < ROW; i++)
	{
		if (i % 3 == 0)
		{
			m_screen[i][0] = '#';
			m_screen[i][COLUMN - 1] = '#';
		}
		m_screen[i][1] = '#';
		m_screen[i][COLUMN - 2] = '#';
	}

	m_carTopX = ROW;
	m_carTopY = COLUMN / 2;

	m_screen[ROW - 1][COLUMN / 2 - 1] = m_screen[ROW - 1][COLUMN / 2] =
		m_screen[ROW - 1][COLUMN / 2 + 1] = 'x';
	m_screen[ROW - 2][COLUMN / 2] = 'x';
	m_screen[ROW - 3][COLUMN / 2 - 1] = m_screen[ROW - 3][COLUMN / 2]
		= m_screen[ROW - 3][COLUMN / 2 + 1] = 'x';
	m_screen[ROW - 4][COLUMN / 2] = 'x';
}


void Frame::calculateLeft()
{
	// если не левая обочина, сместить влево
	if (m_carTopY - 2 != 2)
	{
		m_screen[m_carTopX - 4][m_carTopY] = ' ';
		m_screen[m_carTopX - 3][m_carTopY + 1] = ' ';
		m_screen[m_carTopX - 2][m_carTopY] = ' ';
		m_screen[m_carTopX - 1][m_carTopY + 1] = ' ';
		
		m_carTopY--;

		m_screen[m_carTopX - 4][m_carTopY] = 'x';
		m_screen[m_carTopX - 3][m_carTopY - 1] = 'x';
		m_screen[m_carTopX - 2][m_carTopY] = 'x';
		m_screen[m_carTopX - 1][m_carTopY - 1] = 'x';
		
	}
}

void Frame::calculateRight()
{
	if (m_carTopY + 2 != 23)
	{
		m_screen[m_carTopX - 4][m_carTopY] = ' ';
		m_screen[m_carTopX - 3][m_carTopY - 1] = ' ';
		m_screen[m_carTopX - 2][m_carTopY] = ' ';
		m_screen[m_carTopX - 1][m_carTopY - 1] = ' ';

		m_carTopY++;

		m_screen[m_carTopX - 4][m_carTopY] = 'x';
		m_screen[m_carTopX - 3][m_carTopY + 1] = 'x';
		m_screen[m_carTopX - 2][m_carTopY] = 'x';
		m_screen[m_carTopX - 1][m_carTopY + 1] = 'x';

	}
}

void Frame::buildObstacles()
{
	int randColumn = rand() % (COLUMN - 2) + 2 ;
	for (int i = 1;; i++)
	{
		if (rand() % 10 == 1)
			m_screen[i][49] = '¤';
	}
}

char Frame::getScreenElement(int i, int j)
{
	return m_screen[i][j];
}