#include "Npc.h"

class Map
{
public:
	void ShowMap();
	void Store();
	void Story(int mapNum);
	
	
private:	
	char name[20];
	int mapNum;
};