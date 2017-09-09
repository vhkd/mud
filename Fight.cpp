#include "Fight.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

Fight::~Fight()
{
}

//每回合战斗
bool Fight::fightRound() {
	cout << "请选择：1，普通攻击 2，使用技能 3，逃跑" << endl;
	int choices = 0;
	while (true) {
		cin >> choices;
		if (choices != 1 && choices != 2 && choices != 3)
			cout << "选择错误，请重新选择。" << endl;
		else break;
	}

	if (choices == 1) {
		hurt = player.getAttack() - enemy.getDefend();
		cout << "你对" << enemy.getName() << "造成了" << hurt << "的普通伤害。" << endl;
		enemy.setHealth(enemy.getHealth() - hurt);
		enemyFight();		//怪物攻击
		showFight();
	}
	if (choices == 2) {
		hurt = player.useSkill() * player.getAttack() - enemy.getDefend();
		cout << enemy.getName() << "造成了" << hurt << "的技能伤害。" << endl;
		enemy.setHealth(enemy.getHealth() - hurt);
		enemyFight();  //怪物攻击
		showFight();
	}
	if (choices == 3) {
		srand((unsigned)time(NULL));
		if (rand() % 100 <= 50) {			//一半的可能性成功
			cout << "逃跑失败" << endl;
			return false;
		}
		else {
			cout << "逃跑成功" << endl;
			return true;	//跳转至战斗逃跑结束，没有获得增益
		}
	}
	return false;				//战斗未逃跑
	round++;		//回合数加一
}

//显示战斗的状态
void Fight::showFight() {
	//system("cls")
	player.showRole();
	cout << endl;
	enemy.showEnemy();
	cout << endl << "当前为第" << round << "回合" << endl;
}

//怪物的随机战斗
void Fight::enemyFight() {
	srand((unsigned)time(NULL));
	if (rand() % 100 <= 50) {
		hurt = enemy.getAttack() - player.getDefend();
		player.setHealth(player.getHealth() - hurt);
		cout << enemy.getName() << "对你造成了" << hurt << "的普通伤害" << endl;
	}
	else player.setHealth(player.getHealth() - enemy.useSkill()); //使用技能并造成伤害
}
/*
//使用技能
void Fight::useSkill(){  //待定
cout<<"你对"<<enemy.getName()<<"造成了"<<##<<"的技能伤害。"<<endl;
cout<<enemy.getName()<<"对你造成了"<<##<<"的技能伤害"<<endl;
}
*/


//判断战斗的结束
bool Fight::isFightEnd() { //判断战斗是否结束
	if (player.getHealth() <= 0) {
		cout << "你已死亡，游戏结束。" << endl;
		GameEnd();		//跳转到程序结束
	}
	if (enemy.getHealth() <= 0) {
		cout << enemy.getName() << "已死亡，战斗结束" << endl;
		endFight();		//跳转到战斗正常结束，获得增益
		return true;
	}
	else return false;
}

//游戏结束
void Fight::GameEnd() {   //不必放在这
	cout << "人在江湖，身不由己，少侠，不要气馁，重新来过。" << endl;

//	......;//结束游戏或者......你懂的
	exit(0);		//程序结束
}

//结束战斗
void Fight::endFight() {  //结束战斗
	addMoney(enemy.getMoney());
	addExp(enemy.getExp());
	addGoods(enemy.getGoodsId());
}

void Fight::addMoney(int addMoney) { //增加金钱
	player.setMoney(player.getMoney() + addMoney);
}

void Fight::addGoods(int addGoodsId) {  //增加物品
	player.setBag(addGoodsId);		//setBag函数来判断是否能放入
}

void Fight::addExp(int addExp) {  //增加经验
	player.setExp(player.getExp() + addExp);

}

/*
void Fight::addExp(Role player,int addExp){ //增加经验值
player.addExp(addExp);
if(player.getExp() >= player.getExp_MAX()){
player.setExp(player.getExp() - player.getExp_MAX());
player.addLevel();
}
}
*/

void Fight::recoverHp(Goods goods) { //消耗物品回复生命值
	player.setHealth(player.getHealth() + goods.getAddHP());
}

void Fight::recoverMp(Goods goods) {//消耗物品回复法力值
	player.setMagic(player.getMagic() + goods.getAddMP());
}