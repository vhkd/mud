#include "core/Game.h"

#include <cstdlib>
#include <iostream>
#include <string>

#include "domain/Goods.h"
#include "io/Console.h"
#include "io/Save.h"

using namespace std;

namespace {

void printAnimated(const string &text, int delayMs) {
	for (size_t i = 0; i < text.length(); i++) {
		Console::sleepMs(delayMs);
		cout << text[i];
	}
}

}

int Game::run() {
	showWelcome();
	const int choice = readChoice(1, 3);
	if (choice == 1) {
		startNewGame();
	} else if (choice == 2) {
		loadGame();
	}
	return 0;
}

void Game::showWelcome() const {
	for (int i = 0; i < 8; i++) {
		cout << endl;
	}
	cout << '\t' << '\t' << '\t' << '\t' << "    0   0           0          0           " << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "    0   0            0         0 0  000    " << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "    000000000  000000000000    0 0         " << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "   0    0      0    0     0   0  0 00000   " << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "  00  0 0  0   0   0  0   0  0  0    0     " << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "0      00 0       0 0  0       00    0     " << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "   0 00000000   0    0       0  0    0     " << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "   0    00         0   0        0    0     " << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "   0   0  0      0 00000 0      0    0     " << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "   0  0    0   0   0   0  0     0  0 0     " << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "   0 0      0      00000        0   00     " << endl << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << "   ********************" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << "       游戏制作信息" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << "   ********************" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "   制作人：中国海洋大学2017夏季学期c++课程设计16组" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "   梁同学、张同学与孟同学" << endl << endl;
	cout << '\t' << '\t' << '\t' << '\t';
	printAnimated("   1.新的游戏  2.读取存档  3.退出游戏", 20);
	cout << endl << endl << '\t' << '\t' << '\t' << '\t' << "   ";
}

void Game::showBackgroundStory() const {
	const string stories[] = {
		"    鸿蒙开化之初，中州大陆昆仑之巅的鸿钧上人创立道教，并收徒三人，各授以道门绝技，三徒皆修成混元大罗金仙万劫不坏之体，分别发展出道教的人道、阐教和截教三个分支。此三徒正是人道教主太上老君、阐教教主元始天尊和截教的通天教主。",
		"    三教主秉承师父鸿钧上人教诲，广收门徒将道教流传于世。只因入道门中即可修仙，使人跳出三界之外，不在五行之中，免除生死轮回之苦，使得入道修行之人多不胜数！但修仙之道并非苦心修炼便可达成。修行路上，均要经历三百年一小劫，一千五百年一大劫的劫数。修行之人均无法避开劫数，只能根据自身道行的深浅去经历劫数。",
		"    值商周两朝交替之时，恰逢修仙一千五百年仙劫，于是三教主共议封神榜，以观众仙道行浅深。然劫数难逃，封神一役，致使道门内部阐教和截教不和，修仙众人俱遭屠戮，更引来西方教派参与纷争，后因鸿钧上人亲自出面调停，终得以平息。",
		"    五百年后的中洲大陆，故事就发生在一个平凡冷清的小镇上。"
	};

	for (const string &story : stories) {
		Console::clear();
		cout << "故事背景" << endl << endl;
		printAnimated(story, 5);
		cout << endl;
		Console::pause();
	}
	Console::clear();
}

void Game::startNewGame() {
	showBackgroundStory();
	cout << "职业简介: " << endl
		<< "1.人道" << endl << "认为“道”是宇宙万物的本原和主宰，无所不在，无所不包，万物都是从“道”演化而来的。" << endl
		<< "2.阐教" << endl << "阐者，明也。阐教主张崇尚自然，提倡道法自然，无所不容，自然无为，与自然和谐相处。" << endl
		<< "3.截教" << endl << "主张上道无德，下道唯德。大道五十衍四十九为定数，一线生机遁去，截教的教义正是截取这一线生机，演变六道。" << endl;
	cout << endl << "请输入要创建的职业" << endl;

	const int choiceRole = readChoice(1, 3);
	Role player(choiceRole);
	Map map;
	Console::clear();
	cout << "创建成功" << endl;
	gameLoop(player, map);
}

