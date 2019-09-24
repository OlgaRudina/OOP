#include "Account.h"

using namespace std;

namespace sict {


	Account::Account() {

		balance();
}

	Account::Account(double bal) {

		balance(bal);

		}

	bool Account::credit(double bal) {


		if (bal > 0) {

			this->inBalance += bal;
			return true;
		}

		else {

			return false;
		}
	}

	bool Account::debit(double bal) {
		
		if (bal > 0) {

			this->inBalance -= bal;
			return true;
		}

		else {

			return false;
		}

	}

	double  Account::balance() const {

		return this->inBalance;

	}

	void Account::balance(const double bal) {
		
		if (bal < 0) {
			this->inBalance = 0;
		}
		else {
			this->inBalance = bal;
		}
	}
}
