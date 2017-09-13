﻿#ifndef STORE_H
#define STORE_H

#include <iostream>  
#include <map>  
#include "Goods.h"
#include "Bag.h"
#include "Role.h"

using namespace std;

class Store {
public:
	Store();
	~Store();

	void showStores();
	Bag storeToPlayer(Role &player, Bag &bags);		//返回一个已经操作过的Role对象
	Bag playerToStore(Role &player, Bag &bags);
	
private:
	map<int, int> stores;

	//物品实例化
	Goods goods[24] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23 };
};
#endif