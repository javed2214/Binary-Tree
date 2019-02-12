// Convert All Leaf Nodes of Binary Tree into Doubly Linked List

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

void inOrder(node *root){
	if(root){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

node *leafToDLL(node *root, node **head){

	if(root==NULL) return NULL;
	if(root->left==NULL and root->right==NULL){
		root->right=*head;
		if(*head!=NULL)
			(*head)->left=root;
		*head=root;	
		return NULL;
	}
	root->right=leafToDLL(root->right,head);
	root->left=leafToDLL(root->left,head);

	return root;
}

void printList(node *head){
	cout<<"DLL Leaf: ";
	while(head){
		cout<<head->data<<"<->";
		head=head->right;
	}
}

int main(){

	node *root=NULL;
	node *head=NULL;
	int a[]={30,10,50,5,15,40,60};
	int n=sizeof(a)/sizeof(int);
	for(int i=0;i<n;i++)
		root=createTree(root,a[i]);
	root=leafToDLL(root,&head);

	printList(head);

	return 0;
}
