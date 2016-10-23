/*
//Quezx_problem2

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
*/

#pragma once
#include "stdafx.h"
#include <iostream>
#include <vector>

class Student
{	
private:
	std::string name;
	unsigned int marks;

public:
	Student(void)
	{
	}
	
	Student(std::string name, unsigned int mark)
	{
		this->name = name;
		this->marks= mark;
	}
	inline bool operator> ( const Student& right_hand_side)
	{
		if (this->marks > right_hand_side.marks)
			return true;
		else
			return false;
	}
	inline bool operator<= ( const Student& right_hand_side)
	{
		if (this->marks <= right_hand_side.marks)
			return true;
		else
			return false;
	}	
	/*
	* @breif: the Swap operator ^ overload
	*/
	inline void operator^ ( Student& right_hand_side)  // the $wap(swap) overload
	{
		auto temp_name = right_hand_side.name ;		//save backup
		auto temp_mark = right_hand_side.marks;		//save backup

		right_hand_side.name  = this->name ;		//copy (this) to right
		right_hand_side.marks = this->marks;		//copy (this) to right

		this->name 	= temp_name;			//copy temp to (this)
		this->marks = temp_mark;			//copy temp to (this)

		return ;	//return success
	}

	void set_data(std::string name, unsigned int mark);
	std::string getName();
	
};


class Problem2
{
public:
	Problem2(void);
	~Problem2(void);
	void populate_data(std::vector<Student> &list);
	void display_sorted_name_desc( std::vector<Student>  &list);
	
	/*--------------------------------------------------------------------
	* @brief: Main interface of this class
	*/
	void sort_name_by_marks();
	// -------------------------------------------------------------------

	int partiton(std::vector<Student>&list,int low_index, int high_index);
	/*
	* @brief: Implements the recursive Quicksort method
	*/
	bool sortify(std::vector<Student>&list, int low_index, int high_index );

};

