#include "Status.h"
#include <iostream>

Status::Status() : points(5), sHp(0), sDmg(0), sArmour(0), sStamina(0) {}
void Status::addHp() {
	if (points < 1) {
		std::cout << "Not enought points!\n";
	}
	else {
		sHp++;
		points--;
	}
}
void Status::addDmg() {
	if (points < 1) {
		std::cout << "Not enought points!\n";
	}
	else {
		sDmg++;
		points--;
	}
}
void Status::addArmour() {
	if (points < 1) {
		std::cout << "Not enought points!\n";
	}
	else {
		sArmour++;
		points--;
	}
}

void Status::addStamina() {
	if (points < 1) {
		std::cout << "Not enought points!\n";
	}
	else {
		sStamina++;
		points--;
	}
}
