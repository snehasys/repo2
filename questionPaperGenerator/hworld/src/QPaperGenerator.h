#include <functional>
#include <set>
#include <algorithm>
#include <iostream>

#include "QuestionBank.h"

using namespace std;
class QPaperGenerator{ // TemplateAttribs // question paper generator
public:
   int marks;
   //          Topic             40%:OS, 60%:Algo
   vector<pair<string, vector<pair<int, string>>>> measures;
    
    vector<questionId> runOnQuestionBank(const QuestionBank qb); //                the  generator
};



/****
 * 
 * 
 * 
 * cpp implementations*
 * 
 * 
 * **/

vector<questionId> QPaperGenerator::runOnQuestionBank(const QuestionBank qb){ 
    /// TODO :: add code to filter percentage branch tree on marks for each types

    std::cout<< "<<runOnQuestionBank>>"<<std::endl;

    vector<questionId> result;
    vector<questionId> goodCandidates;
    for (auto subMeasures: measures){
        string subMeasureName = subMeasures.first;
        std::cout<<"subMeasureName: "<< subMeasureName <<std::endl;

        for (auto item: subMeasures.second){
            if(subMeasureName == "Topic" ){
                string key = (item.second);
                auto found = qb.findTopic(key); //qb.topicCache.find(key);
                if(found){
                    goodCandidates.insert (goodCandidates.end(), found->begin(), found->end()); // insert whatever is found
                }
            }
            else if(subMeasureName == "Difficulty" ){
                // std::cout<< item.second <<std::endl;
                string key = (item.second);
                // std::cout<< item.second<<std::endl;
                auto found = qb.findDifficulty(key);
                if(found){
                    goodCandidates.insert (goodCandidates.end(), found->begin(), found->end());
                }
            }
            else if(subMeasureName == "Subject" ){
                string key = (item.second);
                auto found = qb.findSubject(key);
                if(found){
                    goodCandidates.insert (goodCandidates.end(), found->begin(), found->end());
                }
            }
            else if(subMeasureName == "Marks" ){
                string key = (item.second);

                auto found = qb.findMarks(key);
                if(found){
                    goodCandidates.insert (goodCandidates.end(), found->begin(), found->end());
                }
            }
            else
            {
                std::cerr<< "unknown measure name: " << subMeasureName << std::endl;
            }
            
        }

        if(result.empty()) result=goodCandidates;
        std::sort (goodCandidates.begin(), goodCandidates.end());
        std::sort (result.begin(),result.end());
        
        // TODO the matching algorithm, is based on intersection. Refine it with tree...
        std::set_intersection (goodCandidates.begin(), goodCandidates.end(),
                                        result.begin(),result.end(),
                                        result.begin());
    }
    return goodCandidates;
}// end method 