#include <iostream>
#include <fstream>
#include <string>
#include "Grades.h"

using namespace std;



namespace sict
{

	Grades::Grades(char* filename)
	{

		ifstream file(filename);

		if (!file.is_open())
		{
			throw "Error";
		}
		string tmp;

		while (getline(file, tmp))
		{
			counter++;
		}

		file.close();
		
		ifstream newFile(filename);

		grades = new double[counter];
		student = new string[counter];

		for (size_t i = 0; i < counter; i++)
		{
			getline(newFile, tmp);

			{
				size_t index = tmp.find(' ');
				student[i] = tmp.substr(0, index);
				grades[i] = stod(tmp.substr(index + 1, '\n'));

			}
		}

	}

}
