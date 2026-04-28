#include "domain/Task.h"

Task::Task(int id) : goods(24) {
	taskId = id;
	isEnd = false;

	if (id == 1) {
		name = "寻找雪蝶";
		desc = "带着云中子的线索前往五龙山，证明自己的实力后求见广法天尊。";
	} else if (id == 2) {
		name = "寻找龙雀";
		desc = "深入地宫，寻得大夏龙雀，再带去见玉鼎真人。";
	} else if (id == 3) {
		name = "拜见天尊";
		desc = "携紫龙天罡铠前往昆仑，向元始天尊追问龙穴的下落。";
	} else {
		name = "暂无任务";
		desc = "当前没有进行中的任务。";
	}
}

Task::~Task() {}

int Task::getTaskId() const {
	return taskId;
}

string Task::getName() const {
	return name;
}

string Task::getDesc() const {
	return desc;
}

Goods Task::getGoods() const {
	return goods;
}

void Task::setGoods(Goods newGoods) {
	goods = newGoods;
}

bool Task::getIsEnd() const {
	return isEnd;
}

void Task::setIsTaskEnd() {
	isEnd = true;
}
