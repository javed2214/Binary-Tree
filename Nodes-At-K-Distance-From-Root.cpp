// Program to Find All the Nodes at K Distance from Root

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(int n){

	node *temp=new node;
	temp->data=n;
	temp->left=NULL;
	temp->right=NULL;

	return temp;
}

void nodesAtKDis(node *root, int k){

	if(root==NULL) return;
	if(k==0) cout<<root->data<<" ";
	nodesAtKDis(root->left,k-1);
	nodesAtKDis(root->right,k-1);
}

int main(){

	node *root=createNode(1);
	root->left=createNode(2);
	root->right=createNode(3);
	root->left->left=createNode(4);
	root->left->right=createNode(5);
	root->right->left=createNode(6);
	root->right->right=createNode(7);

	int k=2;
	nodesAtKDis(root,k);

	return 0;
}