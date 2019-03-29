// Program to Find Density of a Binary Tree
// Density = (Size / Height)

// Program to Find Sum pf Nodes at Maximum Depth
// https://www.geeksforgeeks.org/sum-of-nodes-at-maximum-depth-of-a-binary-tree-set-2/

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(int n){

	node *root=new node;
	root->data=n;
	root->left=NULL;
	root->right=NULL;
	
	return root;
}

int treeHeight(node *root){

	if(root==NULL) return 0;
	return 1+max(treeHeight(root->left), treeHeight(root->right));
}

int treeSize(node *root){

	if(root==NULL) return 0;
	return 1+treeSize(root->left)+treeSize(root->right);
}

float densityOfBT(node *root){

	float height=treeHeight(root);
	float size=treeSize(root);

	float density=(size/height);

	return density;
}

int main(){

	node *root=createNode(1);
	root->left=createNode(2);
	root->right=createNode(3);
	root->left->left=createNode(4);
	root->left->right=createNode(5);
	root->right->left=createNode(6);
	root->right->right=createNode(7);	

	cout<<densityOfBT(root);

	return 0;
}