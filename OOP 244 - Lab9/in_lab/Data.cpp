#include "Data.h"

using namespace std;
using namespace sict;

namespace sict {
	// readRow extracts a single record from input and stores n data fields in data
	// - includes error checking: checks if the name of the row is valid.
	//
	bool readRow(istream& input, const char* name, double* data, int n) {
		char row[2000];
		bool TF = !input.bad();

		// row format is 
		// name,1,2,3,4,5,6

		if (TF) {
			// read the name  first

			input.get(row, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (strcmp(row, name) != 0) {
				// wrong row
				cout << "Error occured for " << name << endl;
				input.ignore(2000, '\n');
				TF = false;
			}
		}

		if (TF)
			// read the data array
			TF = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return TF;
	}

	bool readRow(istream& input, const char* name, int* data, int n) {
		char row[2000];
		bool TF = !input.bad();

		// row format is 
		// name,1,2,3,4,5,6

		if (TF) {
			// read the name  first

			input.get(row, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (strcmp(row, name) != 0) {
				// wrong row
				cout << "Error occured for " << name << endl;
				input.ignore(2000, '\n');
				TF = false;
			}
		}

		if (TF)
			// read the data array
			TF = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return TF;
	}

	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"

		double inPopulation = (max(population, n) - min(population, n));
		inPopulation = inPopulation / 1000000;
		cout << fixed;
		cout << setprecision(2);
		cout << "Population change from 2000 to 2004 is " << inPopulation << " million" << endl;



		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005

		int inTrend = CrimeTrend(violentCrimeRate, n);
		if (inTrend == -1) {
			cout << "Violent Crime trend is down" << endl;
		}
		else {
			cout << "Violent Crime trend is up" << endl;
		}




		// Q3 print the GTA number accurate to 0 decimal places

		double incidents = average(grandTheftAuto, n) / 1000000;
		cout << fixed;
		cout << setprecision(2);
		cout << "There are " << incidents << " million Grand Theft Auto incidents on average a year" << endl;



		// Q4. Print the min and max violentCrime rates

		int crimeRate = min(violentCrimeRate, n);
		cout << "The Minimum Violent Crime rate was " << crimeRate << endl;

		crimeRate = max(violentCrimeRate, n);
		cout << "The Maximum Violent Crime rate was " << crimeRate << endl;



	}
}