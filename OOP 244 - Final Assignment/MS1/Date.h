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
#ifndef AMA_DATE_H
#define AMA_DATE_H
#include <iostream>


namespace AMA {

	const int min_year = 2000;
	const int max_year = 2030;
	const int NO_ERROR = 0; // No error - the date is valid
	const int CIN_FAILED = 1; // istream failed on information entry
	const int YEAR_ERROR = 2;  // Year value is invalid
	const int MON_ERROR = 3; // Month value is invalid
	const int DAY_ERROR = 4; // Day value is invalid

  class Date {

	  int mmonth; // 2 digits value between 1 and 12 inclusive
	  int myear; // 4 digits value between min_year and max_year 
	  int mday;
      int mdays(int, int)const; //2 digits value between 1 and the number of days in the month
	  int merrorCode;

      void errCode(int errorCode); //sets the error state variable to one of the values listed above
      int comparator() const;

  public:

	  Date(); //default constructor initializes the object to a safe empty state and sets the error state to NO_ERROR.
	  Date(int year, int month, int day); //3-parameter constructor checks if each number is in range, in the order of year, month and
                                         //day.If any of the numbers are not within range, this function sets the error state to the
		                                //  appropriate error code and stops further validation.
	  

	  bool operator==(const Date& rhs) const; 
	  bool operator!=(const Date& rhs) const;
	  bool operator<(const Date& rhs) const;
	  bool operator>(const Date& rhs) const;
	  bool operator<=(const Date& rhs) const;
	  bool operator>=(const Date& rhs) const;

	  int errCode() const; // returns the error state as an error code value.
	  bool bad() const; // returns true if the error state is not NO_ERROR.

	  std::istream& read(std::istream& istr);
	  std::ostream& write(std::ostream& ostr) const;
 
  };


  std::ostream& operator << (std::ostream& ostr, const Date& date);
  std::istream& operator >> (std::istream& istr, Date& date);


}
#endif