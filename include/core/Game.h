#ifndef GAME_H
#define GAME_H

#include "domain/Map.h"
#include "domain/Role.h"
#include "systems/BattleSystem.h"
#include "systems/DialogueSystem.h"
#include "systems/StoreSystem.h"

class Game {
public:
	int run();

private:
	void showWelcome() const;
	void showBackgroundStory() const;
	void startNewGame();
	void loadGame();
	void gameLoop(Role &player, Map &map);
	void handleStatusMenu(Role &player);
	void handleEquipMenu(Role &player);
	int readChoice(int min, int max) const;

	BattleSystem battleSystem;
	DialogueSystem dialogueSystem;
	StoreSystem storeSystem;
};

#endif
