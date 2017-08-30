#include <iostream>  
#include <map>  
#include "Goods.h"
#include "Bag.h"
#include "Role.h"

class Store {
public:
	Store();
	~Store();

	showStores();
	storeToPlayer(Role player, Bag bag);
	playerToStore(Role player, Bag bag);
	
private:
	map<Goods.goodsId,int> stores;
}

Store::Store(){
	map<Goods.goodsId id,int num> stores;
}