// Range the elements of an array so that all zeroes are at the end of the array,
// while preserving the ordering of the nonzero elements.
#include <iostream>
#include <vector>
using namespace std;


void sweepZeroesToEnd(vector<int>& input){
    size_t i=0;
    for(size_t j=0; j<input.size(); ++j){
        if(input.at(j) != 0 ){
            input.at(i) = input.at(j);
            i++; // increment write position
        }
    }
    while(i < input.size()){
        input.at(i++) = 0; // fill with zero to the last...
    }
}


int main(){
    vector<int> in = {2,3,0,1,0,2,54,42,12,0,5,0,10};
    sweepZeroesToEnd(in);
    for(auto& val : in) {cout<<val<< " ";}

    return 0;
}