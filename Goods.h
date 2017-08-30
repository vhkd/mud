class Goods
{
public:
	string getName();
	int getGoodsId();
	char getDesc();
	int getType();
	int getAddAttack();
	int getAddDefend();	
	int getAddHP();		
	int getAddMaxHP();	
	int getAddMP();	
	int getAddMaxMP();	
	int getPriceSell();
	int getPriceBuy();
	void showGoods();
	
private:
	string name;	//物品名称
	int goodsId;
	char desc[256];	//物品描述
	int type;//物品属性：武器-0，装备-1，药品-2
	int addAttack;	//增加攻击
	int addDefend;	//增加防御
	int addHP;		//增加Hp
	int addMaxHP;	//增加max HP
	int addMP;		//增加Mp
	int addMaxMP;	//增加max MP

	int priceSell;
	int priceBuy;		
}
