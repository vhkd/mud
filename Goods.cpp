#include "Goods.h"

Goods::Goods(int id)
{
	switch (id)
	{
	case '0': {
		goodsId = id;
		name = "��";
		desc = "ɽ���Է���������ĵ�,�����ֲ�,��ǿ������������";
		type = 0;
		addAttack = 10;
		priceBuy = 20;
		priceSell = 10;
		break;
	}
	case '1': {
		goodsId = id;
		name = "���ֽ�";
		desc = "���Ϻ�����������һ�����ε�ʵ���ͱ���,���߽����ر�";
		type = 0;
		addAttack = 20;
		priceBuy = 40;
		priceSell = 20;
		break;
	}
	case '2': {
		goodsId = id;
		name = "������";
		desc = "��˵���������������ù��Ľ�,��ʵ�����޴ӿ���";
		type = 0;
		addAttack = 30;
		priceBuy = 60;
		priceSell = 30;
		break;
	}
	case '3': {
		goodsId = id;
		name = "��ݽ�";
		desc = "�񱳿��еľ�ݵ�,��������ƻƽ����";
		type = 0;
		addAttack = 40;
		priceBuy = 80;
		priceSell = 40;
		break;
	}
	case '4': {
		goodsId = id;
		name = "���ӽ�";
		desc = "���ʹ���,������ֱ,����ʱ��׺����,�ƽ��о��Ӷ�����";
		type = 0;
		addAttack = 50;
		priceBuy = 100;
		priceSell = 50;
		break;
	}
	case '10': {
		goodsId = id;
		name = "�಼��";
		desc = "��ͨ�˼����������ķ���,��������ö�����ͨ";
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
		name = "���ּ�";
		desc = "ʹ�þ������ƵĿ���,�ܹ���Ч���������˺�";
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
		name = "������";
		desc = "����˿�������׿�׺�ϳ���״,ÿ�������ĸ������׿�,��������";
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
		name = "����ս��";
		desc = "���������͸��ˮ��,ʵ����ȴ����ǧ�겻������ɽ�����Ƴ�,�ǳ����";
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
		name = "��˿��⬼�";
		desc = "�ý�˿��ǧ����֦��ϱ�֯����,�����ҵ�ǹ����,��һ���ѵõ��䱦";
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
		name = "��ҩ";
		desc = "����������ҩ,����������Ѫ";
		type = 2;
		addHP = 30;
		priceBuy = 10;
		priceSell = 5;
		break;
	}
	case '21': {
		goodsId = id;
		name = "С����";
		desc = "ɢ������������ɫҩ��,���������Ѫ";
		type = 2;
		addHP = 60;
		priceBuy = 20;
		priceSell = 10;
		break;
	}
	case '22': {
		goodsId = id;
		name = "������";
		desc = "����ҩ�ﾫ�����ɵĵ�ҩ,������������";
		type = 2;
		addMP = 30;
		priceBuy = 10;
		priceSell = 5;
		break;
	}
	case '23': {
		goodsId = id;
		name = "��ˮ��Ԫ��";
		desc = "����Ũ��������ҩ��,�����������";
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
	if (type == 0) //����
	{
		cout << "������:" << addAttack << endl;
	}
	if (type == 1) //����
	{
		cout << "������:" << addDefend << endl;
		cout << "������Ѫ:" << addMaxHP << endl;
		cout << "��������:" << addMaxMP << endl;
	}
	if (type == 3) //ҩƷ
	{
		cout << "�ظ���Ѫ:" << addHP << endl;
		cout << "�ظ�����:" << addMP << endl;
	}
}
