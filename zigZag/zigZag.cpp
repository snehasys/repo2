// Print binary tree in zinzag snake pattern
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class node{
  public:
  char data;
  node *lChild, *rChild;
  node(char d){
    data=d;    lChild = nullptr;    rChild = nullptr;
  }
};

void printSnakeTraverse(node *root){ 
  std::stack<char> s;
  std::queue<std::pair<node*,size_t>> q;
  q.push(make_pair(root, 0 )); // set initial level as 0

  while(!q.empty())
  {
    std::pair<node*,size_t> item = q.front();
    const size_t lvl = item.second;
    q.pop();
    if(item.first == nullptr) continue;
    
    if(lvl%2 == 0){ // time to print left to right
        while(!s.empty()){ // before printing, first unroll the previous level's stack
            std:: cout << s.top();    s.pop();
        }
        // now print current level
        std:: cout << item.first->data;// << "{" << lvl << "}";
    }
    else{ //keep pushing into stack
      s.push(item.first->data);
    }
    q.push(make_pair(item.first->lChild, lvl+1)); // typical BFS Stuff
    q.push(make_pair(item.first->rChild, lvl+1)); // typical BFS Stuff
  }
  while(!s.empty()){ // unroll if anything is left, in the end
        std:: cout << s.top();    s.pop();
  }
}
 
node* initBT_UT1(){
  node* root = new node('A');
  root->lChild= new node('B');
  root->rChild= new node('C');  
  root->lChild->lChild = new node('D');
  root->lChild->rChild = new node('E');
  root->rChild->lChild = new node('F');
  root->rChild->rChild = new node('G');
  
  root->lChild->lChild->lChild = new node('H');
  root->lChild->lChild->rChild = new node('X');
  root->rChild->rChild->lChild = new node('Y');
  root->rChild->rChild->rChild = new node('I');
  return root;
}
 
/*     A
//    / \
//    B  C
//   /\  /\
//   D E F G
//  /\     /\
// H  X    Y I
 ZigZag traversal of above tree, should yield the below: */
//ACBDEFGIYXH

int main() {
  //auto words = { "Hello, ", "World!", "\n" };
  /*for (const string& word : words) {
    cout << word;
  }*/
  auto root = initBT_UT1();
  printSnakeTraverse(root);
  return 0;
}
