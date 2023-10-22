#include "Boss.h"

Boss::Boss() {
	hp = 100;
	dmg = 10;
	armour = 5;
	stamina = 100;
	bossLevel = 0;
}
void Boss::updateStats() {
	hp = 100 + bossLevel * 25;
	dmg = 10 + bossLevel * 7;
	armour = 5 + bossLevel * 3;
	stamina = 100 + bossLevel * 10;
}
void Boss::addBossLevel() {
	bossLevel++;
}
int Boss::normalAttack(int enemyArmour) {
	int damageDealt = dmg - enemyArmour;
	if (damageDealt < 0) {
		damageDealt = 0;
	}
	return damageDealt;
}
int Boss::powerfulAttack(int enemyArmour) {
	if (stamina >= 20) {
		stamina -= 20;
		int damageDealt = 2 * (dmg - enemyArmour);
		if (damageDealt < 0) {
			damageDealt = 0;
		}
		return damageDealt;
	}
	else {
		normalAttack(enemyArmour);
	}
}