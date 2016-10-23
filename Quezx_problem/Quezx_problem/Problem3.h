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

#pragma once
#include "stdafx.h"

class Problem3
{
public:
	Problem3(void);
	~Problem3(void);
	
	bool display_UnoCoin_Sequence(int limit);
};

