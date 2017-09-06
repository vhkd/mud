class Goods
{
public:
	Goods(int id);
	~Goods();

	char* getName();
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
	char name[20];	//物品名称
	int goodsId;
	char desc[256];	//物品描述
	int type;//物品属性：武器-0，装备-1，药品-2
	int addAttack = 0;	//增加攻击
	int addDefend = 0;	//增加防御
	int addHP = 0;		//增加Hp
	int addMaxHP = 0;	//增加max HP
	int addMP = 0;		//增加Mp
	int addMaxMP = 0;	//增加max MP
	int priceSell;
	int priceBuy;		
};

Goods goods[20];//构造对象数组