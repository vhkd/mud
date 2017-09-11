#include "Bag.h"
#include<iostream>
using namespace std;

Bag::Bag(){}

Bag::~Bag(){}

void Bag::showBags()
{
	cout << "当前背包:" << endl;
	cout << "物品ID  物品名称      数量" << endl;
	map<int, int>::iterator iter;
	for (iter = bags.begin(); iter != bags.end(); ++iter)
	{
		cout << goods[iter->first].getGoodsId() <<"      " << goods[iter->first].getName() << "            " << iter->second << endl;
	}
}

void Bag::addGoods(int id, int num)
{
	if(bags.count(id))
	{
		bags[id] += num;
	}
	else
	{
		bags.insert(pair<int, int>(id, num));
	}
}

void Bag::reduceGoods(int id, int num)
{
	bags[id] -= num;
	if (bags[id] <= 0)
	{
		bags.erase(id);
	}
}

int Bag::getGoodsNum() {  //返回背包里物品的数量
	return bags.size();
}