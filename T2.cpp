// Program to Find Sum of Non Leaf Nodes

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(node *, int);
void inOrder(node *);
int sumOfNonLeaves(node *);

int main(){

	node *root=NULL;
	int a[]={20,10,5,15,30,25,40};		// Non Leaf Nodes: 20,10,30
	int n=sizeof(a)/sizeof(int);
	for(int i=0;i<n;i++)
		root=createNode(root,a[i]);
	inOrder(root);
	cout<<"\n";
	cout<<"Sum: "<<sumOfNonLeaves(root);

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
int sumOfNonLeaves(node *root){

	if(root==NULL or root->left==NULL and root->right==NULL)
		return 0;
	return root->data+sumOfNonLeaves(root->left)+sumOfNonLeaves(root->right);
}