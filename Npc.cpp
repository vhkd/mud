#ifndef NPC_CPP
#define NPC_CPP

#include <iostream>
#include "Npc.h"

using namespace std;

Npc::Npc() {
}
Npc::Npc(int num)
{
	type = num;
	switch (num)
	{
	case 0: {
		name = "镇长";
		goodId = 20;
		goodNum = 5;
		money = 20;
		break;
	}
	case 2: {
		name = "云中子";
		goodId = 1;
		goodNum = 1;
		money = 50;
		break;
	}
	case 4: {
		name = "广法天尊";
		goodId = 12;
		goodNum = 1;
		money = 100;
		break;
	}
	case 5: {
		name = "接引道人";
		goodId = 21;
		goodNum = 50;
		money = 200;
		break;
	}
	case 7: {
		name = "玉鼎真人";
		goodId = 6;
		goodNum = 1;
		money = 2000;
		break;
	}
	case 9: {
		name = "元始天尊";
		goodId = 9;
		goodNum = 1;
		money = 0;
		break;
	}

	default:
		break;
	}
}

Npc::~Npc()
{
}

string Npc::getName() {
	return name;
}

void Npc::chat(Role player) {
	switch (type)
	{
	case 0: {
		if (player.getStory() == 0) {
			cout << "镇长: 最近镇上不太安宁啊" << endl; 
			system("pause");
			cout << "你: 怎么了, 出什么事情了" << endl; 
			system("pause");
			cout << "镇长: 最近镇子北面的官道突然出现很多以前没有的野物, 厉害得很, 有些猎户都不是他们的对手, 让镇上的居民人心惶惶" << endl;
			system("pause");
			cout << "你: 这些野物这么猖狂? 让我会会它们, 顺便去岳州城里打探一下消息" << endl;
			system("pause");
			cout << "镇长: 那你一定要小心啊, 这些金疮药你拿着, 防备野物的伤害" << endl;
			system("pause");

		}
		break;
	}
	case 2: {
		if (player.getStory() == 0) {
			cout << "  " << endl;
			system("pause");
		}
		break;
	}
	case 4: {
		if (player.getStory() == 0) {
			cout << "  " << endl;
			system("pause");
		}
		break;
	}
	case 5: {
		if (player.getStory() == 0) {
			cout << "  " << endl;
			system("pause");
		}
		break;
	}
	case 7: {
		if (player.getStory() == 0) {
			cout << "  " << endl;
			system("pause");
		}
		break;
	}
	case 9: {
		if (player.getStory() == 0) {
			cout << "  " << endl;
			system("pause");
		}
		break;
	}
	default:
		break;
	}
}

int Npc::getGoodNum()
{
	return goodNum;
}

int Npc::getGoodId() {
	return goodId;
}

int Npc::getMoney() {
	return money;
}
#endif