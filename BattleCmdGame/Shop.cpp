#include "Shop.h"
#include <iostream>


Shop::Shop() : swords{ 10, 20, 30 }, axes{ 12, 24, 36 }, bows{ 25, 45, 60 }, owned{0, 0, 0, 0, 0, 0, 0, 0, 0} {}

void Shop::checkMoney(Character& c, int forBuy, int numberOfItem, int itemDamage) {
	if (owned[numberOfItem] == 1) {
		std::cout << "You have it and equiped it!\n";
		c.itemPower = itemDamage;
	}else if (c.money >= forBuy) {
		owned[numberOfItem] = 1;
		c.money -= forBuy;
		c.itemPower = itemDamage;
		std::cout << "You bought it and equiped it!\n";
	}
	else {
		system("cls");
		std::cout << "You don't have enough money!\n";
	}
}