#include "Character.h"

Character::Character() {
	hp = 100;
	dmg = 10;
	armour = 5;
	stamina = 100;
}
void Character::seeStats() {
	system("cls");
	std::cout << "Stats" << "\n"
		<< "Hp: " << hp << "\n"
		<< "Armour: " << armour << "\n"
		<< "Damage: " << dmg << "\n"
		<< "Stamina: " << stamina << "\n\n";

}
void Character::updateStats() {
	hp = hp + sHp * 15;
	dmg = dmg + sDmg * 2;
	armour = armour + sArmour * 1;
	stamina = stamina + sStamina * 10;
}
// Normal attack
int Character::normalAttack(int enemyArmour) {
	int damageDealt = dmg - enemyArmour;
	if (damageDealt < 0) {
		damageDealt = 0;
	}
	return damageDealt;
}


// Powerful attack
int Character::powerfulAttack(int enemyArmour) {
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
