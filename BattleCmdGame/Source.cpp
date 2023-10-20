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
	Next Update:
	Moneyyy - integration and Shop

	Bugs:
	Stamina after battle is not recovering
	The updateStats is updating too much and double damage.

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
			//we need to reset the hp for the boss too!
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