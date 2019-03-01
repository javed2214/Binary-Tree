// Evaluation of Expression Tree
// In Epression Tree each Internal Node Corresponds to an Operator and each Leaf Node Corresponds to Operand

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	string data;
	struct node *left;
	struct node *right;
}node;

node *createNode(string n){

	node *root=new node;
	root->data=n;
	root->left=NULL;
	root->right=NULL;

	return root;
}

void inOrder(node *root){

	if(root){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

int evalFunction(node *root){

	if(root==NULL) return 0;

	if(root->left==NULL and root->right==NULL)
		return stoi(root->data);	// String to Integer Conversion

	int l_val=evalFunction(root->left);
	int r_val=evalFunction(root->right);

	if(root->data=="+")
		return (l_val+r_val);
	if(root->data=="-")
		return (l_val-r_val);
	if(root->data=="*")
		return (l_val*r_val);
	return (l_val/r_val);
}

int main(){

	node *root=createNode("+");
	root->left=createNode("*");
	root->right=createNode("-");
	root->left->left=createNode("5");
	root->left->right=createNode("4");
	root->right->left=createNode("100");
	root->right->right=createNode("10");

	inOrder(root);
	cout<<"\n";

	cout<<evalFunction(root);

	return 0;
}