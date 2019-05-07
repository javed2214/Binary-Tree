// Program to Check Whether the Tree is Continuous or Not
// A tree is Continuous tree if in each root to leaf path, absolute difference between keys of two adjacent is 1
// We are given a binary tree, we need to check if tree is continuous or not
// https://www.geeksforgeeks.org/continuous-tree/

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(int n){

	node *temp=(node *)malloc(sizeof(node));
	temp->data=n;
	temp->left=NULL;
	temp->right=NULL;

	return temp;
}

bool continuousTree(node *root){

	if(root==NULL) return true;
	if(root->left==NULL and root->right==NULL) return true;
	if(root->left==NULL)
		return (abs(root->data-root->right->data)==1 and continuousTree(root->right));
	if(root->right==NULL)
		return (abs(root->data-root->left->data)==1 and continuousTree(root->left));
	return (abs(root->data-root->left->data)==1 and abs(root->data-root->right->data)==1 and continuousTree(root->left) and continuousTree(root->right));
} 

int main(){

	node *root=createNode(3);
	root->left=createNode(2);
	root->right=createNode(4);
	root->left->left=createNode(1);
	root->left->right=createNode(3);
	root->right->right=createNode(5);

	bool x=continuousTree(root);

	if(x) cout<<"Yes";
	else cout<<"No";

	return 0;
}