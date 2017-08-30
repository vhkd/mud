#include <iostream>  
#include <map>  
#include "Goods.h"
#include "Role.h"

class Bag {
public:
	Bag();
	~Bag();

	void showBags();
	void addGoods();
	void reduceGoods();
	
private:
	//map<Goods.goodsId,int> bags;
};

Bag::Bag(){
	//map<Goods.goodsId id,int num> bags;
}