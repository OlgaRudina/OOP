#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <cstring>
#include "Hero.h"

using namespace std;
using namespace sict;

namespace sict {

	Hero::Hero() {

		*hName = '\0';
		hHealth = 0;
		hATTK = 0;

	}


	Hero::Hero(const char *name, int health, int ATTK) {

		if (health > 0 && ATTK > 0 && *name != '\0')

		{
			strcpy(hName, name);
			hHealth = health;
			hATTK = ATTK;
		}

		else {

			*hName = '\0';
			hHealth = 0;
			hATTK = 0;

		}

	}

	void Hero::operator-=(int attack) {

		if (attack > 0) {

			hHealth = hHealth - attack;
		};

		if (hHealth < attack) {

			hHealth = 0;
		}
	}

	bool Hero::isAlive() const {

		if (hHealth > 0) {

			return true;
		}

		else {

			return false;
		}

	}


	int Hero::attackStrength() const {

		if (hATTK != 0) {

			return hATTK;
		}

		else {

			return 0;
		}
	}


	std::ostream & operator<<(std::ostream & os, const Hero & hero) {

		if (hero.hName == '\0') {
			os << "No Hero";
		}
		else {
			os << hero.hName;
		}
		return os;
	}

	void Hero::removeHealth(int attack) {

		if (attack >= hHealth)
			hHealth = 0;
		else
			hHealth -= attack;
	}

	void Damage(Hero& A, Hero& B) {
		A.removeHealth(B.attackStrength());
		B.removeHealth(A.attackStrength());
	}

	const Hero & operator*(const Hero & first, const Hero & second) {

		cout << "Ancient Battle! ";
		cout << first;
		cout << " vs ";
		cout << second;
		cout << " : ";
		Hero A = first;
		Hero B = second;

		const Hero *winner = nullptr;
		int rounds = 0;

		while (A.isAlive() && B.isAlive() && rounds < 100) {

			rounds++;
			Damage(A, B);

		}

		bool draw;

		if (A.isAlive() && B.isAlive()) { draw = true; }
		else { draw = false; }

		if (draw) {
			winner = &first;
		}
		else if (A.isAlive())
		{
			winner = &first;
		}
		else {
			winner = &second;
		}

		cout << "Winner is ";
		cout << *winner;
		cout << " in " << rounds << " rounds." << endl;
		return *winner;

	}

}
