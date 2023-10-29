#pragma once
#include <iostream>
#include "Status.h"
#include "Boss.h"

class Character :public Status {
public:
	int hp, dmg, armour, stamina, money, itemPower;
	Character();
	void seeStats();
	void updateStats();
	void statsPrint();
	void compareStats(Boss boss);
	// Normal attack
	int normalAttack(int enemyArmour);
	// Powerful attack
	int powerfulAttack(int enemyArmour);
};