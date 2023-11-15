#pragma once
#include <iostream>
#include "StatusPoints.h"
#include "Boss.h"

class Boss;

class Character :public StatusPoints {
public:
	int hp, dmg, armour, stamina, money, itemPower;
	Character();
	void seeStats();
	void updateStats();
	void statsPrint();
	void compareStats(Boss& boss);
	// Normal attack
	void normalAttack(Boss& boss);
	// Powerful attack
	void powerfulAttack(Boss& boss);
};