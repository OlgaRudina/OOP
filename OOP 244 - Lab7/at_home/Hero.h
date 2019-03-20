#ifndef SICT_HERO_H
#define SICT_HERO_H
#include <iostream>

namespace sict {

	const int max_rounds = 100;

	class Hero {

		char hName[41];
		int hHealth;
		int hATTK;

	public:

		Hero();
		Hero(const char *name, int health, int ATTK);
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		friend std::ostream& operator<<(std::ostream&, const Hero&);
		void removeHealth(int attack);
	};

	const Hero& operator*(const Hero& first, const Hero& second);

}

#endif