#ifndef NPC_CPP
#define NPC_CPP
#include"Npc.h"
#include<iostream>
using namespace std;

Npc::Npc() {
}
/*
string Npc::getName(int whichNpc) {
	return name[whichNpc];
}
*/
void Npc::chat(int whichNpc) {
	if (whichNpc == 1)
		cout << "嗨，我是火行者，你可以从我这里得到火灵珠，但是你必须去打败绯红树怪。" << endl;
	if (whichNpc == 2)
		cout << "ﾞ嗨，我是木行者，你可以从我这里得到木灵珠，但是你必须去打败苍老魔像。" << endl;
	if (whichNpc == 3)
		cout << "嗨，我是水行者，你可以从我这里得到水灵珠，但是你必须去打败深红蜂啄鸟。" << endl;
	if (whichNpc == 4)
		cout << "嗨，我是金行者，你可以从我这里得到金灵珠，但是你必须去打败炼狱巨龙。" << endl;
	if (whichNpc == 5)
		cout << "嗨，我是土行者，你可以从我这里得到土灵珠，但是你必须去打败霸龙纳什男爵。" << endl;
	if (whichNpc == 6)
		cout << "嘿嘿嘿......" << endl;
}

int Npc::getGoods(int whichNpc) {
	if (whichNpc == 1)
		return goodsId[0];
	if (whichNpc == 2)
		return goodsId[1];
	if (whichNpc == 3)
		return goodsId[2];
	if (whichNpc == 4)
		return goodsId[3];
	if (whichNpc == 5)
		return goodsId[4];
	if (whichNpc == 5)
		return goodsId[5];
	return 0;
}
int Npc::getMoney(int whichNpc) {
	if (whichNpc == 1)
		return money[0];
	if (whichNpc == 2)
		return money[1];
	if (whichNpc == 3)
		return money[2];
	if (whichNpc == 4)
		return money[3];
	if (whichNpc == 5)
		return money[4];
	if (whichNpc == 5)
		return money[5];

}
bool Npc::isChatted(int whichNpc) {
	if (whichNpc == 1)
		return true;
	if (whichNpc == 2)
		return true;
	if (whichNpc == 3)
		return true;
	if (whichNpc == 4)
		return true;
	if (whichNpc == 5)
		return true;
	if (whichNpc == 5)
		return false;
}

#endif