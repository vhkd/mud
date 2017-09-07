#ifndef STORE_H
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
	void storeToPlayer(Role player, Bag bags);
	void playerToStore(Role player, Bag bags);
	
private:
	map<int, int> stores;
};
#endif