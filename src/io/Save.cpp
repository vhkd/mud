#include "io/Save.h"

#include <fstream>
#include <iostream>

using namespace std;

bool Save::setToFile(const Role &player) {
	ofstream file("savegame.txt");
	if (!file) {
		cout << "无法打开存档文件。" << endl;
		return false;
	}

	file << player.getType() << ' '
		<< player.getHealth_max() << ' '
		<< player.getHealth() << ' '
		<< player.getMagic_max() << ' '
		<< player.getMagic() << ' '
		<< player.getAttack() << ' '
		<< player.getExp() << ' '
		<< player.getLevel() << ' '
		<< player.getDefend() << ' '
		<< player.getMoney() << ' '
		<< player.getMapId() << ' '
		<< player.getStory() << ' '
		<< player.getWeapon() << ' '
		<< player.getClothes() << '\n';

	const Skill skill = player.getSkill();
	file << skill.getLevel(1) << ' '
		<< skill.getLevel(2) << ' '
		<< skill.getLevel(3) << ' '
		<< skill.getLevel(4) << '\n';

	const Task task = player.getTask();
	file << task.getTaskId() << ' '
		<< task.getIsEnd() << ' '
		<< task.getGoods().getGoodsId() << '\n';

	const map<int, int> bagItems = player.getBag().getMapBags();
	file << bagItems.size() << '\n';
	for (const auto &item : bagItems) {
		file << item.first << ' ' << item.second << '\n';
	}

	cout << "保存成功。" << endl;
	return true;
}

bool Save::loadFromFile(Role &player) {
	ifstream file("savegame.txt");
	if (!file) {
		cout << "没有保存的游戏！" << endl;
		return false;
	}

	int type = 0;
	int healthMax = 0;
	int health = 0;
	int magicMax = 0;
	int magic = 0;
	int attack = 0;
	int exp = 0;
	int level = 0;
	int defend = 0;
	int money = 0;
	int mapId = 0;
	int story = 0;
	int weapon = -1;
	int clothes = -1;

	file >> type >> healthMax >> health >> magicMax >> magic >> attack >> exp >> level >> defend >> money >> mapId >> story >> weapon >> clothes;
	if (!file) {
		cout << "存档格式错误。" << endl;
		return false;
	}

	player = Role(type);
	player.setHealth_max(healthMax);
	player.setHealth(health);
	player.setMagic_max(magicMax);
	player.setMagic(magic);
	player.setAttack(attack);
	player.setExpSave(exp);
	player.setLevelSave(level);
	player.setDefend(defend);
	player.setMoney(money);
	player.setMapId(mapId);
	player.setStory(story);
	player.setWeapon(weapon);
	player.setClothes(clothes);
	player.newBag();

	Skill skill;
	for (int i = 1; i <= 4; i++) {
		int levelValue = 0;
		file >> levelValue;
		skill.setLevel(i, levelValue);
	}
	player.setSkill(skill);

	int taskId = 0;
	int taskIsEnd = 0;
	int taskGoodsId = 24;
	file >> taskId >> taskIsEnd >> taskGoodsId;
	if (taskId > 0) {
		Task task(taskId);
		player.setTask(task);
		if (taskIsEnd != 0) {
			player.setTaskIsEnd();
		}
		if (taskGoodsId >= 0 && taskGoodsId < 24) {
			player.setTaskGoods(Goods(taskGoodsId));
		}
	}

	int bagSize = 0;
	file >> bagSize;
	for (int i = 0; i < bagSize; i++) {
		int goodsId = 0;
		int goodsNum = 0;
		file >> goodsId >> goodsNum;
		player.addSaveGoodsToBag(goodsId, goodsNum);
	}

	cout << "读入成功！" << endl;
	return true;
}
