// Program to Print All Ancestors of a Node in Binary Tree

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

int prinAncestors(node *root, int k){

	if(root){
		if(root->data==k)
			return 1;
		if(prinAncestors(root->left,k) or prinAncestors(root->right,k)){
			cout<<root->data<<" ";
			return 1;
		}
	}
	return 0;
}

int main(){

	node *root=NULL;
	int a[]={20,10,30,5,15,25,40,12,17};
	int n=sizeof(a)/sizeof(int);

	for(int i=0;i<n;i++)
		root=createTree(root,a[i]);
	
	int k;
	cout<<"Ancestors of which Node: ";
	cin>>k;
	prinAncestors(root,k);

	return 0;
}


