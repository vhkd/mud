#ifndef NPC_H
#define NPC_H

#include "Role.h"

class Npc
{
public:
	Npc();
	Npc(int num);
	~Npc();

	void chat();
	void getEquip();
	void getMoney(Role player);
	bool isChatted();
	
private:
	char name[20];
	
};

#endif