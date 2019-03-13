// Program to Find Max Node at Given Level
// https://www.geeksforgeeks.org/find-the-maximum-node-at-a-given-level-in-a-binary-tree/

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *newNode(int n){

	node *root=(node *)malloc(sizeof(node));
	root->data=n;
	root->left=NULL;
	root->right=NULL;

	return root;
}

int maxAtGivenLevel(node *root, int level){

	if(root==NULL) return 0;
	if(level==0) return root->data;
	int x=maxAtGivenLevel(root->left, level-1);
	int y=maxAtGivenLevel(root->right, level-1);

	return max(x,y);
}

int main(){

	node *root=NULL;
	root = newNode(45); 
    root->left = newNode(46); 
    root->left->left = newNode(18); 
    root->left->left->left = newNode(16); 
    root->left->left->right = newNode(23); 
    root->left->right = newNode(17); 
    root->left->right->left = newNode(24); 
    root->left->right->right = newNode(21); 
    root->right = newNode(15); 
    root->right->left = newNode(22); 
    root->right->left->left = newNode(37); 
    root->right->left->right = newNode(41); 
    root->right->right = newNode(19); 
    root->right->right->left = newNode(49); 
    root->right->right->right = newNode(29); 

    int level=3;

    cout<<maxAtGivenLevel(root, level);

    return 0;
}