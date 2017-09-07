#ifndef NPC_H
#define NPC_H

#include "Role.h"

class Npc
{
public:
	void chat();
	void getEquip();
	void getMoney(Role player);
	bool isChatted();
	
private:
	char name[20];
	
};

#endif