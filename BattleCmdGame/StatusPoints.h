#pragma once
class StatusPoints {
public:
	int sHp, sDmg, sArmour, sStamina;
	int points;
	StatusPoints();
	void addHp();
	void addDmg();
	void addArmour();
	void addStamina();
};