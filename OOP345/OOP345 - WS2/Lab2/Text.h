//Lab 2 
//Olga Rudina, 039949136
//21-Sep-18


#pragma once

#include <string>
#include <memory>

using namespace std;

namespace w2 {

	class Text
	{
		string _fname;
		string * _strptr;
		size_t _count;

	public:
		explicit Text(const std::string file = "Unknown");
		void readFile();
		void countLines();
		Text(const Text&);
		Text& operator=(const Text&);
		Text(Text&&);
		Text& operator=(Text&&);
		~Text();

		size_t size() const;
	};

}