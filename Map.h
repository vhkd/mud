#ifndef MAP_H
#define MAP_H

#include <string>
#include <cstdio>
#include "Npc.h"

using namespace std;

class Map
{
public:
	Map();
	~Map();
	virtual void ShowMap();
	void Store();
	void Story(int mapNum);
	
	
protected:	
	string name;
};

class Map_Total : public Map
{
public:
	Map_Total();
	~Map_Total();

	void ShowMap();
};

class Map_Separate : public Map
{
public:
	Map_Separate();
	Map_Separate(int num);
	~Map_Separate();

	void ShowMap();
	void Move(char order);

private:
	int mapNum;
	char pos[5][5];
	int dx;
	int dy;
};

#endif