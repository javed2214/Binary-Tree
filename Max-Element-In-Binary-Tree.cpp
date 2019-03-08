// Program to Find Maximum Element in Binary Tree
// https://www.geeksforgeeks.org/find-maximum-or-minimum-in-binary-tree/

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

int maxElement(node *root){

	if(root==NULL) return INT_MIN;

	int res=root->data;
	int left=maxElement(root->left);
	int right=maxElement(root->right);

	if(left > res) res=left;
	if(right > res) res=right;

	return res;
}

node *createNode(int n){

	node *root=(node *)malloc(sizeof(node));
	root->data=n;
	root->left=NULL;
	root->right=NULL;

	return root;
}

int main(){

	node *root=createNode(20);
	root->left=createNode(10);
	root->right=createNode(30);

	cout<<maxElement(root);

	return 0;
}