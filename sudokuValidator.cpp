/**
  Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx
  The Sudoku board could be partially filled, where empty cells are filled with the character ‘.’ (dot)

  Note:
        A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
**/

#include <vector>
#include <iostream>
#include <string>
#include <set>

using namespace std;

bool isGoodRow(const vector<string> &A, size_t i){
    set<char> uniq;
    string toBeChecked = A.at(i);
    int inserted = 0;
    for(char c:toBeChecked){
        if(c!='.'){
            uniq.insert(c); // insert if not empty cell
            inserted++;
        }
    }
    if(inserted == uniq.size()) return true;
    return false;
}

bool isGoodCol(const vector<string> &A, const size_t j){
    set<char> uniq;
    int inserted = 0;
    for(size_t i=0; i<A.size(); ++i){
        char c = A.at(i).at(j);
        if(c!='.'){
            uniq.insert(c); // insert if not empty cell
            inserted++;
        }
    }
    if(inserted == uniq.size()) return true;
    return false;
}

bool isGoodBox(const vector<string> &A, const size_t x, const size_t y){
    set<char> uniq;
    int inserted = 0;
    for(size_t i=x; i<x+3; ++i){
        for(size_t j=y; j<y+3; ++j){
            char c = A.at(i).at(j);
            if(c!='.'){
                uniq.insert(c); // insert if not empty cell
                inserted++;
            }
        }
    }
    if(inserted == uniq.size()) return true;
    return false;
}

bool isValidSudoku(const vector<string> &A) {
    for (int x = 0; x < A.size(); x++){
        if(!isGoodRow(A,x))  return false;
    }
    for (int y = 0; y < A.at(0).size(); y++){
        if(!isGoodCol(A,y))  return false;
    }

    for (int x = 0; x < A.size(); x+=3){
        for (int y = 0; y < A.at(0).size(); y+=3){
            if(!isGoodBox(A,x,y))  return false;
        }
    }
    return true;
}

int main(){  // UNIT TEST
  vector<string> badInput {"55..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"};
  vector<string> goodInput{"53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"};
  cout<<"isValidSudoku: "<<isValidSudoku(badInput)<<endl;
  cout<<"isValidSudoku: "<<isValidSudoku(goodInput)<<endl;
  return 0;
}
