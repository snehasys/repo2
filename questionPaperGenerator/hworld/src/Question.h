#pragma once
#include <string>
#include <functional>

// #define questionId  size_t //list<Question>::iterator

using questionId = std::size_t; //list<Question>::iterator

// using namespace std;

class Question{
public:
	questionId qid;
	std::string text;
	std::string subject;
	std::string topic;
	std::string difficulty;
	int marks;
	Question(){}
	Question(std::string text,int marks, std::string difclty, std::string topic)
    {
		this->qid = std::hash<std::string>{}(text + difclty + topic); // create a unique hash to be stored
		this->text= text;
		this->marks = marks;
		this->difficulty = difclty;
		this->topic = topic;
	}
};