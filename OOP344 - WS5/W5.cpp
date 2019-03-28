// Workshop 5 - Lambda Expression
// 345_w5.cpp
// Chris Szalwinski & Dr. Elliott Coleshill
// 2018-08-22

#include <iostream>
#include <fstream>
#include "Grades.h"
#include "Letter.h"

using namespace sict;

int main(int argc, char* argv[]) {

	std::ofstream ofs("Lab5Output.txt");

	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;

	if (argc == 1) {
		std::cerr << "\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	else if (argc != 2) {
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}

	//Update the main functions as per the specifications here
	auto letter = [](double mark) -> Letter
	{
		Letter Grade;
		if (mark >= 90)
		{
			Grade = Letter::A_Plus;
		}
		else if (mark >= 80)
		{
			Grade = Letter::A;
		}
		else if (mark >= 75)
		{
			Grade = Letter::B_Plus;
		}
		else if (mark >= 70)
		{
			Grade = Letter::B;
		}
		else if (mark >= 65)
		{
			Grade = Letter::C_Plus;
		}
		else if (mark >= 60)
		{
			Grade = Letter::C;
		}
		else if (mark >= 55)
		{
			Grade = Letter::D_Plus;
		}
		else if (mark >= 50)
		{
			Grade = Letter::D;
		}
		else
		{
			Grade = Letter::F;
		}
		return Grade;
	};

	Grades grades(argv[1]);
	grades.displayGrades(ofs, letter);

	ofs.close();
}