#include <iostream>
using namespace std;

const int ROW = 25;
const int COLUMN = 26;

/*int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Rus");//������� ���������
	system("mode con cols=26 lines=26");//������� �������� ���� �������
	system("title Dead Racer");//������� �������� ���� �������
	system("color 0A");//������� ����� ������� (0-������ ���; �-�������� ���)

	
	int speed = 5;
	int range = 0;
	int lifes = 3;
	int timer = 80;
	int odometer = 0;
	char scr[LINES][COLS];

	for (int i = 0; i < LINES; i++)//�������� �� ������
		for (int j = 0; j < COLS; j++)
			scr[i][j] = ' ';

	for (int i = COLS; lifes > 0; i--, lifes--, scr[0][i] = '@');
	//���������� ����������
	int speedBuf = speed;
	//���������� ���������� �� ��������� ������
	for (int i = COLS - 9; speed != 0; i--, scr[0][i] = static_cast<char>(speed % 10) + '0', speed /= 10);
	//����������� "��/�"
	scr[0][COLS - 9] = '�'; scr[0][COLS - 8] = '�'; scr[0][COLS - 7] = '/'; scr[0][COLS - 6] = '�';

	int odometerBuf = odometer, odometerDigitLength;
	//���������� ���������� ���� �� ��������
	for (odometerDigitLength = 0; odometerBuf != 0; odometerBuf /= 10, odometerDigitLength++);
	//���������� �������� �� ��������� ������
	for (int i = odometerDigitLength, odometerBuf = odometer; i >= 0; i--, 
		scr[0][i] = odometerBuf % 10 + '0', odometerBuf /= 10);
	//����������� "��"
	scr[0][odometerDigitLength++] = '�'; scr[0][odometerDigitLength++] = '�';
	//��������� ��������
	odometer++;

	for (int i = 1; i < LINES; i++)
	{
		if (i % 2 == 0)
		{
			scr[i][0] = '#';
			scr[i][COLS - 1] = '#';
			scr[i][COLS / 2] = '||';
		}
		scr[i][1] = '#';
		scr[i][COLS - 2] = '#';
	}

	// ���������� ������

	scr[LINES - 1][COLS/2 - 1] = scr[LINES - 1][COLS / 2] = scr[LINES - 1][COLS / 2 + 1] = 'x';
	scr[LINES - 2][COLS/2] = 'x';
	scr[LINES - 3][COLS / 2 - 1] = scr[LINES - 3][COLS / 2] = scr[LINES - 3][COLS / 2 + 1] = 'x';
	scr[LINES - 4][COLS / 2] = 'x';
	

	
	for (int i = 0; i < LINES; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << scr[i][j];
		}
		cout << endl;
	}

	cin.get();
	return 0;
}*/






