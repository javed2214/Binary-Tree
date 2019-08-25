// Program to Find Level of A Node in a Binary Tree
// https://www.geeksforgeeks.org/get-level-of-a-node-in-a-binary-tree/

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(int x){

	node *temp = (node *)malloc(sizeof(node));
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

int findLevel(node *root, int x, int level){

	if(root == NULL) return 0;
	if(root->data == x) return level;
	int p = findLevel(root->left, x, level + 1);
	if(p != 0) return p;
	p = findLevel(root->right, x, level + 1);
	return p;
}

int main(){

	node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->left = createNode(6);
	root->right->right = createNode(7);
	root->right->right->right = createNode(8);

	int k;
	cin>>k;

	cout<<findLevel(root, k, 1);

	return 0;
}