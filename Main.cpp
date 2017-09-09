#include <iostream>
#include <Windows.h>
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

//强制界面全屏
void FullScreen() {
	HWND hwnd = GetForegroundWindow();
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);
	char setting[30];
	sprintf_s(setting, "mode con:cols=%d lines=%d", x, y);
	system(setting);
	SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, x, y, NULL);
	MoveWindow(hwnd, 0, 0, x, y, 1);
	printf("\n\n");
}

int welcomePage()
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 13);
	cout << "*" << endl;
	cout << "*" << endl;
	cout << "*" << endl;
	cout << "*" << endl;
	cout << "*" << endl;
	cout << "*" << endl;
	cout << "*" << endl;
	cout << "*" << endl;
	cout << "*                       title " << endl;
	cout << "*" << endl;
	cout << "*" << endl;
	cout << "*" << endl;
	cout << "*" << endl; 
	cout << "*" << endl;
	cout << "*" << endl;
	cout << "*" << endl;
	cout << " " << endl;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	cout << "1.新的游戏  2.读取存档  3.退出游戏" << endl << endl;

	return 0;
}

int playGame()
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	system("cls");
	cout << "故事背景" << endl << endl;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	cout << "这是一句剧情" << endl;
	cout << endl;
	system("pause");
	system("cls");
	cout << "这是另一句剧情" << endl;
	system("pause");
	system("cls");
	cout << "这又是一句剧情" << endl;
	system("pause");
	system("cls");

	return 0;
}

int main()
{
	FullScreen();
	welcomePage();
	int choice;
	cin >> choice;
	if(choice == 1) {			
		//人物创建
		int choiceRole;
		cout << "请输入要创建的职业 1...  2...  3..." << endl;
		cin >> choiceRole;
		Role player(choiceRole);
		system("cls");
		cout << "创建成功" << endl;
		player.showRole();

		Bag bags;

		Map map;//世界地图
		//Map_Separate map[9] = { 1,2,3,4,5,6,7,8,9 };//小地图

		playGame();

	menu:
		cout << "位于 :" << map.getName() << endl;
		player.showRole();
		cout << endl << "1.交谈 2.战斗 3.移动 4.状态" << endl;
		int choice;
		cin >> choice;
		if (choice == 1) {

		}
		else if (choice == 2) {

		}
		else if (choice == 3) {
			while (true)
			{
				map.ShowMap();
				cout << "使用WASD来移动 按1进入地图" << endl;
				char order;
				cin >> order;
				if (order == '1') break;
				else map.Move(order);
			}
		}
		else if (choice == 4) {
			cout << "1.属性 2.背包 3.技能 4.返回";
			int choice;
			cin >> choice;
			if (choice == 1) player.showRole();
			else if (choice == 2) bags.showBags();
			else if (choice == 3) player.showSkill();//显示技能
			else if (choice == 4) goto menu;
		}

		goto menu;

	}
	else if (choice == 2)
	{
		//读取存档
	}
	else if(choice == 3)
	{
		exit(0);
	}

	//cout << "test" << endl;
}