void Game::loadGame() {
	Role player(0);
	if (!Save::loadFromFile(player)) {
		return;
	}
	Map map(player.getMapId());
	gameLoop(player, map);
}

void Game::gameLoop(Role &player, Map &map) {
	while (true) {
		Console::sleepMs(500);
		Console::clear();
		cout << endl << "位于 :" << map.getName() << endl;
		map.showRoom();
		if (map.isThereFight()) {
			Enemy_Boss boss(map.getPosition());
			if (!map.isThereChat()) {
				cout << "这里有：\t";
			}
			cout << boss.getName() << '\t' << "三头小野怪" << endl;
		}

		player.showRole();
		cout << endl << "1.交谈 2.战斗 3.移动 4.状态 5.商店 6.退出 7.保存并退出" << endl;
		const int choice = readChoice(1, 7);

		if (choice == 1) {
			if (map.isThereChat()) {
				cout << endl << "可以对话的人物:" << endl;
				cout << map.getNpcName() << endl;
				dialogueSystem.run(player, map.getPosition());
				Console::pause();
			}
			continue;
		}

		if (choice == 2) {
			if (!map.isThereFight()) {
				cout << "这里没有战斗可以发生" << endl;
				Console::pause();
				continue;
			}

			Enemy_Boss boss(map.getPosition());
			const BattleOutcome outcome = battleSystem.run(player, boss);
			if (outcome == BattleOutcome::Defeat) {
				return;
			}
			Console::pause();
			continue;
		}

		if (choice == 3) {
			while (true) {
				map.ShowMap();
				cout << "使用w a s d来移动 按1进入地图" << endl;
				char order;
				cin >> order;
				if (order == '1') {
					Console::clear();
					break;
				}
				map.Move(order);
				player.setMapId(map.getPosition());
			}
			continue;
		}

		if (choice == 4) {
			handleStatusMenu(player);
			continue;
		}

		if (choice == 5) {
			storeSystem.run(player);
			continue;
		}

		if (choice == 6) {
			cout << "成功退出！" << endl;
			return;
		}

		if (Save::setToFile(player)) {
			return;
		}
	}
}

void Game::handleStatusMenu(Role &player) {
	cout << "1.属性 2.背包 3.技能 4.装备 5.任务 6.返回" << endl;
	const int choice = readChoice(1, 6);
	if (choice == 1) {
		cout << "以上就为人物属性。" << endl;
	} else if (choice == 2) {
		player.showBag();
		player.useDrug();
	} else if (choice == 3) {
		player.showSkill();
	} else if (choice == 4) {
		handleEquipMenu(player);
	} else if (choice == 5) {
		cout << "任务" << player.getTaskId() << '\t' << player.getTaskName() << '\t' << player.getTaskDesc() << endl << endl;
	}
	Console::pause();
}

void Game::handleEquipMenu(Role &player) {
	Goods goods[24] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 };
	player.showEquip();
	cout << "1.更换装备 2.取下装备 3.退出" << endl;
	const int choiceEquip = readChoice(1, 3);
	if (choiceEquip == 1) {
		player.showBag();
		cout << "请选择要换上的装备(24.取消)" << endl;
		int id;
		cin >> id;
		if (id >= 0 && id < 24) {
			player.wearEquip(id);
		}
		return;
	}

	if (choiceEquip == 2) {
		cout << "请输入要换下的装备" << endl;
		if (player.getWeapon() != -1) {
			cout << "1." << goods[player.getWeapon()].getName() << endl;
		}
		if (player.getClothes() != -1) {
			cout << "2." << goods[player.getClothes()].getName() << endl;
		}
		const int choice = readChoice(1, 2);
		if (choice == 1 && player.getWeapon() != -1) {
			player.removeEquip(player.getWeapon());
		}
		if (choice == 2 && player.getClothes() != -1) {
			player.removeEquip(player.getClothes());
		}
	}
}

int Game::readChoice(int min, int max) const {
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
