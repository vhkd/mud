#include "Enemy.h"
#include "Bag.h"

class Fight{

public:
	void round(Role player, Enemy enemy);//显示当前战斗
	void showFight(Role player, Enemy enemy);
	
	bool isFightEnd(Role player, Enemy enemy);//判断是否结束
	
	void addMoney(Role player, Enemy enemy);
	void addGoods(Role player, Enemy enemy);
	void addExp(Role player);
	
	void recoverHp(Role player, Goods goods);
	void recoverMp(Role player, Goods goods);
	
	void useSkill(Role player, Goods goods);
	
private:
	int round;//回合数
};