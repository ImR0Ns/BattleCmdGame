#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>

/*
	Next Update:
	Moneyyy - integration and Shop
*/


void clearData();//for clear cmd

// 
// 
//Boss class
class Boss {
public:
	int hp, dmg, armour, stamina;
	int bossLevel = 1;
	Boss() {
		hp = 100;
		dmg = 10;
		armour = 5;
		stamina = 100;
	}
	//bossLevel and update
	void bossLvl() {
		bossLevel++;
		hp = 100 + bossLevel * 25;
		dmg = 10 + bossLevel * 25;
		armour = 10 + bossLevel * 25;
		stamina = 100 + bossLevel * 25;
	}

	//attack logic the same as Character
	// 
	// Normal attack
	int normalAttack(int enemyArmour) {
		int damageDealt = dmg - enemyArmour;
		if (damageDealt < 0) {
			damageDealt = 0;
		}
		return damageDealt;
	}


	// Powerful attack
	int powerfulAttack(int enemyArmour) {
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
};

//Weapons and dammage
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

//status and points
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

//Character and stats
class Character:public Status {
public:
	int hp, dmg, armour, stamina;
	Character() {
		hp = 100;
		dmg = 10;
		armour = 5;
		stamina = 100;
	}
	void seeStats() {
		clearData();
		std::cout << "Stats" << "\n"
			<< "Hp: " << hp << "\n"
			<< "Armour: " << armour << "\n"
			<< "Damage: " << dmg << "\n"
			<< "Stamina: " << stamina << "\n\n";
		
	}
	void updateStats() {
		hp = hp + sHp * 15;
		dmg = dmg + sDmg * 2;
		armour = armour + sArmour * 1;
		stamina = stamina + sStamina * 10;
	}
	// Normal attack
	int normalAttack(int enemyArmour) {
		int damageDealt = dmg - enemyArmour;
		if (damageDealt < 0) {
			damageDealt = 0;
		}
		return damageDealt;
	}


	// Powerful attack
	int powerfulAttack(int enemyArmour) {
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
};

class StartGame {
public:
	//init boss
	Boss boss;

	//fight system
	void attackBetween(Character& c, Boss& b, int attackPower) {

		int bossDmg = b.powerfulAttack(c.armour); //the boss will use his powerfull attack till he has no stamina
		int dmg = 0;

		if (attackPower == 1) {
			dmg = c.normalAttack(b.armour);
		}
		else {
			dmg = c.powerfulAttack(b.armour);
		}

		c.hp -= bossDmg;
		b.hp -= dmg;
		clearData();

		std::cout << "You did " << dmg << " to the boss!\n"
			<< "He did " << bossDmg << " to you\n";
	}

	void fightBoss(Character c) {
		clearData();

		int choice;
		bool active = true;
		int rememberHp = c.hp;

		while (active && c.hp > 0 && boss.hp > 0) {
			std::cout << "Your hp: " << c.hp << "\nEnemy hp: " << boss.hp << "\n";
			std::cout << "Choose your action:" << std::endl;
			std::cout << "(1)Normal Attack | 0 stamina" << std::endl;
			std::cout << "(2)Powerful Attack | 20 stamina" << std::endl;
			std::cout << "(3)Exit" << std::endl;

			std::cin >> choice;

			if (std::cin.fail() || choice < 1 || choice > 3) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid choice. Please enter a number between 1 and 3." << std::endl;
			}
			else {
				// Valid choice
				switch (choice) {
				case 1:
					attackBetween(c, boss, 1);
					break;
				case 2:
					attackBetween(c, boss, 2);
					break;
				case 3:
					active = false;
					printMain(c);
					break;
				}
			}
		}
		//clear data 
		clearData();
		//show winning
		if (boss.hp <= 0) {
			std::cout << "You won! (5 stats points | 1000 money)\n";
			c.points += 5;
			boss.bossLvl(); // update level and stats of boss
		}
		else {
			std::cout << "The Boss won! (1 stats point | 150 money)\n";
			c.points += 1;
		}

		c.hp = rememberHp; // restore full hp

		//sleep for 5 seconds to look at your prize
		std::cout << "You will be redirected to the main page in " << 5 << " seconds...\n";
		std::this_thread::sleep_for(std::chrono::seconds(5));
		//go to main
		printMain(c);
	}

	//main menu system
	void printMain(Character c) {
		clearData();
		std::string text = "Menu!\n(1)Fight Boss\n(2)See stats\n(3)Add points | Available points " + std::to_string(c.points) + "\n(4)Shop\n(5)Exit Game!\n";
		std::cout << text;

		int option;

		// Read the input as a string
		std::string input;
		std::cin >> input;

		while (true) {
			// Try to convert the input string to an integer
			std::istringstream ss(input);
			if (ss >> option) {
				if (option == 1) {
					
					fightBoss(c);
					break;
				}
				else if (option == 2) {

					c.seeStats();
					std::cout<<text;

					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin >> input;
				}
				else if (option == 3) {
					addStatus(c);
					break;
				}
				else if (option == 4) {
					//in work

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
		clearData();
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

	//START GAME
	StartGame() {
		Character createCharacter;
		addStatus(createCharacter);
	}

};

int main() {
	StartGame start; //init
	std::cout << "";
}

void clearData() {
	system("cls");
}