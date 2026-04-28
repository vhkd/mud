#ifndef DIALOGUE_SYSTEM_H
#define DIALOGUE_SYSTEM_H

#include "domain/Role.h"

class DialogueSystem {
public:
	void run(Role &player, int mapPosition) const;

private:
	void say(const char *speaker, const char *line) const;
	void narrate(const char *line) const;
	void grantReward(Role &player, int goodsId, int goodsNum, const char *taskHint = nullptr) const;
	void remindLockedDialogue() const;
};

#endif
