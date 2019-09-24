#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H
#include <iostream>
#include "Hero.h"

namespace sict {

	class SuperHero : public Hero {

		int sBonus;
		int sDefence;

	public:
		SuperHero();
		SuperHero(const char *name, int health, int ATTK, int bonus, int defence);

		int attackStrength() const;
		int defend() const;

	};
	
	void SuperDamage(SuperHero& A, SuperHero& B);
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}

#endif