#include <iostream>
#include <stack>
#include <queue>
using namespace std;
struct Node{
	int value;
	Node *left;
	Node *right;
	Node(int value):value(value),left(NULL),right(NULL){}
};


//create tree
void inertNode(Node *node,int value){
	if(value <= node->value){
		if(!node->left){
			node->left = new Node(value);
		}else{
			inertNode(node->left,value);
		}
	}else{
		if(!node->right){
			node->right = new Node(value);
		}else{
			inertNode(node->right,value);
		}
	}
}

void inOrder1(Node *node){
	std::stack<Node *> nstack;
	Node *temp = node;
	while(temp || !nstack.empty()){
		if(temp){
			nstack.push(temp);
			temp = temp>left;
		}else{
			temp = nstack.top();
			std::cout << temp->value;
			nstack.pop();
			temp = temp->right;
		}
	}
}

int main(){
	int n;
	while(std::cin >> n){
		n--;
		int value;
		std::cin >> value;
		Node root(value);
		while(n--){
			int newValue;
			std::cin >> newValue;
			inertNode(&root,newValue);
		}

		std::cout << "InOrder is:";
		inOrder1(&root);
		std::cout << std::endl;
	}
}
