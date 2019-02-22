// Program to Print All the Ancestors of a Node in a Binary Tree

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
bool printAncestors(node *root, int k){

	if(root==NULL) return false;

	if(root->data==k) return true;
	
	if(printAncestors(root->left,k) or printAncestors(root->right,k)){
		cout<<root->data<<" ";
		return true;
	}
	else return false;
}

int main(){

	node *root=NULL;
	int a[]={20,10,30,5,15,25,40,12,17};
	int n=sizeof(a)/sizeof(int);

	for(int i=0;i<n;i++)
		root=createTree(root,a[i]);
	
	int k=17;
	cout<<"Ancestors of "<<k<<": ";
	printAncestors(root,k);

	return 0;
}


