#pragma once

#include "Character.h";

class Character;

class Boss {
public:
	int hp, dmg, armour, stamina, bossLevel;
	Boss();
	//bossLevel and update
	void updateStats();
	void addBossLevel();
	//attack logic the same as Character
	// 
	// Normal attack
	void normalAttack(Character& c);
	// Powerful attack
	void powerfulAttack(Character& c);
};