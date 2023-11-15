#include "Boss.h";

Boss::Boss() : hp(100), dmg(10), armour(5), stamina(100), bossLevel(0){}
void Boss::updateStats() {
	hp = 100 + bossLevel * 25;
	dmg = 10 + bossLevel * 7;
	armour = 5 + bossLevel * 3;
	stamina = 100 + bossLevel * 10;
}
void Boss::addBossLevel() {
	bossLevel++;
}
void Boss::normalAttack(Character& c) {
	int damageDealt = dmg - c.armour;
	if (damageDealt < 0) {
		damageDealt = 0;
	}
	c.hp -= damageDealt;
	system("cls");
	std::cout << "He did " << damageDealt << " to you\n";
}
void Boss::powerfulAttack(Character& c) {
	if (stamina >= 20) {
		stamina -= 20;
		int damageDealt = 2 * (dmg - c.armour);
		if (damageDealt < 0) {
			damageDealt = 0;
		}
		c.hp -= damageDealt;
		system("cls");
		std::cout << "He did " << damageDealt << " to you\n";
	}
	else {
		normalAttack(c);
	}
}