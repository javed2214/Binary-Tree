// Program to Construct Balanced Binary Search Tree from Sorted Array
// Recursive Approach
// Asked in Many Interviews

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *newNode(int n){
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=n;
	temp->left=NULL;
	temp->right=NULL;

	return temp;
}

node *sortedArrayToBST(int *a, int start, int end){

	if(start > end) return NULL;
	
	int mid=(start+end)/2;
	node *root=newNode(a[mid]);
	root->left=sortedArrayToBST(a,start,mid-1);
	root->right=sortedArrayToBST(a,mid+1,end);

	return root;
}

void preOrderTraversal(node *root){
	if(root){
		cout<<root->data<<" ";
		preOrderTraversal(root->left);
		preOrderTraversal(root->right);
	}
}

int main(){

	int a[]={1,2,3,4,5,6,7};
	int n=sizeof(a)/sizeof(int);

	node *root=NULL;

	root=sortedArrayToBST(a,0,n-1);
	preOrderTraversal(root);

	return 0;
}
