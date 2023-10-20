#pragma once
#include <iostream>
#include "Status.h"

class Character :public Status {
public:
	int hp, dmg, armour, stamina;
	Character();
	void seeStats();
	void updateStats();
	// Normal attack
	int normalAttack(int enemyArmour);
	// Powerful attack
	int powerfulAttack(int enemyArmour);
};