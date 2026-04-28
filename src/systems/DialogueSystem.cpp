#include "systems/DialogueSystem.h"

#include <iostream>

#include "io/Console.h"
#include "domain/Goods.h"
#include "domain/Task.h"

using namespace std;

void DialogueSystem::run(Role &player, int mapPosition) const {
	switch (mapPosition) {
	case 0:
		if (player.getStory() != 0) {
			cout << "雪蝶已经把能说的都告诉你了。" << endl;
			return;
		}
		say("雪蝶", "近来镇北官道不太平，夜里常有凶物出没，闹得乡民不得安睡。");
		say("你", "只是寻常山兽，还是另有蹊跷？");
		say("雪蝶", "猎户们都说，那些野物比从前凶悍得多，像是受了什么邪气催逼。");
		say("你", "我正好要去岳州城探探消息，顺路替乡亲们看看。");
		say("雪蝶", "此去多加小心。这几包金创药你先带上，关键时刻能保命。");
		player.setStory(1);
		grantReward(player, 20, 5);
		return;

	case 2:
		if (player.getStory() != 1) {
			remindLockedDialogue();
			return;
		}
		say("云中子", "你来得正好。雪蝶失踪了，镇上都在传她是被树怪掳走的。");
		say("你", "不可能……前些天她还劝我路上小心。");
		say("云中子", "线索不多，只知道那树怪常在山道深处出没。你若真要查，就别再空手上路。");
		say("你", "她曾助我，我不能坐视不理。");
		say("云中子", "这把精钢剑你拿着。若想继续追查，可以去五龙山找广法天尊，但他向来只见有本事的人。");
		player.setStory(2);
		grantReward(player, 1, 1, "新任务：带着线索前往五龙山，设法见到广法天尊。");
		player.setTask(Task(1));
		return;

	case 4:
		if (player.getStory() != 2) {
			remindLockedDialogue();
			return;
		}
		if (!player.getTaskIsEnd()) {
			cout << "广法天尊看了你一眼，淡淡说道：“先把手上的事情办妥，再来见我。”" << endl;
			return;
		}
		say("广法天尊", "你身上带着猛兽魂，看来确实闯过了山中的险关。说吧，何事如此急切？");
		say("你", "我在追查雪蝶的下落，听闻天尊见多识广，特来请教。");
		say("广法天尊", "雪蝶之事我未亲见，但我师兄玉鼎真人也许知道更多。");
		say("你", "弟子愿即刻前往。只是该如何求见？");
		say("广法天尊", "他近来正寻找大夏龙雀。你若能把那件古兵带去，他多半会开口。地宫深处凶险重重，这件环锁铠你先拿着。");
		player.setStory(3);
		grantReward(player, 12, 1, "新任务：深入地宫，寻得大夏龙雀后去见玉鼎真人。");
		player.setTask(Task(2));
		return;

	case 5:
		if (player.getStory() != 3) {
			remindLockedDialogue();
			return;
		}
		say("接引道人", "喂，小子，可曾见过我的毒蝎虎？它若跑丢了，我可要心疼好几天。");
		say("你", "未曾见到。我一路追查雪蝶线索，误打误撞闯进此地。");
		say("接引道人", "原来如此。地宫寒气蚀骨，你能走到这里，也算命硬。");
		say("你", "还请前辈指点一二。");
		say("接引道人", "我不知道雪蝶的消息，不过这几枚小还丹你拿去，省得半路先把自己折进去。若真见着我的毒蝎虎，记得替我留神。");
		player.setStory(4);
		grantReward(player, 21, 5);
		return;

	case 7:
		if (player.getStory() != 4) {
			remindLockedDialogue();
			return;
		}
		narrate("一名醉意醺然的道人倚着残墙，嘴里反复念着“贫道可是玉鼎真人”。");
		say("你", "敢问前辈可是玉鼎真人？我为寻找雪蝶而来。");
		say("玉鼎真人", "求人办事，总得带点诚意。");
		if (!player.getTaskIsEnd()) {
			say("玉鼎真人", "空着手来问路，可不像是求人的样子。等你把我要的东西带来，再谈不迟。");
			return;
		}
		say("你", "广法天尊命我将大夏龙雀送来，也请前辈赐教雪蝶的去向。");
		say("玉鼎真人", "这还差不多。我只知她并未身死，而是被树怪掳去了龙穴，只是那龙穴究竟在何处，我也不敢妄断。");
		say("你", "线索至此又断了……");
		say("玉鼎真人", "别急，去昆仑问我师父元始天尊。他若肯说，世间少有他不知道的事。带上紫龙天罡铠当见面礼，他老人家或许心情会好些。");
		say("玉鼎真人", "你既替我寻回大夏龙雀，这柄无影飞剑便赠你防身。");
		player.setStory(5);
		grantReward(player, 7, 1, "新任务：携紫龙天罡铠前往昆仑，向元始天尊求问龙穴所在。");
		player.setTask(Task(3));
		return;

	case 9:
		if (player.getStory() != 5) {
			remindLockedDialogue();
			return;
		}
		say("元始天尊", "你一路走来，心中所求，我已尽知。");
		say("你", "还请天尊明示雪蝶的去向。");
		if (!player.getTaskIsEnd()) {
			say("元始天尊", "时机未到。等你备好该带来的东西，再来问我。");
			return;
		}
		say("元始天尊", "她仍活着，被困在龙坑之中。若想救她，你必须先击败盘踞其上的纳什男爵。");
		say("你", "多谢天尊指点。");
		say("元始天尊", "此行凶险，我便赐你一柄纯均。愿你不负此剑，也不负来时初心。");
		player.setStory(6);
		grantReward(player, 9, 1, "主线推进：前往最终龙穴，击败纳什男爵，救出雪蝶。");
		return;

	default:
		cout << "这里没有可以深入交谈的人物。" << endl;
		return;
	}
}

void DialogueSystem::say(const char *speaker, const char *line) const {
	cout << speaker << "：" << line << endl;
	Console::pause();
}

void DialogueSystem::narrate(const char *line) const {
	cout << line << endl;
	Console::pause();
}

void DialogueSystem::grantReward(Role &player, int goodsId, int goodsNum, const char *taskHint) const {
	Goods reward(goodsId);
	player.addGoodsToBag(goodsId, goodsNum);
	cout << endl << "获得物品：" << reward.getName() << " x" << goodsNum << endl;
	if (taskHint != nullptr) {
		cout << taskHint << endl;
	}
	cout << endl;
}

void DialogueSystem::remindLockedDialogue() const {
	cout << "对方暂时没有新的话可说。先沿着现有线索继续前行吧。" << endl;
}
