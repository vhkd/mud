#include "systems/BattleSystem.h"

#include <cstdlib>
#include <iostream>

#include "io/Console.h"
#include "domain/Goods.h"

using namespace std;

BattleSystem::BattleSystem() : rng(random_device{}()) {}

BattleOutcome BattleSystem::run(Role &player, Enemy enemy) {
	cout << "正在进入战斗......" << endl;
	int round = 1;

	while (!isBattleOver(player, enemy)) {
		Console::sleepMs(500);
		Console::clear();
		showStatus(player, enemy, round);

		if (handlePlayerTurn(player, enemy)) {
			return BattleOutcome::Escaped;
		}

		if (enemy.getHealth() <= 0) {
			break;
		}

		handleEnemyTurn(player, enemy);
		if (player.getHealth() <= 0) {
			cout << "你已力竭倒下，江湖路只得从头再来。" << endl;
			return BattleOutcome::Defeat;
		}

		round++;
	}

	applyVictoryRewards(player, enemy);
	return BattleOutcome::Victory;
}

int BattleSystem::readChoice(int min, int max) const {
	int choice = 0;
	while (true) {
		if ((cin >> choice) && choice >= min && choice <= max) {
			return choice;
		}
		if (cin.eof()) {
			std::exit(0);
		}
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "选择错误，请重新选择。" << endl;
	}
}

void BattleSystem::showStatus(const Role &player, const Enemy &enemy, int round) const {
	player.showRole();
	cout << endl;
	enemy.showEnemy();
	cout << endl << "当前为第 " << round << " 回合" << endl;
	cout << "请选择：1.普通攻击 2.使用技能 3.使用药品 4.逃跑" << endl;
}

bool BattleSystem::handlePlayerTurn(Role &player, Enemy &enemy) {
	const int choice = readChoice(1, 4);
	if (choice == 1) {
		const int hurt = player.getAttack() - enemy.getDefend();
		if (hurt <= 0) {
			cout << enemy.getName() << " 的防御化解了你的攻势。" << endl;
		} else {
			cout << "你对 " << enemy.getName() << " 造成了 " << hurt << " 点普通伤害。" << endl;
			enemy.setHealth(enemy.getHealth() - hurt);
		}
		return false;
	}

	if (choice == 2) {
		if (!player.showSkill()) {
			cout << "本回合未能施展技能。" << endl;
			return false;
		}

		const double multiplier = player.useSkill();
		const int hurt = static_cast<int>(multiplier * player.getAttack() - enemy.getDefend());
		if (hurt <= 0) {
			cout << enemy.getName() << " 挡住了这次技能攻击。" << endl;
		} else {
			cout << "技能命中，造成 " << hurt << " 点伤害。" << endl;
			enemy.setHealth(enemy.getHealth() - hurt);
		}
		return false;
	}

	if (choice == 3) {
		useConsumable(player);
		return false;
	}

	uniform_int_distribution<int> escapeRoll(0, 99);
	if (escapeRoll(rng) < 50) {
		cout << "你找准空隙，成功脱离了战斗。" << endl;
		return true;
	}

	cout << "你试图抽身后退，却被敌人死死缠住。" << endl;
	return false;
}

void BattleSystem::handleEnemyTurn(Role &player, Enemy &enemy) {
	uniform_int_distribution<int> attackRoll(0, 99);
	const bool useSkill = attackRoll(rng) >= 50 && enemy.getMagic() >= 20;

	if (!useSkill) {
		const int hurt = enemy.getAttack() - player.getDefend();
		if (hurt <= 0) {
			cout << "你稳住架势，挡下了 " << enemy.getName() << " 的攻击。" << endl;
			return;
		}

		player.setHealth(player.getHealth() - hurt);
		cout << enemy.getName() << " 对你造成了 " << hurt << " 点伤害。" << endl;
		return;
	}

	const int hurt = static_cast<int>(enemy.useSkill() - player.getDefend());
	enemy.setMagic(enemy.getMagic() - 20);
	if (hurt <= 0) {
		cout << enemy.getName() << " 发动了法术，但仍被你化解。" << endl;
		return;
	}

	player.setHealth(player.getHealth() - hurt);
	cout << enemy.getName() << " 消耗 20 点法力发动技能，对你造成了 " << hurt << " 点伤害。" << endl;
}

void BattleSystem::useConsumable(Role &player) {
	Goods goods[24] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 };

	if (!player.getBag().isUseDrug()) {
		cout << "背包里没有可在战斗中使用的药品。" << endl;
		return;
	}

	cout << "请选择要使用的药品（0 取消）：" << endl;
	for (int i = 1; i <= player.getBag().getGoodsNum(); i++) {
		const int goodsId = player.getBagWhichGoodsId(i);
		if (goodsId >= 20 && goodsId <= 23) {
			cout << i << ". " << goods[goodsId].getName() << '\t' << player.getBagWhichGoodsNum(i) << " 件" << endl;
		}
	}

	int whichGoods = readChoice(0, player.getBag().getGoodsNum());
	if (whichGoods == 0) {
		cout << "你放弃了使用药品。" << endl;
		return;
	}

	const int goodsId = player.getBagWhichGoodsId(whichGoods);
	cout << "请输入使用数量：" << endl;
	const int count = readChoice(1, player.getBagWhichGoodsNum(whichGoods));
	player.subGoodsToBag(goodsId, count);

	if (goodsId == 20 || goodsId == 21) {
		player.setHealth(player.getHealth() + goods[goodsId].getAddHP() * count);
		cout << "气血恢复了 " << goods[goodsId].getAddHP() * count << " 点。" << endl;
		return;
	}

	player.setMagic(player.getMagic() + goods[goodsId].getAddMP() * count);
	cout << "内力恢复了 " << goods[goodsId].getAddMP() * count << " 点。" << endl;
}

void BattleSystem::applyVictoryRewards(Role &player, const Enemy &enemy) const {
	cout << enemy.getName() << " 已被击败，战斗结束。" << endl;
	cout << "你获得了 " << enemy.getMoney() << " 点金钱。" << endl;
	player.setMoney(player.getMoney() + enemy.getMoney());
	cout << "你获得了 " << enemy.getExp() << " 点经验。" << endl;
	player.setExp(player.getExp() + enemy.getExp());
	int goodsId[4];
	int goodsNum[4];
	for (int i = 0; i < 4; i++) {
		goodsId[i] = enemy.getGoodsId()[i];
		goodsNum[i] = enemy.getGoodsNum()[i];
	}
	player.addGoodsToBag(goodsId, goodsNum);
}

bool BattleSystem::isBattleOver(const Role &player, const Enemy &enemy) const {
	return player.getHealth() <= 0 || enemy.getHealth() <= 0;
}
