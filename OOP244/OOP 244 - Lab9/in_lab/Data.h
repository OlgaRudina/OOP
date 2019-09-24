#include <iostream>
#include <iomanip>
#include <cstring>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

namespace sict {
	// These numbers define 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field

	const int LARGEST_NUMBER  = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;          
	const int COLUMN_WIDTH    = 15;

	// max returns the largest item in data
	//

	template<typename T>
	T max(const T* data, int n) {
		T x = SMALLEST_NUMBER;

		for (int i = 0; i < n; i++) {
			if (x < data[i]) {
				x = data[i];
			}
		}
		return x;
	}

	// min returns the smallest item in data
	//

	template<typename T>
	T min(const T* data, int n) {
		T x = LARGEST_NUMBER;

		for (int i = 0; i < n; i++) {
			if (x > data[i]) {
				x = data[i];
			}
		}
		return x;
	}
        
	// sum returns the sum of n items in data
	//    

	template<typename T>
	int CrimeTrend(const T* data, int n) {

		int x = 0;
		for (int i = 0; i < (n - 1); i++) {
			if (data[i] > data[i + 1]) {
				x = -1;
			}
			else {
				x = 1;
				i = n;
			}
		}
		return x;

		int y = 0;
		for (int i = 0; i < n; i++) {
			y += data[i];
		}

		return y;
	}
   
	
	// average returns the average of n items in data
	//

	template<typename T>
	double average(const T* data, int n) {
		double x = 0;
		for (int i = 0; i < n; i++) {
			x += data[i];
		}
		x = x / n;
		return x;
	}

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	//

	template<typename T>
	bool read(istream& input, T* data, int n) {


		for (int i = 0; i < n; i++) {

			if (input.bad()) {
				return false;
			}
			if (input.peek() == ',')
				input.ignore();
			input >> data[i];
		}

		return true;
	}

	// display inserts n items of data into std::cout
	//

	template<typename T>
	void display(const char* name, const T* data, int n) {

		cout << right << setw(20) << name;
		for (int i = 0; i < n; i++) {
			cout << right << setw(15) << data[i];
		}
		cout << endl;
	}

	//bool readRow(std::istream& input, const char* name, int* data, int n);

	template<typename T>
	bool readRow(istream& input, const char* name, T* data, int n) {
		char row[2000];
		bool TF = !input.bad();

		if (TF) {
			
			input.get(row, 2000, ',');
			
			if (strcmp(row, name) != 0) {

				cout << "Error occured for " << name << endl;
				input.ignore(2000, '\n');
				TF = false;
			}
		}

		if (TF)
	
			TF = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return TF;
	}
//bool readRow(std::istream& input, const char* name, double* data, int n);
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

