// Check Whether Binary Tree is full Binary Tree or Not
// In Full BT all the Nodes have Either Two or Zero Child Nodes

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(int n){

	node *root=(node *)malloc(sizeof(node));
	root->data=n;
	root->left=NULL;
	root->right=NULL;

	return root;
}

bool fullBinaryTree(node *root){

	if(root==NULL) return true;
	if(root->left==NULL and root->right==NULL) return true;
	if(root->left==NULL and root->right!=NULL) return false;
	if(root->left!=NULL and root->right==NULL) return false;
	return fullBinaryTree(root->left) and fullBinaryTree(root->right);
}

int main(){

	node *root=createNode(1);
	root->left=createNode(2);
	root->right=createNode(3);
	root->left->left=createNode(4);
	root->left->right=createNode(5);

	if(fullBinaryTree(root)) cout<<"Yes!\n";
	else cout<<"No\n";

	return 0;
}