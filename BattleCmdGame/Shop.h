#pragma once
#include "Character.h"
#include <array> // I learned that it is more useful and similar performance for arrays

class Shop {
public:
	//int swords[3];
	std::array<int, 3> swords;
	//int axes[3];
	std::array<int, 3> axes;
	//int bows[3];
	std::array<int, 3> bows;
	//int owned[9];
	std::array<int, 9> owned;
	Shop();
	void checkMoney(Character& c, int forBuy, int numberOfItem, int itemDamage);
};