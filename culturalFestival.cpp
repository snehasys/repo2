/*
	****PROBLEM STATEMENT****
*	A cultural festival is going to be organized in Hacker Society on the day of Holi .The head of the society needs some 
*	Poets,Dancers and some Musicians to perform in this event. He decides to interview N number of people who live in the
*	society. Each one has ratings in all the three fields. He wants to choose right guys for the right job so that the 
*	festival can be celebrated in the best possible way.Thus he selects P Poets,D Dancers and M Musicians. Help him in 
*	organizing the event.
*
*	The strength of Cultural Festival is the sum of ratings of the people in the corresponding field.
*	You have to maximize the sum of their ratings.
*
*	Input Format::
*	First line contains 4 integers N,P,D,M.
*	Next 3 lines contain 3 arrays each of size N denoting the rating of the person in the corresponding field.
*       The first one is the ratings of N people on their poetry skill, next on their dancing skill and the third one
*       on their music skills.
*
*	Output Format::
*	Print an integer denoting the maximum sum of ratings that can be obtained
*
*	SAMPLE INPUT::
*	3 1 1 1
*	1 2 3
*	1 3 3
*	4 5 6
*
*	SAMPLE OUTPUT::
*	10
*
*	Explanation::
*	Choose the 1st person for Poetry , 2nd for Dancing and 3rd for Music 1+3+6 =10
*	Or, you can also choose the 3rd person for Poetry , 2nd for Dancing and 1st for Music 4+3+3=10
*/


#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class CompareDist{ //comparator for priority queue
    public: bool operator()(pair<int,size_t> n1, pair<int,size_t> n2) { return n1.first > n2.first;}
};
enum AT {P=0, D=1, M=2}; // ArtistType
///////////////////////////////////////////////////////////////////
/*
*   \brief: Here find the best skill for each Art. Return the sum. and REMOVE the person(s) from skill matrix
*/
int getKmaxSkillSum(vector<vector<int> >& skillMatrix, 
                    const int artistsRequired, // count of artists
                    const AT a) // the artist type. i.e. P,D,M
{
    //     ADT pq   <elements of pq>,<underlying container of pq>,<comparator>  
    priority_queue<pair<int,size_t> , vector<pair<int,size_t> >, CompareDist > topArtists; // this is kind of a maxheap
    set<size_t> tombStoned; //the indexes of shortlisted people will accumulate here (in sorted order)
    
    for(size_t n=0; n<skillMatrix.size(); ++n){
        const int nthGuySkill = skillMatrix[n][a];
        topArtists.push(make_pair(nthGuySkill, n));
    }// gathered in max heap
    // now the top k people are the highest rated ones, due to the maxheap property of priority queue
    int k = artistsRequired;
    int maxSkill = 0;
    while(k--){ // do it for top k peoples
        auto top = topArtists.top();
        maxSkill += top.first;
        tombStoned.insert(top.second); // store the people who are selected
//        cout << topArtists.top()<<endl;
        topArtists.pop();
    }
	/// Here we remove the already sortlisted people for next talentHunt
    for(set<size_t>::iterator rit = tombStoned.rbegin(); rit = tombStoned.rend(); rit++){
        size_t removePeople = *rit;
        skillMatrix.erase (skillMatrix.begin()+ removePeople);
    }
    return maxSkill;
}

///////////////////////////////////////////////////////////////
int findBest(const vector<vector<int> >skills, 
         const vector<AT> artistOrder,
         const int poetRequired,
         const int dancerRequired,
         const int musicRequired)
{
    auto tempSkills = skills;
    int sum = 0;
    for(AT artist: artistOrder){
        int howMany = -1;
        switch(artist){
            case P:    howMany = poetRequired;   break;
            case D:    howMany = dancerRequired; break;
            case M:    howMany = musicRequired;  break;
        }
        sum += getKmaxSkillSum(tempSkills, howMany, artist );
    }    
//    cout<<endl<<sum<<" bestSumFound \n\n";
    return sum;
}
 //////////////////////////////////////////////////////
/// read skill matrix from STDIN
void readSkillMatrix(vector<vector<int> >& allSkills){ 
    int i=0;
    while(i < allSkills.size()/*i.e. totalPerson*/){
        int Pskill, Dskill, Mskill;
        cin >> Pskill;
        allSkills[i].push_back(Pskill);
        cin >> Dskill;
        allSkills[i].push_back(Dskill);
        cin >> Mskill;
        allSkills[i].push_back(Mskill);
        ++i;
    }
}
//////////////////////////////////////////////////////////////
int main(){
    int totalPerson;
    cin >> totalPerson;
    int poetRequired, dancerRequired, musicRequired;
    cin>>poetRequired; cin>>dancerRequired; cin>>musicRequired;
        
    vector<vector<int> > allSkills(totalPerson);
    readSkillMatrix(allSkills);
    
    int maxTalentFound = 0;
    
    // six permutations required(at most): i.e. PDM, PMD, MDP, MPD, DPM, DMP
    // find the best result among the above six
    vector<vector<AT> > allPermutations;
    allPermutations.push_back(vector<AT> {AT::P, AT::D, AT::M});
    allPermutations.push_back(vector<AT> {AT::P, AT::M, AT::D});
    allPermutations.push_back(vector<AT> {AT::M, AT::D, AT::P});
    allPermutations.push_back(vector<AT> {AT::M, AT::P, AT::D});
    allPermutations.push_back(vector<AT> {AT::D, AT::P, AT::M});
    allPermutations.push_back(vector<AT> {AT::D, AT::M, AT::P});
    
    for (auto onePattern: allPermutations){
        int currentBestSum = findBest(allSkills, onePattern, poetRequired, dancerRequired, musicRequired);

        if(currentBestSum > maxTalentFound)
            maxTalentFound = currentBestSum;        
    }
    cout << maxTalentFound; // final result to STDOUT
    return 0;
}
