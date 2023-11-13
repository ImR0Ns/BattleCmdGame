#include "StatusPoints.h"
#include <iostream>

StatusPoints::StatusPoints() : points(5), sHp(0), sDmg(0), sArmour(0), sStamina(0) {}
void StatusPoints::addHp() {
	if (points < 1) {
		std::cout << "Not enought points!\n";
	}
	else {
		sHp++;
		points--;
	}
}
void StatusPoints::addDmg() {
	if (points < 1) {
		std::cout << "Not enought points!\n";
	}
	else {
		sDmg++;
		points--;
	}
}
void StatusPoints::addArmour() {
	if (points < 1) {
		std::cout << "Not enought points!\n";
	}
	else {
		sArmour++;
		points--;
	}
}

void StatusPoints::addStamina() {
	if (points < 1) {
		std::cout << "Not enought points!\n";
	}
	else {
		sStamina++;
		points--;
	}
}
