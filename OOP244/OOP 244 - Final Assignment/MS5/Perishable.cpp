#include <iostream>
#include "Perishable.h"

#define _CRT_SECURE_NO_WARNINGS

using namespace std;


namespace AMA
{
	Perishable::Perishable() : Product('P')
	{
		pError.clear();
	}

	std::fstream & Perishable::store(std::fstream & file, bool newLine) const
	{
		Product::store(file, false);
		file << ',' << expDate << endl;
		return file;
	}
	std::fstream & Perishable::load(std::fstream & file)
	{
		Product::load(file);
		expDate.read(file);
		file.ignore();
		return file;
	}
	std::ostream & Perishable::write(std::ostream & os, bool linear) const
	{
		Product::write(os, linear);

		if (isClear() && !isEmpty())
		{
			if (linear)
				expDate.write(os);
			else
			{
				os << "\n Expiry date: ";
				expDate.write(os);
			}
		}
		return os;
	}
	std::istream & Perishable::read(std::istream & is)
	{
		is.clear();
		Product::read(is);

		if (pError.isClear())
		{
			cout << " Expiry date (YYYY/MM/DD): ";
			expDate.read(is);
		}

		if (expDate.errCode() == CIN_FAILED)
		{
			pError.clear();
			pError.message("Invalid Date Entry");
		}

		if (expDate.errCode() == YEAR_ERROR)
		{
			pError.message("Invalid Year in Date Entry");
		}

		if (expDate.errCode() == MON_ERROR)
		{
			pError.clear();
			pError.message("Invalid Month in Date Entry");
		}

		if (expDate.errCode() == DAY_ERROR)
		{
			pError.clear();
			pError.message("Invalid Day in Date Entry");
		}

		if (expDate.errCode())
		{
			is.setstate(std::ios::failbit);
		}

		if (expDate.errCode() != CIN_FAILED && expDate.errCode() != YEAR_ERROR && expDate.errCode() != MON_ERROR && expDate.errCode() != DAY_ERROR)
		{
			pError.clear();
		}

		return is;
	}
	const Date & Perishable::expiry() const
	{
		return expDate;
	}
}