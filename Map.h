#ifndef MAP_H
#define MAP_H

#include <string>
#include <cstdio>
#include "Enemy.h"
#include "Npc.h"

using namespace std;

class Map
{
public:
	Map();//初始位置为地图0
	Map(int pos); //由参数pos为所在位置
	~Map();
	void ShowMap();			//显示大地图
	void showRoom();		//显示身处的地方的信息，（有什么人可以交谈或者战斗）
	void Store();
	void Move(char order);
	bool isThereChat();
	bool isThereFight();
	int getPosition();

	string getName();

private:
	string name;
	int position; //当前位置
	string mapName[9] = { "地图0","地图1","地图2","地图3","地图4","地图5","地图6","地图7","地图8" };
	int mapNum;
	char pos[6][6];
	int dx;
	int dy;
	//Npc npc;
};

#endif