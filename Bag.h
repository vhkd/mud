#ifndef BAG_H
#define BAG_H
 
#include <map>  
#include "Goods.h"


class Bag {
public:
	Bag();
	~Bag();

	void showBags();
	void showGoods(int* goodsId,int* num);
	void showGoods(int goodsId, int num);	//重载应对两种情况
	int getGoodsNum();			//得到背包里物品的数量
	void addGoods(int id, int num);
	void reduceGoods(int id, int num);
	void operator=(Bag bag);
	map<int, int> getMapBags();

private:
	map<int,int> bags;
	int goodId[20][20];
	//物品实例化
	Goods goods[24] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23 };
};

#endif 