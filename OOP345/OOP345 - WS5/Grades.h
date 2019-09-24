#pragma once
#include <iomanip>
#include <string>
#include "Letter.h"

using namespace std;

namespace sict
{
	class Grades {


		double* grades;
		string* student;
		size_t counter=0;



	public:
		Grades(char* filename); 

		template <typename F>
		void displayGrades(ostream& os, F letterGrade) const
		{
			os << fixed;
			os << setprecision(2);
			for (int i = 0; i < counter; i++)
			{

				os << student[i] << " ";
				os << grades[i] << " ";
				os << convert(letterGrade(grades[i])) << endl;

			}
		}



	};




}
