/* fastDelete Duplicates from a sorted array */
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <assert.h>
using namespace std;


void deleteDuplicates(vector<int>& sortedInput){
    size_t i=0, prev=0, j=1;
    while(j<sortedInput.size()){
        if(sortedInput[prev] != sortedInput[j]){
            ++i;
            sortedInput[i] = sortedInput[j];
        }
        prev = j;
        ++j;
    }
    sortedInput.resize(++i);
}

bool isEqual(vector<int>v, set<int>s){
    if(v.size() != s.size()) return false;
    int i= 0;
    for(auto& si:s){
        if(si != v[i++]) return false;
    }
    return true;
}

int main(){
    vector<int> in = {2,3,0,1,0,2,54,42,12,0,5,10,10,42,3 , 54};
    set<int> set_in= std::set<int>(in.begin(), in.end());

    std::stable_sort(in.begin(),in.end());
    
    for(auto& val : in) {cout<<val<< " ";}
    cout <<endl<<endl;
    deleteDuplicates(in);
    for(auto& val : in) {cout<<val<< " ";}
    (isEqual(in, set_in))? cout<<"Test passed": cerr<<"Test failed";
    int i;
    // cin>>i;
    return 0;
}