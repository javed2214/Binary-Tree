// Program to Count Total Number of Half Nodes in a Bianry Tree
// A Half Node is a Node which Has Only One Child

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(int n){

	node *root=(node *)malloc(sizeof(node));
	root->data=n;
	root->left=NULL;
	root->right=NULL;

	return root;
}

int levelOrder(node *root){

	if(root==NULL) return 0;

	queue<node *> q;
	q.push(root);
	int count=0;

	while(!q.empty()){
		node *temp=q.front();
		q.pop();
		if((temp->left==NULL and temp->right!=NULL) or (temp->left!=NULL and temp->right==NULL))
			count++;
		if(temp->left) q.push(temp->left);	
		if(temp->right) q.push(temp->right);
	}
	return count;
}

int main(){

	node *root=createNode(10);
	root->left=createNode(20);
	root->right=createNode(30);
	root->left->left=createNode(40);
	root->left->right=createNode(50);
	root->right->left=createNode(60);
	root->right->right=createNode(70);

	cout<<levelOrder(root);

	return 0;
}