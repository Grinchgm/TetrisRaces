#include<iostream>
#include"Game.h"

int main(int argc, char* argv[])
{
	system("mode con cols=26 lines=26");//������� �������� ���� �������
	system("title Dead Racer");//������� �������� ���� �������
	system("color 0A");//������� ����� ������� (0-������ ���; �-�������� ���)
	//Frame frame;
	//FrameVizualizer vizualizer;
	Game game;
	while (true)
	{
		game.start();
	}

	return 0;
}
