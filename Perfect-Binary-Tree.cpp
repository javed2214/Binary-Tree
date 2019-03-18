// Program to Find whether the Binary Tree is Perfect Binary Tree or Not
// In Perfect BT all Internal Nodes have two Children and all Leaves are at same Level
// https://www.geeksforgeeks.org/check-weather-given-binary-tree-perfect-not/

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

int height(node *root){

	if(root==NULL) return 0;
	return 1+max(height(root->left),height(root->right));
}

bool isPerfect(node *root, int h, int level){

	if(root==NULL) return true;
	if(root->left==NULL and root->right==NULL)
		return (h==level);
	if(root->left==NULL or root->right==NULL)
		return false;
	return isPerfect(root->left,h,level+1) and isPerfect(root->right,h,level+1);
}

void utilFunction(node *root){

	int h=height(root);
	bool x;
	x=isPerfect(root,h-1,0);

	if(x) cout<<"Perfect\n";
	else cout<<"Not Perfect\n";
}

int main(){

	node *root=createNode(1);
	root->left=createNode(2);
	root->right=createNode(3);
	root->left->left=createNode(4);
	root->left->right=createNode(5);
	root->right->left=createNode(6);
	root->right->right=createNode(7);

	utilFunction(root);

	return 0;
}