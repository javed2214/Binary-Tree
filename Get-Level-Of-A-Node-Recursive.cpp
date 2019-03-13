// Program to Find Level of a Node Recursively

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *getnode(int n){

	node *root=(node *)malloc(sizeof(node));
	root->data=n;
	root->left=NULL;
	root->right=NULL;

	return root;
}

int rootHeight(node *root){

	if(root==NULL) return 0;
	return 1+max(rootHeight(root->left), rootHeight(root->right));
}

bool findLevel(node *root, int k, int level){

	if(root==NULL) return false;
	if(root->data==k and level==0) return true;
	return (findLevel(root->left,k,level-1) or findLevel(root->right,k,level-1));
}

int nodeLevelUtil(node *root, int k){

	int h=rootHeight(root);
	for(int i=0;i<h;i++){
		if(findLevel(root,k,i))
			return (i+1);
	}
	return -1;
}

int main(){

	node* root = getnode(20); 
    root->left = getnode(10); 
    root->right = getnode(30); 
    root->left->left = getnode(5); 
    root->left->right = getnode(15); 
    root->left->right->left = getnode(12); 
    root->right->left = getnode(25); 
    root->right->right = getnode(40); 

    int x=nodeLevelUtil(root,25);
	
	if(x==-1) cout<<"Node Not Found!";
	else cout<<"Level: "<<x;

	return 0;
}
