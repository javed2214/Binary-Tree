// Boundary Traversal of a Binary Tree
// Algorithm :-
// 1. Traverse Left Boundary
// 2. Traverse Leaf Nodes
// 3. Traverse Right Boundary

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

void leftBoundary(node *root){

	if(root){
		if(root->left){
			cout<<root->data<<" ";
			leftBoundary(root->left);
		}
		else if(root->right){
			cout<<root->data<<" ";
			leftBoundary(root->right);
		}
	}
}

void rightBoundary(node *root){

	if(root){
		if(root->right){
			cout<<root->data<<" ";
			rightBoundary(root->right);
		}
		else if(root->left){
			cout<<root->data<<" ";
			rightBoundary(root->right);
		}
	}
}

void leafNodes(node *root){

	if(root){
		leafNodes(root->left);
		if(root->left==NULL and root->right==NULL)
			cout<<root->data<<" ";
		leafNodes(root->right);
	}
}

void boundaryTraversal(node *root){

	leftBoundary(root);
    leafNodes(root);
    rightBoundary(root->right);
}

int main(){

	node *root=newNode(20);
	root->left = newNode(8); 
    root->left->left = newNode(4); 
    root->left->right = newNode(12); 
    root->left->right->left = newNode(10); 
    root->left->right->right = newNode(14); 
    root->right = newNode(22); 
    root->right->right = newNode(25); 

   	boundaryTraversal(root);

    return 0;
}