========================================================================
    CONSOLE APPLICATION : Quezx_problem Project Overview
========================================================================

Q1. Print Fibonacci series in a pyramid shape.
The user will enter the number of rows and the output should contain those many
rows printing the Fibonacci series.
Example:
Input: 3 (Number of Rows)
Output:
  1
 1 2
3 5 8

Q2. Implement Quicksort algorithm to sort the below problem.
The user will enter the names and marks for students, you will store them in a
dynamic list. The list should be dynamic, the user should be able to add as many
names and marks as he/she wants. You should be able to sort the names based on
their marks they received.
For, example:
Input:
NamesList = {‘raj, ‘ simran’, ‘vinod’}
MarksList = {10, 12 , 8}
Output:
simran
raj
vinod
You must implement the quicksort algorithm to sort the list. DO NOT USE ANY
BUILT IN FUNCTION TO SORT THE LIST.

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

//////////////////////////////////////////
Solution submitted by Snehasish Sarkar
/////////////////////////////////////////////////////////////////////////////////////

Quezx_problem.cpp
    This is the main application source file, for all three problems.
s
Quezx_problem.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

Quezx_problem.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).
/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named Quezx_problem.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////
