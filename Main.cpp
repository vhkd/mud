#include <iostream>
#include "Bag.h"
#include "Enemy.h"
#include "Fight.h"
#include "Goods.h"
#include "Map.h"
#include "Npc.h"
#include "Role.h"
#include "Skill.h"
#include "Store.h"

using namespace std;

int initGame() 
{
	//人物创建
	int choiceRole;
	cout << "请输入要创建的职业 1...  2...  3..." << endl;
	cin >> choiceRole;
	Role player(choiceRole);
	cout << "创建成功" << endl;

	Bag bags;

	Map_Total map_total;//世界地图
	Map_Separate map[9] = {1,2,3,4,5,6,7,8,9};//小地图
}

int main()
{
	cout << "1.新的游戏  2.读取存档  3.退出游戏" << endl;
	int choice;
	switch (choice)
	{
	case '1':{
		initGame();
		break;
	}
	case '2': {
		//读取存档
		break;
	}
	case '3': {
		break;
	}
	default:
		break;
	}
}