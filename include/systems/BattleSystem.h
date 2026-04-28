#ifndef BATTLE_SYSTEM_H
#define BATTLE_SYSTEM_H

#include <random>

#include "domain/Enemy.h"
#include "domain/Role.h"

enum class BattleOutcome {
	Escaped,
	Victory,
	Defeat
};

class BattleSystem {
public:
	BattleSystem();
	BattleOutcome run(Role &player, Enemy enemy);

private:
	int readChoice(int min, int max) const;
	void showStatus(const Role &player, const Enemy &enemy, int round) const;
	bool handlePlayerTurn(Role &player, Enemy &enemy);
	void handleEnemyTurn(Role &player, Enemy &enemy);
	void useConsumable(Role &player);
	void applyVictoryRewards(Role &player, const Enemy &enemy) const;
	bool isBattleOver(const Role &player, const Enemy &enemy) const;

	std::mt19937 rng;
};

#endif
