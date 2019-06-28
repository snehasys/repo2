#include<iostream>
#include<stack>

using namespace std;

class node{
public:
	int data;
	node *left,*right;
	
	node(int d){
		data = d;
		left = right = nullptr;
	}
	
};

void inorder(node* t){
	if(t== nullptr)		return;
	inorder(t->left);
	std::cout<<t->data<< " ";
	inorder(t->right);
}

void inorderIterative( node * t){
	stack<node*> stc;
	stc.push(t);
	while (!stc.empty()){
		auto item = stc.top();
		stc.pop();
		if(item != nullptr)
		{
			stc.push(item->right);
			if(item->left == nullptr){
				cout<< item->data << " "; // print current item if there is no left child
			}
			else{
				stc.push(new node(item->data)); // push the current item as to be printed after left proces
				stc.push(item->left);
			}
		}
	}
}

node* createBST(void){
	node* root = new node(20);
	root->left = new node(12);
	root->left->left = new node(2);
	root->left->left->right = new node(10);
	root->left->right = new node(18);
	
	root->right = new node(22);
	root->right->left = new node(21);
	root->right->right = new node(25);
	return root;
}

int main(){
	auto root = createBST();
	inorder(root);
	cout<<endl;
	inorderIterative(root);
	cout<<endl;
	return 0;
}


