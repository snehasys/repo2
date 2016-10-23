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
#include "stdafx.h"
#include "Problem1.h"

#include <iostream>
#include <string>
#include <cassert>

#define SPACE_ " "

std::string Problem1::getGap(unsigned int lines)
{
	std::string gap;
	while(gap.size() < (lines /2) + 1)
		gap += SPACE_;
	return gap;
}


void Problem1::make_fibonacci_pyramid(long long int rows)
{	
	if(rows < 1)
	{
		std::cerr << "Cannot compute fibonacci series for row value: "<< rows;
		return;
	}
	unsigned int r = rows, old_data = 0, new_data = 1;//, current_line = 1;
	std::string gap = getGap(rows);

//	(rows > 4) ? gap = SPACE_ SPACE_ : gap = SPACE_;

	while (r > 0)
	{
		auto current_line = rows - r + 1;
		auto space = r;
		while (space > 1) /// Initial balancing spaces
		{
			std::cout << gap;
			space--;
		}
		auto new_gap = gap;
		for(auto i=0; i< current_line; ++i)
		{
			auto moreSPACE_s = std::to_string(new_data).size() /2 ;// get the printable length of new_data
			auto size_ = gap.size() - moreSPACE_s;
			assert( size_ >=0 );
			new_gap.resize(size_);

			std::cout << new_gap << new_data << new_gap ; // Print the number 
			auto tmp = new_data;
			new_data += old_data;
			old_data = tmp;
		}
		std::cout<<std::endl;
		r--;
	}// end while

}


Problem1::Problem1(void)
{
}


Problem1::~Problem1(void)
{
}