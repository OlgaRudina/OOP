
#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__
#include <ostream>
#include "Account.h"

namespace sict {
	class SavingsAccount : public Account

	{
		double _intRate;
		void IntRate(const double);
		double IntRate() const;

	public:
		// TODO: constructor initializes balance and interest rate
		
		SavingsAccount(double, double);

		
		// TODO: perform month end transactions
		
		void monthEnd();

			// TODO: display inserts the account information into an ostream			
	
		void display(std::ostream&) const;
	};
}
#endif
