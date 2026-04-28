#ifndef ENEMY_H
#define ENEMY_H

#include <string>

using namespace std;

class Enemy {

public:
	Enemy();
	~Enemy();
	string getName() const;
	void setType(int whattype);
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


	int* getGoodsId();		//掉落物品
	const int* getGoodsId() const;
	int* getGoodsNum();		//掉落物品数量
	const int* getGoodsNum() const;
	int getExp() const;			//增加经验
	int getMoney() const;			//增加金钱

	double useSkill() const;	//怪物使用技能，返回伤害数值

	void showEnemy() const;

protected:
	string name;
	int type;
	int health_max;
	int health;
	int magic_max;
	int magic;
	int attack;
	int defend;

	int goodsId[4]; //打死怪物会掉落的物品
	int goodsNum[4];//打死怪物会掉落的物品数量
	int exp;  //打死怪物增加的经验
	int money;  //打死怪物增加的金钱
};

class Enemy_Small {	//小怪
public:
	Enemy_Small();
	~Enemy_Small();
private:
	int health;
	int attack;
};

class Enemy_Boss :public Enemy { //大怪
public:
	Enemy_Boss();
	Enemy_Boss(int type);
	~Enemy_Boss() {};

};
#endif
