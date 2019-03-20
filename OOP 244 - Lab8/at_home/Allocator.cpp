#include "SavingsAccount.h" 
#include "ChequingAccount.h"

namespace sict {


	// TODO: Allocator function
	//

	iAccount* CreateAccount(const char* type, double bal) {

		Account * newAccount = nullptr;

		if (type[0] == 'S') {

			newAccount = new SavingsAccount(bal, intRate);
		}

		else if (type[0] == 'C') {

			newAccount = new ChequingAccount(bal, TFEE, MFEE);
		}

		return newAccount;


	}

}
