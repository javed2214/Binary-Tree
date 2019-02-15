// Program to Convert Binary Tree into Doubly Linked List

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

void inOrder(node *root){
	if(root){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

void BTtoDLL(node *root, node **head){

	if(root==NULL) return;

	BTtoDLL(root->right,head);
	root->right=*head;

	if(*head!=NULL)
		(*head)->left=root;
	*head=root;

	BTtoDLL(root->left,head);
}

/*
void BTtoDLL(node *root, node **head){

	if(root==NULL) return;
	
	static node *prev=NULL;
	BTtoDLL(root->left,head);

	if(prev==NULL)
		*head=root;
	else{
		root->left=prev;
		prev->right=root;
	}
	prev=root;
	BTtoDLL(root->right,head);
}
*/

void printDLL(node *head){

	while(head!=NULL){
		cout<<head->data<<"<=>";
		head=head->right;
	}
	return;
}

int main(){

	int a[]={20,10,30,5,15,25,35};
	int n=sizeof(a)/sizeof(int);

	node *root=NULL;
	for(int i=0;i<n;i++)
		root=createTree(root,a[i]);

	cout<<"Inorder: ";
	inOrder(root);

	node *head=NULL;
	BTtoDLL(root,&head);

	cout<<"\nDLL: ";
	printDLL(head);

	return 0;
}