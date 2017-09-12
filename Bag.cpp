#include "Bag.h"
#include<iostream>
#include<iomanip>
using namespace std;

Bag::Bag(){}

Bag::~Bag(){}

void Bag::showBags()
{
	if (bags.begin() == bags.end())
		cout << "当前背包无物品！" << endl;
	else {
		cout << "当前背包:" << endl;
		cout << "物品ID  物品名称      数量" << endl;
		map<int, int>::iterator iter;
		for (iter = bags.begin(); iter != bags.end(); ++iter)
		{
			cout <<setw(2)<< goods[iter->first].getGoodsId()<< setw(10)<< goods[iter->first].getName() <<setw(3)<< iter->second << endl;
		}
	}
}

void Bag::showGoods(int* goodsId,int* num){
	
	for (int i = 0;goodsId[i] >= 0;i++)
		cout <<i+1<<"."<<setw(10)<<left<< goods[goodsId[i]].getName() << num[i] << "件"<<endl;
	cout << endl;
}

void Bag::showGoods(int goodsId, int num) {
	cout << 1 << "." << setw(10) << left << goods[goodsId].getName() << num << "件" << endl;
	cout << endl;
}

void Bag::addGoods(int id, int num){
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

void Bag::operator=(Bag bag){
	bags = bag.getMapBags();
}

map<int, int> Bag::getMapBags()
{
	return bags;
}

int Bag::getGoodsNum() {  //返回背包里物品的数量
	return bags.size();
}