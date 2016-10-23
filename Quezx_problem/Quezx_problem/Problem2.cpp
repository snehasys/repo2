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

#include "stdafx.h"
#include "Problem2.h"

void Student::set_data(std::string name, unsigned int mark)
{
	this->name = name;
	this->marks= mark;
}
std::string Student::getName(){
	return this->name;
}

/*
* @brief: Implements the recursive Quicksort method
*/
bool Problem2::sortify(std::vector<Student>&list, int low_index, int high_index )
{
	if(high_index > low_index) //terminator condition
	{
		int pivot = partiton(list, low_index, high_index);
		sortify( list, low_index, pivot-1);
		sortify( list, pivot+1, high_index);

	}
	return true; //base case
}

/*
* @brief: The main interface of this problem
*/
void Problem2::sort_name_by_marks()
{
	std::vector<Student> list;
	populate_data( list );

	sortify(list, 0, list.size()-1 );

	display_sorted_name_desc(list);
}


Problem2::Problem2(void)
{
}


Problem2::~Problem2(void)
{
}

void Problem2::populate_data(std::vector<Student> &list)
{
//	Student s1("raj",10);
//	list.push_back(s1);
//	Student s2("simran",12);
//	list.push_back(s2);
//	Student s3("vinod",8);
//	list.push_back(s3);
	Student s;
	int count;
	std::cout<<"How many students:";
	std::cin >> count;
	while(count > 0)
	{
		std::string name;
		unsigned int mark;
		std::cout<<"\nStudent name:";
		std::cin >> name;
		std::cout<< name <<"'s obtained marks:";
		std::cin >> mark;

		s.set_data(name, mark);
		list.push_back(s);
		count--;
	}
}
int Problem2::partiton(std::vector<Student>&list,int low_index, int high_index)
{
	int left  = low_index ;
	int right = high_index;
	Student pivot_item = list[low_index];
	while(left < right)
	{
		while( left<list.size() && list[left] <= pivot_item)
		{
			++left; // shift left by one 
		}
		while(list[right] > pivot_item)
		{
			--right; //shift right by one 
		}
		if(right > left)
		{
			list[left] ^ list[right]; //SWAP left with right (NOTE: I have overloaded '^' as the swap operator)
		}
	}//end while
	list[low_index] = list[right];
	list[right]     = pivot_item ;
	return right;	//right should be the final position of the pivot
}


void Problem2::display_sorted_name_desc( std::vector<Student>  &list)
{
	for(int i = list.size()-1; i>=0 ; i--)
		std::cout << list[i].getName()<<std::endl;
}

