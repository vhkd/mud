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
	cout << "世界地图:" << endl;
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
		name = "地图1";
		mapNum = 1;
		break;
	}
	case'2': {
		name = "地图2";
		mapNum = 2;
		break;
	}
	case'3': {
		name = "地图3";
		mapNum = 3;
		break;
	}
	case'4': {
		name = "地图4";
		mapNum = 4;
		break;
	}
	case'5': {
		name = "地图5";
		mapNum = 5;
		break;
	}
	case'6': {
		name = "地图6";
		mapNum = 6;
		break;
	}
	case'7': {
		name = "地图7";
		mapNum = 7;
		break;
	}
	case'8': {
		name = "地图8";
		mapNum = 8;
		break;
	}
	case'9': {
		name = "地图9";
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
				cout << "移动失败" << endl;
			}
			break;
		}
		case 'a': {
			if (dy > 0) {
				dy--;
			}
			else
			{
				cout << "移动失败" << endl;
			}
			break;
		}
		case 's': {
			if (dx < 4) {
				dx++;
			}
			else
			{
				cout << "移动失败" << endl;
			}
			break;
		}
		case 'd': {
			if (dy < 4) {
				dy++;
			}
			else
			{
				cout << "移动失败" << endl;
			}
			break;
		}
		default:
			break;
	}
	pos[dx][dy] = '*';
}