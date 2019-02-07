// Program to Find Sum of Leaf Nodes

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(node *, int);
void inOrder(node *);
int sumOfLeaves(node *);

int main(){

	node *root=NULL;
	int a[]={20,10,5,15,30,25,40};		// Leaf Nodes: 5,15,25,40
	int n=sizeof(a)/sizeof(int);
	for(int i=0;i<n;i++)
		root=createNode(root,a[i]);
	inOrder(root);
	cout<<"\n";
	cout<<"Sum: "<<sumOfLeaves(root);

	return 0;
}
node *createNode(node *root, int n){

	if(root==NULL){
		node *root=new node;
		root->data=n;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	else if(n<root->data)
		root->left=createNode(root->left,n);
	else if(n>root->data)
		root->right=createNode(root->right,n);
}
void inOrder(node *root){

	if(root==NULL) return;
	else{
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}
int sumOfLeaves(node *root){

	if(root==NULL)
		return 0;
	if(root->left==NULL and root->right==NULL)
		return root->data;
	return sumOfLeaves(root->left)+sumOfLeaves(root->right);
}
