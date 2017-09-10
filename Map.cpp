#include <iostream>
#include "Map.h"


using namespace std;

Map::Map()
{
	position = 0;
	dx = 5;
	dy = 2;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			pos[i][j] = ' ';
		}
	}
	pos[dx][dy] = '*';
}

Map::Map(int p)
{
	position = p;
	switch (p)
	{
	case'0': {
		dx = 5;
		dy = 2;
		break;
	}
	case'1': {
		dx = 4;
		dy = 2;
		break;
	}
	case'2':{
		dx = 3;
		dy = 2;
		break;
	}
	case'3': {
		dx = 3;
		dy = 1;
		break;
	}
	case'4': {
		dx = 2;
		dy = 1;
		break;
	}
	case'5': {
		dx = 2;
		dy = 0;
		break;
	}
	case'6': {
		dx = 3;
		dy = 3;
		break;
	}
	case'7': {
		dx = 2;
		dy = 3;
		break;
	}
	case'8': {
		dx = 1;
		dy = 3;
		break;
	}
	case'9': {
		dx = 0;
		dy = 3;
		break;
	}
	default:
		break;
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			pos[i][j] = ' ';
		}
	}
	pos[dx][dy] = '*';
}

Map::~Map()
{
}

void Map::Store()
{
}


void Map::ShowMap()
{
	system("cls");
	cout << "世界地图:" << endl;
	printf("                                  __________\n");
	printf("                                 |          |\n");
	printf("                                 |          |\n");
	printf("                                 |  地图9   |\n");
	printf("                                 |    %c     |\n", pos[0][3]);
	printf("                                 |          |\n");
	printf("                                 |__________|\n");
	printf("                                 |          |\n");
	printf("                                 |          |\n");
	printf("                                 |  地图8   |\n");
	printf("                                 |    %c     |\n", pos[1][3]);
	printf("                                 |          |\n");
	printf("___________ __________           |__________|\n");
	printf("|          |          |          |          |\n");
	printf("|          |          |          |          |\n");
	printf("|  地图5   |  地图4   |          |  地图7   |\n");
	printf("|    %c     |    %c     |          |    %c     |\n", pos[2][0], pos[2][1], pos[2][3]);
	printf("|          |          |          |          |\n");
	printf("|__________|__________|__________|__________|\n");
	printf("           |          |          |          |\n");
	printf("           |          |          |          |\n");
	printf("           |  地图3   |  地图2   |  地图6   |\n");
	printf("           |     %c    |    %c     |    %c     |\n", pos[3][1], pos[3][2], pos[3][3]);
	printf("           |          |          |          |\n");
	printf("           |__________|__________|__________|\n");
	printf("                      |          |\n");
	printf("                      |          |\n");
	printf("                      |  地图1   |\n");
	printf("                      |    %c     |\n", pos[4][2]);
	printf("                      |          |\n");
	printf("                      |__________|\n");
	printf("                      |          |\n");
	printf("                      |          |\n");
	printf("                      |  地图0   |\n");
	printf("                      |    %c     |\n", pos[5][2]);
	printf("                      |          |\n");
	printf("                      |__________|\n");
	cout << "您现在的位置为" << mapName[position] << endl;
}

void Map::showRoom() {
	if (isThereChat()) {
		cout << "这里有：";
	//	cout <<npc.getName(position) <<'\t';
	}
}

void Map::Move(char order)
{
	pos[dx][dy] = ' ';
	switch (order)
	{
		case 'w': {
			if (position == 0 || position == 1 || position == 3 || position == 6 || position == 7 || position == 8) {
				dx--;
				position++;
			}
			else
			{
				cout << "移动失败" << endl;
			}
			break;
		}
		case 'a': {
			if (position == 2 || position == 4 ) {
				dy--;
				position++;
			}
			else if (position == 6)
			{
				dy--;
				position = 2;
			}
			else
			{
				cout << "移动失败" << endl;
			}
			break;
		}
		case 's': {
			if (position == 1 || position == 2 || position == 4 || position == 7 || position == 8 || position == 9) {
				dx++;
				position--;
			}
			else
			{
				cout << "移动失败" << endl;
			}
			break;
		}
		case 'd': {
			if (position == 3 || position == 5 ){
				dy++;
				position--;
			}
			else if (position == 2)
			{
				dy++;
				position = 6;
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
	showRoom();
}

bool Map::isThereChat()
{
	if (position == 0 || position == 2 || position == 8 )
		return true;
	else return false;
}

bool Map::isThereFight()
{
	if (position == 1 || position == 3 || position == 4 || position == 5 || position == 6 || position == 7 || position == 9)
		return true;
	else return false;
}

int Map::getPosition()
{
	return position;
}

string Map::getName()
{
	return mapName[position];
}
