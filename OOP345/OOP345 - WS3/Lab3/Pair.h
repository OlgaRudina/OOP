#pragma once

#include <iostream>

using namespace std;

template <typename A, typename B>

class Pair

{
	A one;
	B two;

public:

	Pair(){};

	Pair(const A& value1, const B& value2)
	{
		one = value1;
		two = value2;
	};

	const A& getKey() const
	{
		return one;
	};

	const B& getValue() const
	{

		return two;
	}


};