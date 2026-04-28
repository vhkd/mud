#ifndef ROLE_H
#define ROLE_H

#include <string>
#include "domain/Bag.h"
#include "domain/Goods.h"
#include "domain/Skill.h"
#include "domain/Task.h"
using namespace std;

class Role {
public:
	Role(int type);
	Role(const Role &player) = default;
	~Role();
	Role &operator=(const Role &player);

	string getName() const;
	int getType() const;

	int getHealth_max() const;
	void setHealth_max(int hp_m);

	int getHealth() const;
	void setHealth(int hp);

	int getMagic_max() const;
	void setMagic_max(int mp_m);

	int getMagic() const;
	void setMagic(int mp);

	int getAttack() const;
	void setAttack(int a);

	int getDefend() const;
	void setDefend(int d);

	int getExp() const;
	void setExp(int e);
	void setExpSave(int e);
	int getLevelExp_max(int whichLevel) const;

	int getLevel() const;
	void setLevel(int l);
	void setLevelSave(int l);

	int getMoney() const;
	void setMoney(int m);

	int getMapId() const;
	void setMapId(int NewMapId);

	int getStory() const;
	void setStory(int s);

	Skill getSkill() const;
	void setSkill(const Skill &newSkill);

	void addSaveGoodsToBag(int goodId,int num);

	Bag &getBag();
	const Bag &getBag() const;
	void showBag();
	int getBagWhichGoodsId(int whichGoods);			//得到背包里第whichGoods件物品
	int getBagWhichGoodsNum(int whichGoods);
	//显示背包
	void addGoodsToBag(int *goodsId, int* num);//加入背包,重载应对两种情况
	void addGoodsToBag(int goodsId, int num);

	bool subGoodsToBag(int goodsId, int num);	//减少背包里的物品

	void setBag(Bag bags);

	void savePlayerBag();		//用来单独保存背包
	//int** getBagSave();
	void newBag();

	void showRole() const;//人物属性 当前装备
	bool showSkill();//显示技能,返回是否可以使用技能

	double useSkill();		//使用技能,返回技能的攻击力加成
	void useDrug();			//使用药品

	int getWeapon() const;
	void setWeapon(int w);
	int getClothes() const;
	void setClothes(int c);

	void showEquip();//展示当前装备
	void wearEquip(int id);//穿上装备
	void removeEquip(int id);//脱下装备

	int getTaskId();
	bool getTaskIsEnd();
	void setTask(Task newTask);
	void setTaskIsEnd();
	Task getTask() const;
	string getTaskName();
	string getTaskDesc();
	Goods getTaskGoods();
	void setTaskGoods(Goods newTaskGoods);

private:
	string name;
	int type;
	int health_max;
	int health;
	int magic_max;
	int magic;
	int attack;
	int exp;
	//每个等级对应的最高经验值，经验值大于等于就升级
	const int levelExp_Max[29] = { 6,12,18,24,30,36,42,48,54,60,69,78,87,96,105,114,123,132,141,150,162,174,186,198,210,225,240,270,300 };
	int exp_Max;		//线性经验值，暂定为最高300
	int level;
	int defend;			//防御
	int money;
	Bag bag;			//背包
	//int bag[20];
	int mapId;			//记录玩家当前所在地
	Skill skill;		//他所拥有的技能
	int skillLevel;		//升级带来的技能升级点数
	int story = 0;//剧情节点
	int weapon = -1;//当前武器id  默认-1为无
	int clothes = -1; //当前防具id
	Task task;
				  //物品实例化
	Goods goods[24] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23 };

};
#endif
