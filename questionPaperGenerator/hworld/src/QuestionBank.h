#pragma once
#include "Question.h"

#include <unordered_map>
#include <vector>
#define CacheHashMap std::unordered_map<size_t,std::vector<questionId>> 

//using CacheHashMap = std::unordered_map<size_t,std::vector<questionId>> ;

class QuestionBank{
private:
	std::unordered_map <questionId, Question> allQuestions;
	CacheHashMap subjectCache;
	CacheHashMap topicCache;
	CacheHashMap difficultyCache;
	CacheHashMap marksCache;
    
    const std::vector<questionId>* lookupInCache(const std::string name, const CacheHashMap& Cache) const;
public:
public:
/** FINDERS */
	const std::vector<questionId>* findSubject   (const std::string name) const;
	const std::vector<questionId>* findTopic     (const std::string name) const;
	const std::vector<questionId>* findDifficulty(const std::string name) const;
	const std::vector<questionId>* findMarks     (const std::string name) const;
    /** FINDERS */

    QuestionBank(){}

	void printQuestion(const questionId qid) const;

	void updateAllCache(const Question &q);
	void addQuestion(Question &&q){
		allQuestions[q.qid]=(q); // insert in questions
		updateAllCache(q);
	}
	// TODO put more features like modify, remove questions

};




/************************************************************************************************
 * 
 * 
 * 
 * 
 *  cpp content *
 * 
 * 
 * 
 * 
 ********************************************************************************************** */

using namespace std;
const std::vector<questionId>* QuestionBank::lookupInCache(const std::string name, const CacheHashMap& Cache) const{
	size_t key = std::hash<std::string>{}(name);
	auto found = Cache.find(key);
	if( found != Cache.end()){
		return &found->second;
	}
	return nullptr;
}
const std::vector<questionId>*  QuestionBank::findTopic(const std::string name)const{
    size_t key = std::hash<string>{}(name);
    auto found = this->topicCache.find(key);
    if( found != this->topicCache.end()){
        return & found->second;
    }
    std::cerr<< "Exception:: topic " << name << " can't be found";
    return nullptr;
}


const std::vector<questionId>* QuestionBank::findSubject(const std::string name)const{
    auto found = this->lookupInCache(name, this->subjectCache);
    if(!found)      std::cerr<< "Exception:: Subject " << name << " can't be found";
    return found;
}
const std::vector<questionId>* QuestionBank::findDifficulty(const std::string name)const{
    auto found = this->lookupInCache(name, this->difficultyCache);
    if(!found)      std::cerr<< "Exception:: Difficulty " << name << " can't be found";
    return found;
}
const std::vector<questionId>* QuestionBank::findMarks(const std::string name)const{
    auto found = this->lookupInCache(name, this->marksCache);
    if(!found)      std::cerr<< "Exception:: Marks " << name << " can't be found";
    return found;
}

void  QuestionBank::printQuestion(const questionId qid) const{
    auto found = allQuestions.find(qid);
    if(found != allQuestions.end())	std::cout << found->second.text << "\t\t marks: " << found->second.marks << endl;
    else 							std::cerr << "question id not found " << qid << endl;
}

// logic optimization needed in below method
void QuestionBank::updateAllCache(const Question &q){
	const questionId quesId = q.qid;
	if(!q.subject.empty()){
		size_t key = std::hash<string>{}(q.subject);
		auto updationPoint = subjectCache.find(key);
		if(updationPoint != subjectCache.end()){ // subject exists
			updationPoint->second.push_back(quesId);
		}
		else {
			subjectCache[key ] = vector<questionId>{quesId};
		}
	}

	if(!q.topic.empty()){
		size_t key = std::hash<string>{}(q.topic);
		auto updationPoint = topicCache.find(key);
		if(updationPoint != topicCache.end()){ // subject exists
			updationPoint->second.push_back(quesId);
		}
		else{
			topicCache[key] = vector<questionId>{quesId};
		}
	}

	if(!q.difficulty.empty()){
		size_t key = std::hash<string>{}(q.difficulty);
		auto updationPoint = difficultyCache.find(key);
		if(updationPoint != difficultyCache.end()){ // subject exists
			updationPoint->second.push_back(quesId);
		}
		else{
			difficultyCache[key] = vector<questionId>{quesId};
		}
	}

	{ // for marks, no hashing required
		size_t key = (q.marks);
		auto updationPoint = marksCache.find(key);
		if(updationPoint != marksCache.end()){ // subject exists
			updationPoint->second.push_back(quesId);
		}
		else{
			marksCache[key] = vector<questionId>{quesId};
		}
	}

}
