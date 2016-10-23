// Quezx_problem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Problem1.h"
#include "Problem2.h"
#include "Problem3.h"



int _tmain(int argc, _TCHAR* argv[])
{
	Problem1 p1;
	p1.make_fibonacci_pyramid(13);
	printf("\n\n");

	Problem2 p2;
	p2.sort_name_by_marks();
	printf("\n\n");

	Problem3 p3;
	p3.display_UnoCoin_Sequence(116);
	printf("\n\n");

	std::system("pause");
	return 0;
}