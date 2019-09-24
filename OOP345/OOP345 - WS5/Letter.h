#pragma once
#include <cstring>


namespace sict
{

	enum class Letter {
		A_Plus,
		A,
		B_Plus,
		B,
		C_Plus,
		C,
		D_Plus,
		D,
		F,


	};


	template <typename T>
	const char* convert(const T& score)
	{
		const char * grade;
		switch (score)
		{
		case Letter::A_Plus:
			grade = "A+"; 
			break;

		case Letter::A:
			grade = "A"; 
			break;

		case Letter::B_Plus:
			grade = "B+"; 
			break;

		case Letter::B:
			grade = "B"; 
			break;

		case Letter::C_Plus:
			grade = "C+";
			break;

		case Letter::C:
			grade = "C"; 
			break;

		case Letter::D_Plus:
			grade = "D+"; 
			break;

		case Letter::D:
			grade = "D"; 
			break;

		case Letter::F:
			grade = "F"; 
			break;

		default:
			grade = "n\a";
			break;
		}
		return grade;

	}



}
