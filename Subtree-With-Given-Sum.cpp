// Subtree With Given Sum in a Binary Tree
// You are given a Binary Tree and a Sum. The task is to check if there exist a Subtree whose Sum of All Nodes is Equal to the Given Sum.
// The subtree corresponding to the root node is the entire tree; The subtree corresponding to any other node is called a proper subtree.

#include<bits/stdc++.h>
using namespace std;

typedef struct node{

	int data;
	struct node *left;
	struct node *right;
}node;

node *createTree(node *root, int n){

	if(root==NULL){
		root=(node *)malloc(sizeof(node));
		root->data=n;
		root->left=NULL;
		root->right=NULL;

		return root;
	}
	else if(root->data < n)
		root->left=createTree(root->left,n);
	else if(root->data > n)
		root->right=createTree(root->right,n);

	return root;
}

int checkSum(node *root){
	
	if(root==NULL) return 0;
	return root->data + checkSum(root->left) + checkSum(root->right);
}

bool subTreeSum(node *root, int sum){

	if(root==NULL) return false;
	if(checkSum(root)==sum) return true;
	return (subTreeSum(root->left,sum) or subTreeSum(root->right,sum));
}

int main(){

	int a[]={20,10,30,5,15,25,40,12,17};
	int n=sizeof(a)/sizeof(int);

	node *root=NULL;

	for(int i=0;i<n;i++)
		root=createTree(root,a[i]);

	int sum=44;

	if(subTreeSum(root,sum)) cout<<"Yes!";
	else cout<<"No!";

	return 0;
}