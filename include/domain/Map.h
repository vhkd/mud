#ifndef MAP_H
#define MAP_H

#include <string>

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

	string getNpcName();		//得到当前npc名字
	string getName();

private:
	string name;
	int position; //当前位置
	string mapName[10] = { "平江镇","官道","岳州城","西郊","五龙山","地宫","东郊","轩辕庙","十里坡","昆仑" };
	int mapNum;
	char pos[6][6];
	int dx;
	int dy;
	string npcNames[10] = { "雪蝶", "", "云中子", "", "广法天尊", "接引道人", "", "玉鼎真人", "", "元始天尊" };
};

#endif
