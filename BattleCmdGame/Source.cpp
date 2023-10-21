#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>

//include class headers
#include "Boss.h"
#include "Weapons.h"
#include "Status.h"
#include "Character.h"

/*
Tasks:
Bugs:
-Boss level up after beating not working anymore
-If we enter fight boss and leave will not reset to normal
-auto update hp to everyone
*/


void clearData(); //for clear cmd

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

		//choises
		int choice;
		bool active = true;

		//restore by default for boss too
		int rememberHp = c.hp;
		int rememberStamina = c.stamina;
		int rememberHpBoss = boss.hp;
		int rememmberStaminaBoss = boss.stamina;

		while (active && c.hp > 0 && boss.hp > 0) {
			std::cout << "Your hp: " << c.hp << "\nEnemy hp: " << boss.hp << "\n";
			std::cout << "Choose your action:\n";
			std::cout << "(1)Normal Attack | 0 stamina\n";
			std::cout << "(2)Powerful Attack | 20 stamina | "<<"Your stamina: " << c.stamina <<"\n";
			std::cout << "(3)Exit\n";

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

		//we need to reset the hp for the boss too!
		c.hp = rememberHp; // restore full hp
		c.stamina = rememberStamina;
		boss.hp = rememberHpBoss;
		boss.stamina = rememmberStaminaBoss;


		//sleep for 3 seconds to look at your prize
		std::cout << "You will be redirected to the main page in " << 3 << " seconds...\n";
		std::this_thread::sleep_for(std::chrono::seconds(3));
		//go to main
		printMain(c);
	}

	//main menu system
	void printMain(Character c) {
		clearData();
		std::string text = "Menu!\n(1)Fight Boss\n(2)See stats\n(3)Add points | Available points " + std::to_string(c.points) + "\n(4)Shop | Your Money " + std::to_string(c.money) + "\n(5)Exit Game!\n";
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
					exit(0);
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

	void addStatus(Character c) {
		int option;
		c.statsPrint();

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
					c.statsPrint();
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin >> input;
				}
				else if (option == 2) {
					c.addDmg();
					c.updateStats();
					c.statsPrint();
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin >> input;
				}
				else if (option == 3) {
					c.addArmour();
					c.updateStats();
					c.statsPrint();
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin >> input;
				}
				else if (option == 4) {
					c.addStamina();
					c.updateStats();
					c.statsPrint();
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