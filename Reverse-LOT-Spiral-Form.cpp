// Program to Print Reverse Level Order Traversal of Binary Tree in Spiral Form
// Recursive Approach

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
	else if(n < root->data)
		root->left=createTree(root->left,n);
	else if(n > root->data)
		root->right=createTree(root->right,n);

	return root;
}

int Height(node *root){

	if(root==NULL) return 0;
	return 1+max(Height(root->left),Height(root->right));
}

void reverseLOTSpiral(node *root, int level, int flag){

	if(root==NULL) return;
	
	if(level==0) cout<<root->data<<" ";
	
	if(flag){
		reverseLOTSpiral(root->left,level-1,flag);
		reverseLOTSpiral(root->right,level-1,flag);
	}
	else{
		reverseLOTSpiral(root->right,level-1,flag);
		reverseLOTSpiral(root->left,level-1,flag);
	}
}

void helperFunction(node *root){

	int h=Height(root);
	int flag=1;

	for(int i=h-1;i>=0;i--){
		reverseLOTSpiral(root,i,flag);
		flag=!flag;
	}
	return;
}

int main(){

	int a[]={30,20,50,10,25,40,60};
	int n=sizeof(a)/sizeof(int);
	int sum=35;

	node *root=NULL;
	for(int i=0;i<n;i++)
		root=createTree(root,a[i]);

	helperFunction(root);

	return 0;
}