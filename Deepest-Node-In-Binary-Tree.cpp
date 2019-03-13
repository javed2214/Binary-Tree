// Program to Find the Deepest Node in a Binary Tree
// First find Height of the Tree and then Find the Node at that Height

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

int rootHeight(node *root){

	if(root==NULL) return 0;
	return 1+max(rootHeight(root->left),rootHeight(root->right));
}

void deepestNode(node *root, int level){

	if(root==NULL) return;
	if(level==0) cout<<root->data<<" ";
	deepestNode(root->left, level-1);
	deepestNode(root->right, level-1);
}

void deepestNodeUtil(node *root){

	int h=rootHeight(root);
	deepestNode(root,h-1);
}

int main(){

	node* root = createNode(1); 
    root->left = createNode(2); 
    root->right = createNode(3); 
    root->left->left = createNode(4); 
    root->right->left = createNode(5); 
    root->right->right = createNode(6); 
    root->right->left->right = createNode(7); 
    root->right->right->right = createNode(8); 
    root->right->left->right->left = createNode(9); 

    deepestNodeUtil(root);

	return 0;
}