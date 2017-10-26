#include<iostream>
#include"Game.h"

int main(int argc, char* argv[])
{
	system("mode con cols=26 lines=26");//задание размеров окна консоли
	system("title Dead Racer");//задание описания окна консоли
	system("color 0A");//задание цвета консоли (0-задний фон; А-передний фон)
	//Frame frame;
	//FrameVizualizer vizualizer;
	Game game;
	while (true)
	{
		game.start();
	}

	return 0;
}
