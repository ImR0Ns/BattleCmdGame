#include <iostream>
#include <sstream>

class Weapons {
public:
	enum Swords {
		swordOne = 10,
		swordTwo = 20,
		swordThree = 30
	};
	enum Axe {
		axeOne = 12,
		axeTwo = 24,
		axeThree = 35
	};
	enum Bow {
		bowOne = 15,
		bowTwo = 30,
		bowThree = 45
	};
};

class Status {
public:
	int sHp, sDmg, sArmour, sStamina;
	int points = 5;
	Status() {
		sHp = 0;
		sDmg = 0;
		sArmour = 0;
		sStamina = 0;
	}
	void addHp() {
		if (points < 1) {
			std::cout << "Not enought points!\n";
		}
		else {
			sHp++;
			points--;
		}
	}
	void addDmg() {
		if (points < 1) {
			std::cout << "Not enought points!\n";
		}
		else {
			sDmg++;
			points--;
		}
	}
	void addArmour() {
		if (points < 1) {
			std::cout << "Not enought points!\n";
		}
		else {
			sArmour++;
			points--;
		}
	}
	void addStamina() {
		if (points < 1) {
			std::cout << "Not enought points!\n";
		}
		else {
			sStamina++;
			points--;
		}
	}
};

class Character:public Status {
private:
	int hp, dmg, armour, stamina;
public:
	Character() {
		hp = 100;
		dmg = 10;
		armour = 5;
		stamina = 100;
	}
	void seeStats() {
		std::cout << "Stats" << "\n"
			<< "Hp: " << hp << "\n"
			<< "Armour: " << armour <<"\n"
			<< "Damage: " << dmg << "\n"
			<< "Stamina: " << stamina << "\n";
	}
	void updateStats() {
		hp = hp + sHp * 15;
		dmg = dmg + sDmg * 2;
		armour = armour + sArmour * 3;
		stamina = stamina + sStamina * 10;
	}
};

class StartGame {
public:

	//main menu system
	void printMain(Character c) {
		system("cls");
		std::cout << "Menu!\n"
			<<"(1)Fight Boss\n"
			<<"(2)See stats\n"
			<<"(3)Add points\n"
			<<"(4)Shop\n"
			<<"(5)Exit Game!\n";

		int option;

		// Read the input as a string
		std::string input;
		std::cin >> input;

		while (true) {
			// Try to convert the input string to an integer
			std::istringstream ss(input);
			if (ss >> option) {
				if (option == 1) {
					

					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin >> input;
				}
				else if (option == 2) {
					c.seeStats();

					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin >> input;
				}
				else if (option == 3) {
					
					addStatus(c);

					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin >> input;
				}
				else if (option == 4) {
					

					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin >> input;
				}
				else if (option == 5) {
					break;
				}
				else {
					std::cout << "Not a valid option! Choose from 1 to 5: \n";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin >> input;
				}
			}
			else {
				std::cout << "Not a valid option! Choose from 1 to 5: \n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin >> input;
			}
		}
	}


	//status system
	void statsPrint(Character c) {
		system("cls");
		std::cout << "Add status | Points: " << c.points << "\n"
			<< "(1)Hp points: " << c.sHp << "\n"
			<< "(2)Damage points: " << c.sDmg << "\n"
			<< "(3)Armour points: " << c.sArmour << "\n"
			<< "(4)Stamina points: " << c.sStamina << "\n"
			<< "(5)Go to main\n";
	}
	void addStatus(Character c) {
		int option;
		statsPrint(c);

		// Read the input as a string
		std::string input;
		std::cin >> input;

		while (true) {
			// Try to convert the input string to an integer
			std::istringstream ss(input);
			if (ss >> option) {
				if (option == 1) {
					c.addHp();
					c.updateStats();
					statsPrint(c);
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin >> input;
				}
				else if (option == 2) {
					c.addDmg();
					c.updateStats();
					statsPrint(c);
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin >> input;
				}
				else if (option == 3) {
					c.addArmour();
					c.updateStats();
					statsPrint(c);
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin >> input;
				}
				else if (option == 4) {
					c.addStamina();
					c.updateStats();
					statsPrint(c);
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin >> input;
				}
				else if (option == 5) {
					printMain(c);
					break;
				}
				else {
					std::cout << "Not a valid option! Choose from 1 to 5: \n";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin >> input;
				}
			}
			else {
				std::cout << "Not a valid option! Choose from 1 to 5: \n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin >> input;
			}
		}
	}


	StartGame() {
		std::cout << "Welcome to fight the boss cmd game\n";
		Character createCharacter;
		addStatus(createCharacter);

	}

};

int main() {
	StartGame start;
	std::cout << "Hello";
}