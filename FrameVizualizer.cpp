#include"FrameVizualizer.h"
#include <iostream>

void FrameVizualizer::draw(Frame& frame)
{
	system("cls");
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			std::cout << frame.getScreenElement(i, j);
		}
		std::cout << std::endl;
	}
}
