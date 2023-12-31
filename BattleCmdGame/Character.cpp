#include "Character.h"

Character::Character() : hp(100), dmg(10), armour(5), stamina(100), money(1000), itemPower(0){ } // initializer list
void Character::seeStats() {
	system("cls");
	std::cout << "Stats" << "\n"
		<< "Hp: " << hp << "\n"
		<< "Armour: " << armour << "\n"
		<< "Damage: " << dmg << " + " << itemPower << " item power!\n"
		<< "Stamina: " << stamina << "\n\n";

}
void Character::updateStats() {
	//contructor default values + points * int
	hp = 100 + sHp * 15;
	dmg = 10 + sDmg * 2;
	armour = 5 + sArmour * 3;
	stamina = 100 + sStamina * 10;
}
//status system
void Character::statsPrint() {
	system("cls");
	std::cout << "Add status | Points: " << points << "\n"
		<< "(1)Hp points: " << sHp << "\n"
		<< "(2)Damage points: " << sDmg << "\n"
		<< "(3)Armour points: " << sArmour << "\n"
		<< "(4)Stamina points: " << sStamina << "\n"
		<< "(5)Go to main\n";
}
//compare stats in fight mode
void Character::compareStats(Boss& boss){
	std::cout << "Character Stats" << "\t\t\t\t" << "Boss Stats | Level "<< boss.bossLevel + 1 << "\n"
		<< "Hp: " << hp << "\t\t\t\t\t" << "Hp: " << boss.hp << "\n"
		<< "Armour: " << armour << "\t\t\t\t" << "Armour: " << boss.armour << "\n"
		<< "Damage: " << dmg << " + " << itemPower << " item power! " << "\t\t\t\t" << "Damage: " << boss.dmg << "\n"
		<< "Stamina: " << stamina << "\t\t\t\t" << "Stamina: " << boss.stamina << "\n\n";
}

// Normal attack
void Character::normalAttack(Boss& boss) {
	int damageDealt = (dmg + itemPower) - boss.armour;
	if (damageDealt < 0) {
		damageDealt = 0;
	}
	boss.hp -= damageDealt;
	boss.powerfulAttack(*this); //*this -> dereference obj to get Character class
	std::cout << "You did " << damageDealt << " to the boss!\n\n";
}


// Powerful attack
void Character::powerfulAttack(Boss& boss) {
	if (stamina >= 20) {
		stamina -= 20;
		int damageDealt = 2 * ((dmg + itemPower) - boss.armour);
		if (damageDealt < 0) {
			damageDealt = 0;
		}
		boss.hp -= damageDealt;
		boss.powerfulAttack(*this);
		std::cout << "You did " << damageDealt << " to the boss!\n\n";
	}
	else {
		normalAttack(boss);
	}
}
