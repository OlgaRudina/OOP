#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <cstring>
#include "SuperHero.h"
#include "Hero.h"

using namespace std;
using namespace sict;

namespace sict {

	SuperHero::SuperHero() : Hero() {

		sBonus = 0;
		sDefence = 0;
	}

	SuperHero::SuperHero(const char *name, int health, int ATTK, int bonus, int defence) : Hero(name, health, ATTK) {
		sBonus = bonus;
		sDefence = defence;
	}



	int SuperHero::attackStrength() const {
		
		return Hero::attackStrength() + sBonus;
	};


	int SuperHero::defend() const {

		return sDefence;

	};

	void SuperDamage(SuperHero& A, SuperHero& B) {
	
		int damageA = B.attackStrength() - A.defend();
		int damageB = A.attackStrength() - B.defend();

		if (damageA < 1) {

			damageA = 1;
		}

		if (damageB < 1) {

			damageB = 1;
		}

		A.removeHealth(damageA);
		B.removeHealth(damageB);
	
	};



	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
	
		cout << "Super Fight! " << first << " vs " << second << " : ";
		
		SuperHero A = first;
		SuperHero B = second;
		const SuperHero *winner = nullptr;
		int rounds = 0;

		while (A.isAlive() && B.isAlive() && rounds < 100) {

			rounds++;
			SuperDamage(A, B);

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

	
	};
}