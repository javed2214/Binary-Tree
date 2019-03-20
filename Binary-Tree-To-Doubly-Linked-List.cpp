// Program to Convert Binary Tree into Doubly Linked List
// https://www.youtube.com/watch?v=FsxTX7-yhOw

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

node *head=NULL;	// Global Pointer
void convertIntoDLL(node *root){

	if(root==NULL) return;
	static node *prev=NULL;
	convertIntoDLL(root->left);
	if(prev==NULL) head=root;
	else{
		root->left=prev;
		prev->right=root;
	}
	prev=root;
	convertIntoDLL(root->right);
}

void printDLL(node *head){

	while(head!=NULL){
		cout<<head->data<<"<=>";
		head=head->right;
	}
}

int main(){

	node *root=createNode(1);
	root->left=createNode(2);
	root->right=createNode(3);
	root->left->left=createNode(4);
	root->left->right=createNode(5);
	root->right->left=createNode(6);
	root->right->right=createNode(7);

	convertIntoDLL(root);

	printDLL(head);
	cout<<"\n";

	return 0;
}