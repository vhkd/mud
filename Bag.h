#ifndef BAG_H
#define BAG_H

#include <iostream>  
#include <map>  
#include "Goods.h"
#include "Role.h"

using namespace std;

class Bag {
public:
	Bag();
	~Bag();

	void showBags();
	void addGoods(int id, int num);
	void reduceGoods(int id, int num);
	
private:
	map<int,int> bags;
	//物品实例化
	Goods goods[24] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23 };
};

#endif 