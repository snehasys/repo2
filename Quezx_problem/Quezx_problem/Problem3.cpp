/*
//Quezx_problem3

Q3. Write a program that prints the numbers from 1 to n (n is the input from user).
But for multiples of two print “Uno” instead of the number and for the multiples of
three print “Coin”. For numbers, which are, multiples of both two and three print
“UnoCoin”.
For example:
Input:
n = 10
Output:
1, Uno, Coin, Uno, 5, UnoCoin, 7, Uno, Coin, Uno
(1, 2 , 3   , 4  , 5,      6 , 7,  8 ,   9 , 10 ) <–---- Do not print this line, it is only for
your reference, so you understand what you required to print in place of the number.

*/

#include "stdafx.h"
#include "Problem3.h"
#include <iostream>

bool Problem3::display_UnoCoin_Sequence(int limit)
{
	if(limit < 0)
		std::cerr<< "Negatives not supported for the sequence";

	for(auto iterator = 1; iterator <= limit; ++iterator )
	{
		bool not_divisible = true;
		if(!( iterator %2 )) // true, if 'iterator' is divisible by 2
		{
			std::cout << "Uno";
			not_divisible = false;
		}
		if(!( iterator %3 )) // true, if 'iterator' is divisible by 3
		{
			std::cout << "Coin";
			not_divisible = false;
		}
		if(not_divisible)
		{
			std::cout << iterator;
		}
		if(iterator != limit)
			std::cout << ", ";
	}// end for
	return true;
}


Problem3::Problem3(void)
{
}


Problem3::~Problem3(void)
{
}
