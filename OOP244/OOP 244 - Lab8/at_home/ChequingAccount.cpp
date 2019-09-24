// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	//

	ChequingAccount::ChequingAccount(double bal, double trans_fee, double month_fee) : Account(bal) {

		this->balance(bal);

		if (trans_fee > 0)
		{
			this->_transFee = trans_fee;
		}

		else {

			this->_transFee = 0;
		}

		if (month_fee > 0)
		{
			this->_monthFee = month_fee;
		}

		else {

			this->_monthFee = 0;
		}
	
	};

	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	//
	bool ChequingAccount::credit(double bal) {

		if (Account::credit(bal)) {

			Account::debit(TFEE);
			return true;
		}

		else {

			return false;
		}
	
	};



	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	//

	bool ChequingAccount::debit(double bal) {
	
		if (Account::debit(bal)) {

			Account::debit(TFEE);
			return true;
		}

		else {

			return false;
		}


	};


	// monthEnd debits month end fee
	//

	void ChequingAccount::monthEnd() {
	
		Account::debit(MFEE);
		Account::debit(TFEE);
	};

	// display inserts account information into ostream os
	//

	void ChequingAccount::display(std::ostream& disp) const {

		disp.setf(ios::fixed);
		disp.precision(2);
		disp << "Account type: Chequing" << endl;
		disp << "Balance: $" << this->balance()<< endl;
		disp << "Per Transaction Fee: " << TFEE << endl;
		disp << "Monthly Fee: " << MFEE << endl;
		disp.unsetf(ios::fixed);
	};

}