// Program to Find the Largest BST Subtree in a Given Binary Tree
// Time Complexity => O(n^2)
// Inefficient Method
// https://www.geeksforgeeks.org/find-the-largest-subtree-in-a-tree-that-is-also-a-bst/

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

int getNodes(node *root){

	if(root==NULL) return 0;
	return 1+getNodes(root->left)+getNodes(root->right);
}

bool isBST(node *root, int min, int max){

	if(root==NULL) return true;
	int x=root->data;
	if(x<min or x>max) return false;
	return (isBST(root->left,min,x) and isBST(root->right,x,max));
}

int sizeOfBST(node *root){

	if(root==NULL) return 0;
	return 1+sizeOfBST(root->left)+sizeOfBST(root->right);
}

int largestBSTSubtree(node *root){

	if(isBST(root,INT_MIN,INT_MAX)) return sizeOfBST(root);
	return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
}

int main(){

    node *root = createNode(50);  
    root->left = createNode(10);  
    root->right = createNode(60);  
    root->left->left = createNode(5);  
    root->left->right = createNode(20);  
    root->right->left = createNode(55);  
    root->right->left->left = createNode(45);  
    root->right->right = createNode(70);  
    root->right->right->left = createNode(65);  
    root->right->right->right = createNode(80);  

    cout<<largestBSTSubtree(root);

    return 0;
}
