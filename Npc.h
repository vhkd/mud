#ifndef NPC_H
#define NPC_H
#include <string>
#include "Role.h"

using namespace std;

class Npc
{
public:
	Npc();
	Npc(int num);
	~Npc();

	string getName();
	void chat(Role player);
	int getGoodId();
	int getGoodNum();
	int getMoney();
	
private:
	string name;
	int type;
	int goodId;
	int goodNum;
	int money;
};

#endif