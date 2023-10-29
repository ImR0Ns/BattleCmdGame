#pragma once
#include "Character.h"

class Shop {
public:
	int swords[3];
	int axes[3];
	int bows[3];
	int owned[9];
	Shop();
	void checkMoney(Character& c, int forBuy, int numberOfItem, int itemDamage);
};