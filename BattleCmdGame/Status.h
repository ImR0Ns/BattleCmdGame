#pragma once
class Status {
public:
	int sHp, sDmg, sArmour, sStamina;
	int points;
	Status();
	void addHp();
	void addDmg();
	void addArmour();
	void addStamina();
};