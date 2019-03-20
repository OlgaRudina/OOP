// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#include <iostream>
#include "Date.h"

namespace AMA {



  // number of days in month mon_ and year year_
  //
  int Date::mdays(int mon, int year)const {
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int month = mon >= 1 && mon <= 12 ? mon : 13;
    month--;
    return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

  //function definitions

  int Date::comparator() const {

	  return myear * 372 + mmonth * 13 + mday;
  }

  Date::Date()   //default constructor initializes the object to a safe empty state and sets the error state to NO_ERROR.
  
  {
	  myear = 0;
	  mmonth = 0;
	  mday = 0;
	  errCode(NO_ERROR);

  };
  

  Date::Date(int year, int month, int day)  //3-parameter constructor checks if each number is in range, in the order of year, month and
									        //day.If any of the numbers are not within range, this function sets the error state to the
									        //  appropriate error code and stops further validation.
 
  {
	  if (year <= max_year && year >= min_year && month <= 12 && month > 0 && day > 0 && day <= 31) {

		  myear = year;
		  mday = day;
		  mmonth = month;
		  errCode(NO_ERROR);
	  }

	  else {

		  myear = 0;
		  mmonth = 0;
		  mday = 0;
		  errCode(NO_ERROR);

	  }
  
  };

  void Date::errCode(int errorCode)  //sets the error state variable to one of the values listed above
  
  {
	  merrorCode = errorCode;
  
  };


  int Date::errCode() const // returns the error state as an error code value.
  
  {
	  return merrorCode;
  }; 

  bool Date::bad() const // returns true if the error state is not NO_ERROR.
  
  {
	  if (merrorCode != NO_ERROR) {
		 
		  return true;

  }

	  else {

		  return false;
	  }

  }; 

  //operator overloading definitions

  bool Date::operator == (const Date& rhs) const 
  {
	  return this->comparator() == rhs.comparator();
};
  bool Date::operator != (const Date& rhs) const 
  
  {
	  return this->comparator() != rhs.comparator();
  };

  bool Date::operator < (const Date& rhs) const 
  
  {
	  return this->comparator() < rhs.comparator();
  };

  bool Date::operator > (const Date& rhs) const 
  
  {
	  return this->comparator() > rhs.comparator();
  };

  bool Date::operator <= (const Date& rhs) const 
  
  {
	  return this->comparator() <= rhs.comparator();
  };

  bool Date::operator >= (const Date& rhs) const 
  
  {
	  return this->comparator() >= rhs.comparator();
  };

  //IO functions definitions

  std::istream& Date::read(std::istream& istr)
  {
  
	  int year, day, month;
	  char delimeter;

	  istr >> year >> delimeter >> month >> delimeter >> day;

	  if (istr.fail()) {
		  
		  merrorCode = CIN_FAILED;
			
	  }

	  else {

		  myear = year;
		  mday = day;
		  mmonth = month;
		  errCode(NO_ERROR);

		  if (year<min_year || year>max_year) {
			  
			  errCode(YEAR_ERROR);
			  myear = 0;
			  mmonth = 0;
			  mday = 0;
		  }

		  else if (month < 1 || month > 12) {
			  errCode(MON_ERROR);
			  myear = 0;
			  mmonth = 0;
			  mday = 0;
		  }

		  else if (day < 1 || day > mdays(month, year)) {

			  errCode(DAY_ERROR);
			  myear = 0;
			  mmonth = 0;
			  mday = 0;

		  }
	  }

	  return istr;
  };

  std::ostream& Date::write(std::ostream& ostr) const
  
  {
	  ostr << myear << '/';
	  ostr.width(2);
	  ostr.fill('0');
	  ostr << mmonth << '/';
	  ostr.width(2);
	  ostr.fill('0');
	  ostr << mday;

	  return ostr;

  };


  std::ostream& operator << (std::ostream& ostr, const Date& date)
  {
	  date.write(ostr);
	  return ostr;
  };

  std::istream& operator >> (std::istream& istr, Date& date)
  {
	  date.read(istr);
	  return istr;
  };

}


