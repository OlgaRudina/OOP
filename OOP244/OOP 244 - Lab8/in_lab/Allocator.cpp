#include "SavingsAccount.h" 

namespace sict {

	// define interest rate
	//

	const double intRate = 0.05;


	// TODO: Allocator function
	//

	iAccount* CreateAccount(const char* type, double bal) {

		Account * newAccount = nullptr;

		if (type[0] == 'S') {

			newAccount = new SavingsAccount(bal, intRate);
		}

		return newAccount;


	}

}
