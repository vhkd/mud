#include "Goods.h"

Goods::Goods(int id)
{
	switch (id)
	{
	case '0': {
		goodsId = id;
		name = "柴刀";
		desc = "山林樵夫用来砍柴的刀,做工粗糙,勉强可以用作武器";
		type = 0;
		addAttack = 10;
		priceBuy = 20;
		priceSell = 10;
		break;
	}
	case '1': {
		goodsId = id;
		name = "精钢剑";
		desc = "用料和做工都上了一定档次的实用型兵器,行走江湖必备";
		type = 0;
		addAttack = 20;
		priceBuy = 40;
		priceSell = 20;
		break;
	}
	case '2': {
		goodsId = id;
		name = "霸王剑";
		desc = "传说中西楚霸王项羽用过的剑,真实性已无从考据";
		type = 0;
		addAttack = 30;
		priceBuy = 60;
		priceSell = 30;
		break;
	}
	case '3': {
		goodsId = id;
		name = "锯齿金刀";
		desc = "厚背宽刃的锯齿刀,金光闪闪似黄金打造";
		type = 0;
		addAttack = 40;
		priceBuy = 80;
		priceSell = 40;
		break;
	}
	case '4': {
		goodsId = id;
		name = "君子剑";
		desc = "剑鞘古朴,刃锐且直,出鞘时如白虹贯日,似剑中君子而得名";
		type = 0;
		addAttack = 50;
		priceBuy = 100;
		priceSell = 50;
		break;
	}
	case '10': {
		goodsId = id;
		name = "青布衣";
		desc = "普通人家男性所穿的服饰,面料与剪裁都很普通";
		type = 1;
		addDefend = 5;
		addMaxHP = 10;
		addMaxMP = 0;
		priceBuy = 20;
		priceSell = 10;
		break;
	}
	case '11': {
		goodsId = id;
		name = "精钢甲";
		desc = "使用精钢烧制的盔甲,能够有效降低外界的伤害";
		type = 1;
		addDefend = 10;
		addMaxHP = 20;
		addMaxMP = 10;
		priceBuy = 30;
		priceSell = 15;
		break;
	}
	case '12': {
		goodsId = id;
		name = "环锁铠";
		desc = "由铁丝或铁环套扣缀合成衣状,每环与另四个环相套扣,形如网锁";
		type = 1;
		addDefend = 20;
		addMaxHP = 30;
		addMaxMP = 30;
		priceBuy = 50;
		priceSell = 25;
		break;
	}
	case '13': {
		goodsId = id;
		name = "冰晶战衣";
		desc = "外表看来宛如透明水晶,实际上却是用千年不化的天山寒冰制成,非常珍贵";
		type = 1;
		addDefend = 30;
		addMaxHP = 40;
		addMaxMP = 40;
		priceBuy = 70;
		priceSell = 35;
		break;
	}
	case '14': {
		goodsId = id;
		name = "金丝软猬甲";
		desc = "用金丝和千年滕枝混合编织而成,柔软且刀枪不入,是一件难得的珍宝";
		type = 1;
		addDefend = 40;
		addMaxHP = 50;
		addMaxMP = 50;
		priceBuy = 90;
		priceSell = 45;
		break;
	}
	case '20': {
		goodsId = id;
		name = "金创药";
		desc = "常见的疗伤药,补充少量气血";
		type = 2;
		addHP = 30;
		priceBuy = 10;
		priceSell = 5;
		break;
	}
	case '21': {
		goodsId = id;
		name = "小还丹";
		desc = "散发着香气的紫色药丸,补充大量气血";
		type = 2;
		addHP = 60;
		priceBuy = 20;
		priceSell = 10;
		break;
	}
	case '22': {
		goodsId = id;
		name = "定神香";
		desc = "名贵药物精心炼成的丹药,补充少量内力";
		type = 2;
		addMP = 30;
		priceBuy = 10;
		priceSell = 5;
		break;
	}
	case '23': {
		goodsId = id;
		name = "风水混元丹";
		desc = "有着浓郁香气的药丸,补充大量内力";
		type = 2;
		addMP = 60;
		priceBuy = 20;
		priceSell = 10;
		break;
	}
	default:
		break;
	}
}

Goods::~Goods()
{
}



string Goods::getName()
{
	return string(name);
}

int Goods::getGoodsId()
{
	return goodsId;
}

string Goods::getDesc()
{
	return string(desc);
}



int Goods::getType()
{
	return type;
}

int Goods::getAddAttack()
{
	return addAttack;
}

int Goods::getAddDefend()
{
	return addDefend;
}

int Goods::getAddHP()
{
	return addHP;
}

int Goods::getAddMaxHP()
{
	return addMaxHP;
}

int Goods::getAddMP()
{
	return addMP;
}

int Goods::getAddMaxMP()
{
	return addMaxMP;
}

int Goods::getPriceSell()
{
	return priceSell;
}

int Goods::getPriceBuy()
{
	return priceBuy;
}

void Goods::showGoods()
{
	cout << name << endl;
	cout << desc << endl;
	if (type == 0) //武器
	{
		cout << "攻击力:" << addAttack << endl;
	}
	if (type == 1) //防具
	{
		cout << "防御力:" << addDefend << endl;
		cout << "增加气血:" << addMaxHP << endl;
		cout << "增加内力:" << addMaxMP << endl;
	}
	if (type == 3) //药品
	{
		cout << "回复气血:" << addHP << endl;
		cout << "回复内力:" << addMP << endl;
	}
}
