
#include "SavingsAccount.h"

using namespace std;

namespace sict {

	SavingsAccount::SavingsAccount(double bal, double rate) : Account(bal) {

		this->IntRate(rate);
	}

	void SavingsAccount::monthEnd() {

		double interest = 0;
		interest = this->balance() * this->IntRate();
		this->credit(interest);

	}

	// TODO: display inserts the account information into an ostream			

	void SavingsAccount::display(std::ostream& disp) const {

		disp << "Account type: Savings" << endl;
		disp.setf(ios::fixed);
		disp.precision(2);
		disp << "Balance: $" << this->balance() << endl;
		disp << "Interest Rate (%): " << (this->IntRate() * 100) << endl;

	}

	void SavingsAccount::IntRate(const double bal) {
		if (bal < 0) {
			this->_intRate = 0;
		}

		else {

			this->_intRate = bal;
		}
	};

	double SavingsAccount::IntRate() const {

		return this->_intRate;
	};
}