// Program to Find Sum of All Left Leaves in a Given Binary Tree

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(node *, int);
void inOrder(node *);
int sumOfLeftLeaves(node *);
bool isLeaf(node *);

int main(){

	node *root=NULL;
	int a[]={20,10,5,15,30,25,40};		// Left Leaf Nodes: 5,25
	int n=sizeof(a)/sizeof(int);
	for(int i=0;i<n;i++)
		root=createNode(root,a[i]);
	inOrder(root);
	cout<<"\n";
	cout<<"Sum: "<<sumOfLeftLeaves(root);

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
bool isLeaf(node *root){

	if(root==NULL) return false;
	if(root->left==NULL and root->right==NULL) return true;
	return false;
}

int sumOfLeftLeaves(node *root){

	int sum=0;
	if(root!=NULL){
		if(isLeaf(root->left))
			sum+=root->left->data;

		sum+=sumOfLeftLeaves(root->left);
		sum+=sumOfLeftLeaves(root->right);
	}
	return sum;
}