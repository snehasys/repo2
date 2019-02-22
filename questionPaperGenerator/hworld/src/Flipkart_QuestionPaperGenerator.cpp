//============================================================================
// Name        : QuestionPaperGenerator.cpp
// Author      : Sne
// Version     :
// Copyright   : Your copyright notice
// Description :  C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <set>

#include "Question.h"
#include "QuestionBank.h"
#include "QPaperGenerator.h"

using namespace std;


//////////////////////////////
// Driver function.. Unit test 1
int main() {
    cout << "Question Paper Generator" << endl;
    QuestionBank qb;
	// Question(std::string text, int marks, std::string difclty, std::string topic)
    qb.addQuestion( Question("What is virtual memory??", 4,"easy","OS"));
    qb.addQuestion( Question("What is priority queue??", 5, "hard", "DS"));
    qb.addQuestion( Question("What is VTable??", 3, "easy", "C++"));
    qb.addQuestion( Question("What is Dynamic casting??", 5, "hard", "C++"));
    qb.addQuestion( Question("Explain an LRU cache ??", 10, "hard", "DS"));
	
	
   QPaperGenerator tpl;
   tpl.marks = 100;
//    vector<pair< string, vector<pair<int, string>>>> measure;
   tpl.measures.push_back(make_pair("Topic", vector<pair<int, string>>{
                                                                     make_pair(30, "OS")
	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   , make_pair(70, "DS")}));
   tpl.measures.push_back(make_pair("Difficulty", vector<pair<int, string>>{
                                                                     make_pair(50, "easy")
	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   , make_pair(50, "hard")}));


   std::vector<questionId> matchingQids = tpl.runOnQuestionBank(qb);
   std::set<questionId> uniques(matchingQids.begin(), matchingQids.end());

   if(!matchingQids.empty()){
	   for(questionId qid : uniques)	qb.printQuestion(qid);
   }
   else{
     cout<< " No matches!";
     }
		 int t;
		 cin>>t;
    return 0;
}

// bhargav.naik@flipkart.com