/*
#include "conio.h"
#include "windows.h"
#include "ctime"
#include <iostream>
using namespace std;

struct player//����������� ���������, �������� ������ � ����������� ������-���� ������������ �������� ������
{
	char name[7];
	int score;
	int mday;
	int mon;
	int year;
};

struct save//����������� ���������, �������� ������ � ������������� ������� ������
{
	int weaponPos;
	int timer;
	int odometer;
	int lifes;
	char screen[14][50];
};

void ScreenOutput(char scr[14][50])//������� ������������� ������ ������� � �������
{
	system("cls");
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 50; j++)
			cout << scr[i][j];
		if (i != 13)
			cout << endl;
	}
}
//���� ���������� �������
void StartMenu(int switcher);//�������, ������������ �� �������� ����, �������� ������ "����" � "����������"
void GameMenu(int switcher);//������� �������� ����
void GameStart(char scr[14][50], int lifes, int *timer);//�������, ������������ ��������� ���������� ������ ��� ������� ������ �������� ������
void Game(int var);//������� ������� ������
void GameOver(int score);//�������, ������������ ��� ������, � ������������ ��� ��������� � �������� ����
void Help(int switcher);//������� ������ ������
void TopChart();//������� "��� �����" - ���������� ������ �������

void Help(int switcher)
{
	system("cls");
	cout << "���������: ������� �����/���� | ���������: ESCAPE\n";
	char arr[1800] = { "                ���������� � ����                 ������������� �� ������� � ������� �����/����     ������� ����� � ������ ��� ENTER                  ��������� � ���������� ���� � ESCAPE                              ���������� � ����                 ������������� �����/���� � ������� �����/����     ������� ������� � ������                          ��������� � ����, �������� ���� � ESCAPE                               �������                      �� � ����� ������������ �������, ��������� �      ����������� ����. ��� ���������� �� ��������� �   ��������� ��� ����� ������� ����������. �������   ���������� ������������ �����������. ��� �������  �� ������ � ��� ������ ������������ �����. �������������������� ���������� ����������� �� 40 ��/�.  �� ������ ������� ����������� ����� � �������     ��������� �����, ���������� � �����, � �����      �������� �����������.                             ��� ���������� �������� �� ����� ��������         ������������ ���������� ���������, �������        �������� � ���������� ���������� ������ ������   (������������ ��������  �&�), ���������� �� 3.    ���� ������ ���������� ���� � ������ �������      ESCAPE. ���� ����������, � �� ������� ��          ���������� ���� ����� ����������� ���������� �    ������� ������ �����������!�.                     � ������� ���� ����� ���������� ������� ��������  �������. ��������� ������ ����� ��� ���������!                         ���������                                 Svjatoslav Laskov � AUTHOR                          Igor Marchenko � COACH                         National Technical University                    �Kharkiv Polytechnic Institute�                                                     2016" };
	for (int i = 0, buf = switcher; i < 13; i++)
	{
		for (int j = buf * 50; j < buf * 50 + 50; j++)
			cout << arr[j];
		if (i != 12)
			cout << endl;
		buf++;
	}
	int controller = _getch();//�������� �������� ������� �������
	if (controller == 224)//���� ���� ������ �������
		controller = _getch();//�� ���������� ����� ������
	if (controller == 72)//���� ������� �����
		if (switcher > 0)
			Help(switcher - 1);
		else
			Help(0);
	if (controller == 80)//���� ������� ����
		if (switcher < 22)
			Help(switcher + 1);
		else
			Help(22);
	if (controller == 27)//���� Escape
		StartMenu(2);
}

void StartMenu(int switcher)
{
	system("cls");
	switch (switcher)
	{
	case 1:
		cout << "\n\n\n                  <<  ������!  >>\n\n                      ������!\n\n                     ��� �����\n\n                       �����";
		break;
	case 2:
		cout << "\n\n\n                      ������!\n\n                  <<  ������!  >>\n\n                     ��� �����\n\n                       �����";
		break;
	case 3:
		cout << "\n\n\n                      ������!\n\n                      ������!\n\n                  << ��� ����� >>\n\n                       �����";
		break;
	case 4:
		cout << "\n\n\n                      ������!\n\n                      ������!\n\n                     ��� �����\n\n                  <<   �����   >>";
		break;
	}
	int choice = _getch();
	if (choice == 224)
		choice = _getch();
	if (choice == 72)
		if (switcher != 1)
			StartMenu(switcher - 1);
		else
			StartMenu(4);
	if (choice == 80)
		if (switcher != 4)
			StartMenu(switcher + 1);
		else
			StartMenu(1);
	if (choice == 13 || choice == 32)
	{
		if (switcher == 1)
			GameMenu(1);
		if (switcher == 2)
			Help(0);
		if (switcher == 3)
			TopChart();
		if (switcher == 4)
			_exit(0);
	}
}

void GameMenu(int switcher)
{
	system("cls");
	if (switcher == 1)
		cout << "\n\n\n\n\n                <<  ����� ����!  >>\n\n                    ����������!";
	else
		cout << "\n\n\n\n\n                    ����� ����!\n\n                <<  ����������!  >>";
	int choice = _getch();
	if (choice == 224)
		choice = _getch();
	if (choice == 72 || choice == 80)
		GameMenu(3 - switcher);
	if (choice == 27)
		StartMenu(1);
	if (choice == 13 || choice == 32)
		Game(switcher);
}

void GameStart(char scr[14][50], int lifes, int *timer)
{
	for (int i = 0; i < 14; i++)//�������� �� ������
		for (int j = 0; j < 50; j++)
			scr[i][j] = ' ';
	for (int i = 50; lifes > 0; i--, lifes--, scr[0][i] = '&');
	*timer = 80;
	char borderSymbols[] = { '�', '�', '�', ' ' };
	for (int aboveBelow = 0; aboveBelow < 50; aboveBelow++)//���������� �������� � ������� ����� (2 + 2)
	{
		scr[1][aboveBelow] = borderSymbols[rand() % 3];
		if (scr[1][aboveBelow] == '�')
			scr[2][aboveBelow] = '�';

		scr[13][aboveBelow] = borderSymbols[rand() % 3];
		if (scr[13][aboveBelow] == '�')
			scr[12][aboveBelow] = '�';
	}
	scr[6][0] = '\\'; scr[6][1] = '\\';//���������� �������
	scr[7][0] = '3'; scr[7][1] = '='; scr[7][2] = '=';
	scr[8][0] = '/'; scr[8][1] = '/';
}

void GameOver(int score)
{
	system("cls");
	player newPlayer;//���������� ���������
	newPlayer.score = score;//������������� ���� ���������� �����
	cout << "����������� ���!\n�� ������������ " << score << " ����������.\n\n(����������, �� ����������� ������������� �������)\n(����������� �� ����� 6 ��������)\n�������� ���� ��� � ������� ��������\n��� ���������� ������� �������: ";
	cin.getline(newPlayer.name, 7);//������������� ���� �����
	time_t timeCur;
	time(&timeCur);
	struct tm * timeCurStruct = 0;
	localtime_s(timeCurStruct, &timeCur);
	newPlayer.mday = timeCurStruct->tm_mday;//������������� ���� ���������� ����
	newPlayer.mon = timeCurStruct->tm_mon;
	newPlayer.year = timeCurStruct->tm_year;
	FILE *topChart;
	fopen_s(&topChart, "TopChart.bin", "ab+");
	fwrite(&newPlayer, 1, sizeof(player), topChart);//�������� ���������� � ����
	fclose(topChart);
	TopChart();
}

void TopChart()
{
	FILE *topChart;
	fopen_s(&topChart, "TopChart.bin", "rb+");
	system("cls");
	if (topChart == NULL)//���� ��������� ������ ��� �������� �����
	{
		system("cls");
		cout << "��� �� ������� ����������.";
		Sleep(1000);
		system("cls");
		cout << "��� �� ������� ����������..";
		Sleep(1000);
		system("cls");
		cout << "��� �� ������� ����������...";
		Sleep(1000);
		cout << "\n������� ����� �������, ����� ���������.";
		_getch();
		StartMenu(3);
	}
	fseek(topChart, 0L, SEEK_END);
	int playerAmount = ftell(topChart) / sizeof(player);
	player *temp = new player[playerAmount];
	fseek(topChart, 0L, SEEK_SET);
	for (int i = 0; i < playerAmount; i++)//����������� ������������ ����� � ���������
		fread(&temp[i], 1, sizeof(player), topChart);
	fclose(topChart);
	for (int i = 1; i < playerAmount; i++)//���������� �������� �� �������� �������� ������
		if (temp[i].score > temp[i - 1].score)
		{
			player tempAlone;
			//strcpy(tempAlone.name, temp[i].name);
			tempAlone.score = temp[i].score;
			tempAlone.mday = temp[i].mday;
			tempAlone.mon = temp[i].mon;
			tempAlone.year = temp[i].year;

			//strcpy(temp[i].name, temp[i - 1].name);
			temp[i].score = temp[i - 1].score;
			temp[i].mday = temp[i - 1].mday;
			temp[i].mon = temp[i - 1].mon;
			temp[i].year = temp[i - 1].year;

			//strcpy(temp[i - 1].name, tempAlone.name);
			temp[i - 1].score = tempAlone.score;
			temp[i - 1].mday = tempAlone.mday;
			temp[i - 1].mon = tempAlone.mon;
			temp[i - 1].year = tempAlone.year;

			if (i > 1)
				i -= 2;
			else
				i = 0;
		}
	if (playerAmount > 12)
		playerAmount = 12;
	cout << "�       " << "���" << '\t' << "����" << '\t' << "����" << endl;//����� ������� ������� � �������
	for (int i = 0; i < playerAmount; i++)
	{
		cout << i + 1 << ')' << '\t' << temp[i].name << '\t' << temp[i].score << '\t';
		if (temp[i].mday / 10 == 0)
			cout << '0' << temp[i].mday;
		else
			cout << temp[i].mday;
		cout << ' ';
		switch (temp[i].mon)
		{
		case 0:
			cout << "������";
			break;
		case 1:
			cout << "�������";
			break;
		case 2:
			cout << "�����";
			break;
		case 3:
			cout << "������";
			break;
		case 4:
			cout << "���";
			break;
		case 5:
			cout << "����";
			break;
		case 6:
			cout << "����";
			break;
		case 7:
			cout << "�������";
			break;
		case 8:
			cout << "��������";
			break;
		case 9:
			cout << "�������";
			break;
		case 10:
			cout << "������";
			break;
		case 11:
			cout << "�������";
			break;
		}
		cout << ' ' << 1900 + temp[i].year << endl;
	}
	fopen_s(&topChart, "TopChart.bin", "wb+");
	for (int i = 0; i < playerAmount; i++)//������ ������� ������� � �������� ����
		fwrite(&temp[i], 1, sizeof(player), topChart);
	fclose(topChart);
	delete[] temp;
	_getch();
	StartMenu(3);
}

int main()
{
	setlocale(LC_ALL, "Rus");//������� ���������
	system("mode con cols=51 lines=14");//������� �������� ���� �������
	system("title Space Invader");//������� �������� ���� �������
	system("color 0A");//������� ����� ������� (0-������ ���; �-�������� ���)
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);//��������� ������
	CONSOLE_CURSOR_INFO cursor = { 100, false };//����� �� 1 �� 100 ������ ������� � ���������; false\true - ���������
	SetConsoleCursorInfo(hCons, &cursor);//���������� �������� ���������� �������
	int timer = 200;
	cout << "          (____/(__)  \\_/\\_/ \\___)(____)\n\n\n\n\n\n\n\n\n\n\n      __   __ _  _  _   __   ____  ____  ____\n     (  )(  ( \\/ )( \\ / _\\ (    \\(  __)(  _ \\";//������������� ��������
	Sleep(timer);
	system("cls");
	cout << "          \\___ \\ ) __//    \\( (__  ) _)\n          (____/(__)  \\_/\\_/ \\___)(____)\n\n\n\n\n\n\n\n\n      __  __ _  _  _   __   ____  ____  ____\n     (  )(  ( \\/ )( \\ / _\\ (    \\(  __)(  _ \\\n      )( /    /\\ \\/ //    \\ ) D ( ) _)  )   /";//������������� ��������
	Sleep(timer);
	system("cls");
	cout << "          / ___)(  _ \\ / _\\  / __)(  __)\n          \\___ \\ ) __//    \\( (__  ) _)\n          (____/(__)  \\_/\\_/ \\___)(____)\n\n\n\n\n\n\n      __  __ _  _  _   __   ____  ____  ____\n     (  )(  ( \\/ )( \\ / _\\ (    \\(  __)(  _ \\\n      )( /    /\\ \\/ //    \\ ) D ( ) _)  )   /\n     (__)\\_)__) \\__/ \\_/\\_/(____/(____)(__\\_)";//������������� ��������
	Sleep(timer);
	system("cls");
	cout << "           ____  ____   __    ___  ____\n          / ___)(  _ \\ / _\\  / __)(  __)\n          \\___ \\ ) __//    \\( (__  ) _)\n          (____/(__)  \\_/\\_/ \\___)(____)\n\n\n\n\n      __  __ _  _  _   __   ____  ____  ____\n     (  )(  ( \\/ )( \\ / _\\ (    \\(  __)(  _ \\\n      )( /    /\\ \\/ //    \\ ) D ( ) _)  )   /\n     (__)\\_)__) \\__/ \\_/\\_/(____/(____)(__\\_)";//������������� ��������
	Sleep(timer);
	system("cls");
	cout << "\n           ____  ____   __    ___  ____\n          / ___)(  _ \\ / _\\  / __)(  __)\n          \\___ \\ ) __//    \\( (__  ) _)\n          (____/(__)  \\_/\\_/ \\___)(____)\n\n\n      __  __ _  _  _   __   ____  ____  ____\n     (  )(  ( \\/ )( \\ / _\\ (    \\(  __)(  _ \\\n      )( /    /\\ \\/ //    \\ ) D ( ) _)  )   /\n     (__)\\_)__) \\__/ \\_/\\_/(____/(____)(__\\_)";//������������� ��������
	Sleep(timer);
	system("cls");
	cout << "\n\n           ____  ____   __    ___  ____\n          / ___)(  _ \\ / _\\  / __)(  __)\n          \\___ \\ ) __//    \\( (__  ) _)\n          (____/(__)  \\_/\\_/ \\___)(____)\n      __  __ _  _  _   __   ____  ____  ____\n     (  )(  ( \\/ )( \\ / _\\ (    \\(  __)(  _ \\\n      )( /    /\\ \\/ //    \\ ) D ( ) _)  )   /\n     (__)\\_)__) \\__/ \\_/\\_/(____/(____)(__\\_)";//������������� ��������
	cout << '\a';
	Sleep(10 * timer);//�������� ��������
	StartMenu(1);
	return 0;
}

void Game(int var)
{
	int weaponPos;//������� ������ ���� � �������
	int timer;//�������� ����� ������������� ������
	int odometer;//���������� ����������� ������, ��� �� �������� ����
	int lifes;//���������� ������
	char control = '&';//���������� ���������� ��������
	int shotPause = 4;//�������� ����� ���������� (��������� �� ���� ����������� ������)
	int speed;//�������� �������
	char scr[14][50];
	if (var == 1)
	{
		weaponPos = 7;//������� ������ ���� � �������
		odometer = 1;//���������� ����������� ������, ��� �� �������� ����
		lifes = 3;//���������� ������
		GameStart(scr, lifes, &timer);
	}
	else//��� �������������� �������� ������ �� ����������
	{
		FILE *saveBin;
		fopen_s(&saveBin, "CurrentSave.bin", "rb");
		if (!saveBin)
		{
			system("cls");
			cout << "��� ����������.";
			Sleep(1000);
			system("cls");
			cout << "��� ����������..";
			Sleep(1000);
			system("cls");
			cout << "��� ����������...";
			Sleep(1000);
			Game(1);
		}
		fread(&weaponPos, 1, sizeof(int), saveBin);
		timer = 80;
		fread(&odometer, 1, sizeof(int), saveBin);
		fread(&lifes, 1, sizeof(int), saveBin);
		fread(&scr, 14 * 50, sizeof(char), saveBin);
		fclose(saveBin);
		remove("CurrentSave.bin");
	}
	while (true)
	{
		int odometerBuf = odometer, odometerDigitLength;
		for (odometerDigitLength = 0; odometerBuf != 0; odometerBuf /= 10, odometerDigitLength++);//���������� ���������� ���� �� ��������
		for (int i = odometerDigitLength, odometerBuf = odometer; i >= 0; i--, scr[0][i] = odometerBuf % 10 + '0', odometerBuf /= 10);//���������� �������� �� ��������� ������
		scr[0][odometerDigitLength++] = '�'; scr[0][odometerDigitLength++] = '�';//����������� "��"
		odometer++;//��������� ��������
		speed = 1000 / timer;//���������� ����������
		int speedBuf = speed;
		for (int i = 42; speed != 0; i--, scr[0][i] = speed % 10 + '0', speed /= 10);//���������� ���������� �� ��������� ������
		scr[0][42] = '�'; scr[0][43] = '�'; scr[0][44] = '/'; scr[0][45] = '�';//����������� "��/�"
		if (_kbhit())//���� ������� ���� ������
		{
			control = _getch();//���������� ������ �� ��������
			if (control == 224)
				control = _getch();
		}
		if (control == 13 && shotPause == 4 || control == 32 && shotPause == 4)//��� ������� �� ����� ���� ����� ������������
		{
			scr[weaponPos][3] = '-';
			shotPause = 0;
		}
		if (shotPause < 4)//�����������
			shotPause++;
		if (control == 27)//��� ������
		{
			FILE *saveBin;
			fopen_s(&saveBin, "CurrentSave.bin", "wb");
			fwrite(&weaponPos, 1, sizeof(int), saveBin);
			fwrite(&odometer, 1, sizeof(int), saveBin);
			fwrite(&lifes, 1, sizeof(int), saveBin);
			fwrite(&scr, 14 * 50, sizeof(char), saveBin);
			fclose(saveBin);
			GameMenu(2);
		}
		if (control == 72)//��� �������� ������� �����
			if (scr[2][0] == '\\' || scr[3][0] == '\\' && scr[2][0] == '�' || scr[3][1] == '\\' && scr[2][1] == '�')//���� ������� �������� � ������� ���� - ���� ��������
				if (lifes > 1)
				{
					cout << '\a';
					lifes--;
					weaponPos = 7;
					GameStart(scr, lifes, &timer);
					Sleep(1000);
				}
				else
					GameOver(odometer);
			else
			{
				for (int i = 2; i < 13; i++)//������� ��������� �� ������� ����
					for (int j = 0; j < 49; j++)
						if (scr[i][j] == '3' || scr[i][j] == '\\' || scr[i][j] == '=' || scr[i][j] == '/')
						{
							scr[i - 1][j] = scr[i][j];
							scr[i][j] = ' ';
						}
				weaponPos--;
			}
		if (control == 80)//��� �������� ������� ����
			if (scr[12][0] == '/' || scr[11][0] == '/' && scr[12][0] == '�' || scr[11][1] == '/' && scr[12][1] == '�')//���� ������� �������� � ������ ���� - ���� ��������
				if (lifes > 1)
				{
					cout << '\a';
					lifes--;
					weaponPos = 7;
					GameStart(scr, lifes, &timer);
					Sleep(1000);
				}
				else
					GameOver(odometer);
			else
			{
				for (int i = 12; i >= 2; i--)//������� ��������� �� ������� ����
					for (int j = 0; j < 49; j++)
						if (scr[i][j] == '3' || scr[i][j] == '\\' || scr[i][j] == '=' || scr[i][j] == '/')
						{
							scr[i + 1][j] = scr[i][j];
							scr[i][j] = ' ';
						}
				weaponPos++;
			}
		for (int i = 1; i < 14; i++)//��� "�����������" �������� ��������� �� ������� �����
			for (int j = 0; j < 49; j++)
			{
				if (scr[i][j] == '\\' && scr[i][j + 1] == '�' || scr[i][j] == '=' && scr[i][j + 1] == '�' || scr[i][j] == '/' && scr[i][j + 1] == '�')
					if (lifes > 1)
					{
						cout << '\a';
						lifes--;
						weaponPos = 7;
						GameStart(scr, lifes, &timer);
						Sleep(1000);
					}
					else
						GameOver(odometer);
				if (scr[i][j] != '3' && scr[i][j] != '\\' && scr[i][j] != '=' && scr[i][j] != '/' && scr[i][j] != '-' && scr[i][j + 1] != '-')
					scr[i][j] = scr[i][j + 1];
				if (scr[i][j] == '�')
					scr[i][j + 1] = ' ';
			}
		for (int i = 1; i < 14; i++)//��� ������� ��������� �� ������� ������
			for (int j = 48; j >= 0; j--)
				if (scr[i][j] == '-')
					if (j != 48)
					{
						scr[i][j + 1] = '-';
						scr[i][j] = ' ';
					}
					else
						scr[i][j] = ' ';
		char borderSymbols[] = { '�', '�', '�', ' ' };
		scr[2][49] = ' ';//��������� ���������� ����� ��������� �����
		scr[1][49] = borderSymbols[rand() % 3];
		if (scr[1][49] == '�')
			scr[2][49] = '�';
		scr[12][49] = ' ';
		scr[13][49] = borderSymbols[rand() % 3];
		if (scr[13][49] == '�')
			scr[12][49] = '�';
		for (int i = 3; i < 12; i++)//��������� ��������� ������������ ������
		{
			if (rand() % 10 == 1)
				scr[i][49] = '�';
		}
		ScreenOutput(scr);//����� ������
		if (control != '&')//"���������" ����������� ����������
			control = '&';
		if (timer > 25)//��������� �������
			timer--;
		Sleep(timer);//�������� �����������
	}
}
*/