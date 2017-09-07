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
};

#endif 