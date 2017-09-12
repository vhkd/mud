#ifndef NPC_H
#define NPC_H
#include<string>
#include"Role.h"

class Npc{
public:
	Npc(int num);
	~Npc();

	string getName();
	void chat(Role player);
	int getGoodId();
	int getGoodNum();
	int getMoney();
	bool isChatted(int whichNpc);
	
private:
	string name;
	int type;
	int goodId;
	int goodNum;
	int money;
	//const string name[6] = { "火行者","木行者","水行者","金行者","土行者","上帝" };
	//const int goodsId[6] = { 1,4,9,12,16,25 };		//6个Npc能给的物品
	//const int money[6] = { 25,34,49,52,66,75 };		//6个Npc能给的金钱
};

#endif