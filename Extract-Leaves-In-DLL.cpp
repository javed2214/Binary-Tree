// Extract Leaves of Binary Tree in a Doubly Linked List
// https://www.geeksforgeeks.org/connect-leaves-doubly-linked-list/

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

node *extractLeaves(node *root, node **head){

	if(root==NULL) return NULL;
	
	if(root->left==NULL and root->right==NULL){
		
		root->right=*head;
		if(*head!=NULL) (*head)->left=root;
		*head=root;

		return NULL;
	}
	
	root->right=extractLeaves(root->right,head);
	root->left=extractLeaves(root->left,head);

	return root;
}

void inOrder(node *root){

	if(root){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

void printDLL(node *head){

	while(head){
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

	cout<<"Tree Inorder: ";
	inOrder(root);
	cout<<"\n";
	node *head=NULL;
	root=extractLeaves(root,&head);

	cout<<"DLL Leaves: ";
	printDLL(head);

	cout<<"\nModified Tree: ";
	inOrder(root);

	return 0;
}