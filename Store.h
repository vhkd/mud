#include <iostream>  
#include <map>  
#include "Goods.h"
#include "Bag.h"
#include "Role.h"

class Store {
public:
	Store();
	~Store();

	void showStores();
	void storeToPlayer(Role player, Bag bag);
	void playerToStore(Role player, Bag bag);
	
private:
	//std::map<Goods.goodsId,int> stores;
};

Store::Store(){
	//std::map<Goods.goodsId id,int num> stores;
}