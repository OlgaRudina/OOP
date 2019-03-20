
#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include "iAccount.h"

namespace sict {

	const double intRate = 0.05;
	const double TFEE = 0.50;
	const double MFEE = 2.00;

	class Account : public iAccount
	{

		double inBalance;

	protected:

		double balance() const; // returns the current balance of the account.
		void balance(const double);

	public:

		Account();

		// TODO: constructor initializes account balance, defaults to 0.0 
		
		Account(double);

		// TODO: credit adds +ve amount to the balance 

		bool credit(double);

		// TODO: debit subtracts a +ve amount from the balance

		bool debit(double);

	};


}
#endif
