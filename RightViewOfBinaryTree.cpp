// Program to Print Right View of a Binary Tree

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
		root->left=createTree(root->left, n);
	else if(n>root->data)
		root->right=createTree(root->right, n);
}

void printTree(node *root){
	if(root){
		printTree(root->left);
		cout<<root->data<<" ";
		printTree(root->right);
	}
}	

void leftViewUtil(node *root, int level, int *maxLevel){

	if(root==NULL) return;

	if(*maxLevel<level){
		cout<<root->data<<" ";
		*maxLevel=level;
	}
	leftViewUtil(root->right,level+1,maxLevel);
	leftViewUtil(root->left,level+1,maxLevel);
}

void LeftView(node *root){

	int maxLevel=0;
	leftViewUtil(root,1,&maxLevel);
}

int main(){	
	int a[]={20,10,40,5,2,15,30,50,22,35,36,37};
	int n=sizeof(a)/sizeof(int);

	node *root=NULL;

	for(int i=0;i<n;i++)
		root=createTree(root,a[i]);

	printTree(root);
	cout<<"\n\nLeft View: \n";
	LeftView(root);

	return 0;
}


