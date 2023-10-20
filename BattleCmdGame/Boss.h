#pragma once
class Boss {
public:
	int hp, dmg, armour, stamina, bossLevel;
	Boss();
	//bossLevel and update
	void bossLvl();
	//attack logic the same as Character
	// 
	// Normal attack
	int normalAttack(int enemyArmour);
	// Powerful attack
	int powerfulAttack(int enemyArmour);
};