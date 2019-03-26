// Program to Find Level Order Successor of any Node in a Binary Tree

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *newNode(int n){

	node *root=(node *)malloc(sizeof(node));
	root->data=n;
	root->left=NULL;
	root->right=NULL;

	return root;
}

int LevelOrderSuccessor(node *root, int k){

	queue <node *> q;
	q.push(root);
	int flag=0;

	while(!q.empty()){
		int s=q.size();
		for(int i=0;i<s;i++){
			node *temp=q.front();
			q.pop();
			if(flag==1) return temp->data;
			if(temp->data==k) flag++;
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}
	}
	return -1;
}

int main(){

	node *root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->right=newNode(7);

	int k;
	cin>>k;
	cout<<LevelOrderSuccessor(root,k);

	return 0;
}