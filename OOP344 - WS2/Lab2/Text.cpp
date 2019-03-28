#include <iostream>
#include <fstream>
#include <string>
#include "Text.h"

namespace w2

{
	// Accepts a filename and set to safe-empty
	Text::Text(std::string file) : _count(0),
		_strptr(new std::string[_count]),
		_fname(file)
	{

		if (!_fname.empty())
		{
			countLines();
			readFile();
		}
	}

	// Read file into std::string::m_StringPtr
	void Text::readFile()
	{
		std::string buf;							
		std::ifstream file(_fname);
		int i = 0;

		_strptr = new std::string[_count];		

		while (std::getline(file, buf))				
		{
			_strptr[i] = buf;
			i++;
		}
	}

	// Counts how many lines are in the file
	void Text::countLines()
	{
		std::ifstream file(_fname);
		std::string buf;

		while (std::getline(file, buf))
			_count++;
	}

	// copies the elements from other into 'this'
	Text::Text(const Text& other)
	{
		*this = other;
	}

	// Copy Assignment Operator
	Text& Text::operator=(const Text& old)
	{
		// Shallow Copy
		_count = old._count;
		_fname = old._fname;

		if (this != &old)
		{
			
			delete[] _strptr;
			_strptr = new std::string[_count];

			// Deep copy - copies the content of the resource not just the address
			for (size_t i = 0; i < _count; i++)
				_strptr[i] = old._strptr[i];
		}
		return *this;
	}

	// Move Constructor
	Text::Text(Text&& src)
	{
		*this = std::move(src);
	}

	// Move operator
	Text& Text::operator=(Text&& src)
	{
		if (this != &src)
		{
			_fname = src._fname;
			_count = src._count;


			delete[] _strptr;

			_strptr = src._strptr;
			src._strptr = nullptr;
		}
		return *this;
	}

	// Destructor
	Text::~Text()
	{
		delete[] _strptr;
		_strptr = nullptr;
	}

	// Return size of Count
	size_t Text::size() const
	{
		return _count;
	}
}