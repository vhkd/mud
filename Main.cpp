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
#include "Save.h"
#include "Read.h"

using namespace std;

//强制界面全屏
/*
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
*/
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
	cout << "    鸿蒙开化之初，中州大陆昆仑之巅的鸿钧上人创立道教，并收徒三人，各授以道门绝技，三徒皆修成混元大罗金仙万劫不坏之体，分别发展出道教的人道、阐教和截教三个分支。此三徒正是人道教主太上老君、阐教教主元始天尊和截教的通天教主。" << endl;
	cout << endl;
	system("pause");
	system("cls");
	cout << "    三教主秉承师父鸿钧上人教诲，广收门徒将道教流传于世。只因入道门中即可修仙，使人跳出三界之外，不在五行之中，免除生死轮回之苦，使得入道修行之人多不胜数！但修仙之道并非苦心修炼便可达成。修行路上，均要经历三百年一小劫，一千五百年一大劫的劫数。修行之人均无法避开劫数，只能根据自身道行的深浅去经历劫数。" << endl;
	system("pause");
	system("cls");
	cout << "    值商周两朝交替之时，恰逢修仙一千五百年仙劫，于是三教主共议封神榜，以观众仙道行浅深。然劫数难逃，封神一役，致使道门内部阐教和截教不和，修仙众人俱遭屠戮，更引来西方教派参与纷争，后因鸿钧上人亲自出面调停，终得以平息。" << endl;
	system("pause");
	system("cls");
	cout << "    五百年后的中洲大陆，故事就发生在一个平凡冷清的小镇上。" << endl;
	system("pause");
	system("cls");

	return 0;
}

int main(){
	//FullScreen();
	welcomePage();
	int choice;
	cin >> choice;
	if(choice == 1) {
		playGame();

		//人物创建
		int choiceRole;
		system("cls");
		cout << "职业简介: " << endl << 
				"1.人道" << endl << "认为“道”是宇宙万物的本原和主宰，无所不在，无所不包，万物都是从“道”演化而来的。"<< endl <<
				"2.阐教" << endl << "阐者，明也。阐教主张崇尚自然，提倡道法自然，无所不容，自然无为，与自然和谐相处。" << endl << 
				"3.截教" << endl << "主张上道无德，下道唯德。大道五十衍四十九为定数，一线生机遁去，截教的教义正是截取这一线生机，演变六道。" << endl;
		cout << endl << "请输入要创建的职业" << endl;
		cin >> choiceRole;
		Role player(choiceRole);
		system("cls");
		cout << "创建成功" << endl;
		player.showRole();


		Goods goods[24] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23 };

		Map map;


	menu:


		cout << "位于 :" << map.getName() << endl;
		player.showRole();
		cout << endl << "1.交谈 2.战斗 3.移动 4.状态 5.存档并退出" << endl;
		int choice;
		cin >> choice;
		if (choice == 1) {
			if (map.isThereChat()) {
				Npc npc(map.getPosition());
				cout << endl << "请输入要对话的人物:" << endl << "1.商店" << endl;
				cout << "2." << npc.getName() << endl;
				int order;
				cin >> order;
				if (order == 1) {
					Store store;
					int order;
					cout << "1. 购买物品 2.卖出物品" << endl;
					cin >> order;
					if (order == 1) {
						store.showStores();
						store.storeToPlayer(player, player.bags);
					}
					else if (order == 2)
					{
						player.bags.showBags();
						store.playerToStore(player, player.bags);
					}
				}
				else if (order == 2) {
					npc.chat(player);
					player.setStory(player.getStory() + 1);
					player.bags.addGoods(npc.getGoodId(), npc.getGoodNum());
					cout << endl << "获得物品:" << goods[npc.getGoodId()].getName() << " * " << npc.getGoodNum() << endl <<endl;
				}
			}
			else {
				cout << "这里没人可以交谈" << endl;
			}
		}
		else if (choice == 2) {
			if (map.isThereFight()) {
				Enemy_Boss  boss(map.getPosition());
				boss.showEnemy();
				Fight fight(player, boss);
				system("cls");
				while (!fight.isFightEnd()) {
					fight.fightRound();
				}
				player = fight.endFight();		//战斗正常结束，获得增益
				boss.setDeathNum();
			}
			else
			{
				cout << "这里没有战斗可以发生" << endl;
			}
		}
		else if (choice == 3) {
			while (true)
			{
				map.ShowMap();
				cout << "使用w a s d来移动 按1进入地图" << endl;
				char order;
				cin >> order;
				if (order == '1') break;
				else map.Move(order);

			}

		}
		else if (choice == 4) {
			cout << "1.属性 2.背包 3.技能 4.返回"<<endl;
			int choice;
			cin >> choice;
			if (choice == 1) player.showRole();
			else if (choice == 2) player.bags.showBags();
			else if (choice == 3) player.showSkill();//显示技能
			else if (choice == 4) goto menu;
		}
		else if (choice == 5) {
			Save save(player);
			exit(0);
		}
		goto menu;

	}
	else if (choice == 2){
		//读取存档
		
		Read readFile(0);
		Role player = readFile.getRole();
		if (player.getType() == 0)
			cout << "请重新选择。" << endl;
		
		Goods goods[24] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23 };

		Map map;

	}
	else if(choice == 3){
		exit(0);
	}
	//cout << "test" << endl;
}