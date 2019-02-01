// Program to Convert Tree into Doubly Linked List
// Inorder Doubly Linked List

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createList(node *root, int n){

	if(root==NULL){
		root=(node *)malloc(sizeof(node));
		root->data=n;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	else if(n<root->data)
		root->left=createList(root->left,n);
	else
		root->right=createList(root->right,n);

	return root;
}

void treeToList(node *root, node *head){

	if(root==NULL)
		return;
	treeToList(root->left,head);
	static node *prev=NULL;
	if(prev==NULL)
		head=prev;
	else{
		prev->right=root;
		root->left=prev;
	}
	prev=root;
	treeToList(root->right,head);
}

void traverseTree(node *root){

	if(root){
		cout<<root->data<<" ";
		traverseTree(root->left);
		traverseTree(root->right);
	}
}

void traverseList(node *head){

	node *p=head;
	while(p){
		cout<<"<=["<<p->data<<"]=>";
		p=p->right;
	}
}

node *getHead(node *root){

	node *p=root;
	while(p->left!=NULL)
		p=p->left;
	return p;
}

int main(){

	node *root=NULL,*head=NULL;
	int a[]={30,20,10,25,50,60};
	int n=sizeof(a)/sizeof(int);
	for(int i=0;i<n;i++)
		root=createList(root,a[i]);
	head=getHead(root);
	traverseTree(root);
	cout<<"\n";
	treeToList(root,NULL);
	traverseList(head);

	return 0;
}