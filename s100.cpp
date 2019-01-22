// Tree Data Structure Implementation in C++
// Inorder, Preorder and Postorder Traversals

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(node*, int);
void inorderTraversal(node*);
void preorderTraversal(node*);
void postorderTraversal(node*);

int main(){

	node *root=NULL;

	int a[]={20,10,5,15,30,25,40};
	int n=sizeof(a)/sizeof(int);
	for(int i=0;i<n;i++)
		root=createNode(root,a[i]);
	cout<<"Inorder: ";
	inorderTraversal(root);
	cout<<"\nPreorder: ";
	preorderTraversal(root);
	cout<<"\nPostorder: ";
	postorderTraversal(root);
	
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

	return root;
}
void inorderTraversal(node *root){

	if(root==NULL)
		return;
	else{
		inorderTraversal(root->left);
		cout<<root->data<<" ";
		inorderTraversal(root->right);
	}
}
void preorderTraversal(node *root){

	if(root==NULL)
		return;
	else{
		cout<<root->data<<" ";
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}
void postorderTraversal(node *root){

	if(root==NULL)
		return;
	else{
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		cout<<root->data<<" ";
	}
}