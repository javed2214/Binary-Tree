// Level Order Traversal of a Binary Tree (Spiral Form)
// Recursive Approach
// https://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/

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
	else if(n<root->data)
		root->left=createTree(root->left,n);
	else if(n>root->data)
		root->right=createTree(root->right,n);
}

int height(node *root){

	if(root==NULL) return 0;
	return 1+max(height(root->left),height(root->right));
}

void printlevelOrderSpiral(node *root, int level, int temp){

	if(root==NULL) return;
	if(level==0) cout<<root->data<<" ";
	if(temp){
		printlevelOrderSpiral(root->left,level-1,temp);
		printlevelOrderSpiral(root->right,level-1,temp);
	}
	else{
		printlevelOrderSpiral(root->right,level-1,temp);
		printlevelOrderSpiral(root->left,level-1,temp);
	}
}

void levelOrder(node *root){

	int h=height(root);
	int temp=1;
	for(int i=0;i<h;i++){
		printlevelOrderSpiral(root,i,temp);
		temp=!temp;
	}
}

int main(){

	node *root=NULL;
	int a[]={20,10,30,5,15,25,40,12,17};
	int n=sizeof(a)/sizeof(int);

	for(int i=0;i<n;i++)
		root=createTree(root,a[i]);
	
	levelOrder(root);

	return 0;
}


