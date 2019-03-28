#pragma once

#include <iostream>


using namespace std;

template <typename T, size_t N>

class List
{
	T Array[N];
	size_t count;

public:

	List() : count(0) { };

	size_t size() const

	{
		return count;
	};

	const T& operator[](int index) const

	{
		return Array[index];

	};

	void operator+=(const T& elem)

	{
		if (count < N)
		{
			Array[count] = elem;
			count++;
		}


	}

};


