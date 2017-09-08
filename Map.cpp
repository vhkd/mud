#include <iostream>
#include "Map.h"

using namespace std;

Map::Map()
{
}

Map::~Map()
{
}

void Map::Store()
{
}

void Map::Story(int mapNum)
{
}

Map_Total::Map_Total()
{
}

Map_Total::~Map_Total()
{
}

void Map_Total::ShowMap()
{
	cout << "�����ͼ:" << endl;
	cout << "          999999               " << endl;
	cout << "             \ "                 << endl;
	cout << "              \  "               << endl;
	cout << "    888888   777777  "           << endl;
	cout << "        \      |    "            << endl;
	cout << "         \    666666     "       << endl;
	cout << "          |       \    "         << endl;
	cout << "          |       555555       " << endl;
	cout << "          |        /"            << endl;
	cout << "       333333    444444     "    << endl;
	cout << "           \    /     "          << endl;
	cout << "           222222 "              << endl;
	cout << "                \__111111"       << endl;
}

Map_Separate::Map_Separate()
{
}

Map_Separate::Map_Separate(int num)
{
	dx = 0;
	dy = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			pos[i][j] = ' ';
		}
	}
	pos[dx][dy] = '*';

	switch (num)
	{
	case'1': {
		name = "��ͼ1";
		mapNum = 1;
		break;
	}
	case'2': {
		name = "��ͼ2";
		mapNum = 2;
		break;
	}
	case'3': {
		name = "��ͼ3";
		mapNum = 3;
		break;
	}
	case'4': {
		name = "��ͼ4";
		mapNum = 4;
		break;
	}
	case'5': {
		name = "��ͼ5";
		mapNum = 5;
		break;
	}
	case'6': {
		name = "��ͼ6";
		mapNum = 6;
		break;
	}
	case'7': {
		name = "��ͼ7";
		mapNum = 7;
		break;
	}
	case'8': {
		name = "��ͼ8";
		mapNum = 8;
		break;
	}
	case'9': {
		name = "��ͼ9";
		mapNum = 9;
		break;
	}
			
	default:
		break;
	}
}

Map_Separate::~Map_Separate()
{
}

void Map_Separate::ShowMap()
{
	printf(" _______________________________________\n");
	printf("|       |       |       |       |       |\n");
	printf("|   %c   |   %c   |   %c   |   %c   |   %c   |\n", pos[0][0], pos[0][1], pos[0][2], pos[0][3], pos[0][4]);
	printf("|_______|_______|_______|_______|_______|\n");
	printf("|       |       |       |       |       |\n");
	printf("|   %c   |   %c   |   %c   |   %c   |   %c   |\n", pos[1][0], pos[1][1], pos[1][2], pos[1][3], pos[1][4]);
	printf("|_______|_______|_______|_______|_______|\n");
	printf("|       |       |       |       |       |\n");
	printf("|   %c   |   %c   |   %c   |   %c   |   %c   |\n", pos[2][0], pos[2][1], pos[2][2], pos[2][3], pos[2][4]);
	printf("|_______|_______|_______|_______|_______|\n");
	printf("|       |       |       |       |       |\n");
	printf("|   %c   |   %c   |   %c   |   %c   |   %c   |\n", pos[3][0], pos[3][1], pos[3][2], pos[3][3], pos[3][4]);
	printf("|_______|_______|_______|_______|_______|\n");
	printf("|       |       |       |       |       |\n");
	printf("|   %c   |   %c   |   %c   |   %c   |   %c   |\n", pos[4][0], pos[4][1], pos[4][2], pos[4][3], pos[4][4]);
	printf("|_______|_______|_______|_______|_______|\n");
}

void Map_Separate::Move(char order)
{
	pos[dx][dy] = ' ';
	switch (order)
	{
		case 'w': {
			if (dx > 0) {
				dx--;
			}
			else
			{
				cout << "�ƶ�ʧ��" << endl;
			}
			break;
		}
		case 'a': {
			if (dy > 0) {
				dy--;
			}
			else
			{
				cout << "�ƶ�ʧ��" << endl;
			}
			break;
		}
		case 's': {
			if (dx < 4) {
				dx++;
			}
			else
			{
				cout << "�ƶ�ʧ��" << endl;
			}
			break;
		}
		case 'd': {
			if (dy < 4) {
				dy++;
			}
			else
			{
				cout << "�ƶ�ʧ��" << endl;
			}
			break;
		}
		default:
			break;
	}
	pos[dx][dy] = '*';
}