/*
//Quezx_problem1

Q1. Print Fibonacci series in a pyramid shape.
The user will enter the number of rows and the output should contain those many rows printing the Fibonacci series.

Example:
Input: 3 (Number of Rows)
Output:
  1
 1 2
3 5 8

*/

#pragma once
#include "stdafx.h"

class Problem1
{
public:
	Problem1(void);
	~Problem1(void);

	std::string getGap(unsigned int rows);
	void make_fibonacci_pyramid(long long int rows);

};

