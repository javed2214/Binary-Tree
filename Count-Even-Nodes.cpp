// Program to Count Number of Even Nodes in a Binary Tree

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

void inOrderTraversal(node *root){

	if(root){
		inOrderTraversal(root->left);
		cout<<root->data<<" ";
		inOrderTraversal(root->right);
	}
}

int countEvenNodes(node *root, int count){

	if(root){
		count = countEvenNodes(root->left, count) + countEvenNodes(root->right, count);
		if(root->data%2==0) count++;
	}
	return count;
}	
				
int main(){

	int a[]={20,10,30,5,15,25,35};
	int n=sizeof(a)/sizeof(int);

	node *root=NULL;

	for(int i=0;i<n;i++)
		root=createTree(root,a[i]);

	inOrderTraversal(root);
	cout<<"\n";

	int count=0;
	cout<<"No of Even Nodes: ";
	cout<<countEvenNodes(root,count);


	return 0;
}
