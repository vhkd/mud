#pragma once
#ifndef TASK_H
#define TASK_H
#include"Goods.h"
#include<string>

class Task {
public:
	Task(int id);
	~Task();

	int getTaskId() const;
	string getName() const;
	string getDesc() const;
	bool getIsEnd() const;
	Goods getGoods() const;
	void setGoods(Goods newGoods);
	void setIsTaskEnd();

private:
	int taskId;		//ID
	string name;	//
	string desc;	//
	bool isEnd;		//ɱ
	Goods goods;	//Ʒ,ʼΪյ


};




#endif
